// Copyright KNJ


#include "Animation/DunAnimInstance.h"

#include "Character/DunCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utilities/Defines.h"
#include "Weapon/IDunWeapon.h"
#include "Weapon/DunWeaponBase.h"

UDunAnimInstance::UDunAnimInstance()
{
	MovingThreshould = 3.0f;
	JumpingThreshould = 100.0f;
}

void UDunAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner)
	{
		Movement = Owner->GetCharacterMovement();
	}
}

void UDunAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Movement)
	{
		Velocity = Movement->Velocity;
		GroundSpeed = Velocity.Size2D();
		bIsIdle = GroundSpeed < MovingThreshould;
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshould);
	}

	
	Owner = Cast<ADunCharacter>(GetOwningActor());
	CheckNull(Owner);
	IIDunWeapon* weapon = Cast<IIDunWeapon>(Owner);
	if (!!weapon)
	{
		if(!!weapon->GetWeapon())
			bEquipped = weapon->GetWeapon()->GetEquipped();
	}

}
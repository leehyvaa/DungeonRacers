// Copyright KNJ


#include "Weapon/DunWeaponMage.h"


#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"

ADunWeaponMage* ADunWeaponMage::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;

	return InWorld->SpawnActor<ADunWeaponMage>(params);
}

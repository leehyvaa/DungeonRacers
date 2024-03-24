// Copyright KNJ


#include "DunCharacter.h"

ADunCharacter::ADunCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->SetUsingAbsoluteRotation(true);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

void ADunCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADunCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADunCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


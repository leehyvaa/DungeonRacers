// Copyright KNJ


#include "Weapon/DunWeaponBase.h"

// Sets default values
ADunWeaponBase::ADunWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADunWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADunWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


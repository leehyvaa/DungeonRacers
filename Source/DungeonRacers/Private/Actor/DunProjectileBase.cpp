// Copyright KNJ


#include "Actor\DunProjectileBase.h"
#include "Components/SphereComponent.h"
//#include "Components/SProjectileMovementComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraComponentPoolMethodEnum.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "ProfilingDebugging/CountersTrace.h"
//#include "Subsystems/SActorPoolingSubsystem.h"

void ADunProjectileBase::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void ADunProjectileBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Sets default values
ADunProjectileBase::ADunProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADunProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADunProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADunProjectileBase::Explode_Implementation()
{
	
}

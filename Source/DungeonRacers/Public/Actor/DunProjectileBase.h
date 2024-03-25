// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DunProjectileBase.generated.h"

class USphereComponent;
class USProjectileMovementComponent;
class UNiagaraComponent;
class UAudioComponent;
class USoundCue;
class UCameraShakeBase;



USTRUCT(BlueprintType)
struct FProjectileSparseData
{
	GENERATED_BODY()

	FProjectileSparseData()
	: ImpactShakeInnerRadius(0.f),
	ImpactShakeOuterRadius(1500.f)
	{ }
	
	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	float ImpactShakeInnerRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	float ImpactShakeOuterRadius;
};



UCLASS(ABSTRACT, SparseClassDataTypes = ProjectileSparseData)
class DUNGEONRACERS_API ADunProjectileBase : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	TSubclassOf<UCameraShakeBase> ImpactShake;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TObjectPtr<UParticleSystem> ImpactVFX;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	TObjectPtr<USoundCue> ImpactSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> SphereComp;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	//TObjectPtr<USProjectileMovementComponent> MoveComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UNiagaraComponent> NiagaraLoopComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UAudioComponent> AudioComp;

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// BlueprintNativeEvent = C++ base implementation, can be expanded in Blueprints
	// BlueprintCallable to allow child classes to trigger explosions
	// Not required for assignment, useful for expanding in Blueprint later on
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	virtual void PostInitializeComponents() override;

	
public:	
	// Sets default values for this actor's properties
	ADunProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DunWeaponBase.generated.h"

UCLASS(Abstract)
class DUNGEONRACERS_API ADunWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ADunWeaponBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	FName HandSocket = "Hand_Weapon";
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	FName HolsterSocket = "Weapon_Socket";
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UAnimMontage* GrabMontage;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UAnimMontage* UngrabMontage;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon") 
	class UAnimMontage* AttackMontage;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UParticleSystem* FlashParticle;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UParticleSystem* EjectParticle;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	TSubclassOf<class ADunProjectileBase> ProjectileClass; 
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UParticleSystem* ImpactParticle;
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	class UMaterialInstanceConstant* DecalMaterial;

public:
	static ADunWeaponBase* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

	//FORCEINLINE bool GetEquipped() { return bEquipped; }
	//FORCEINLINE bool GetEquippping() { return bEquipping; }
	//FORCEINLINE bool GetAiming() { return bAiming; }

	// void Equip();
	// void Begin_Equip();
	// void End_Equip();
	//
	// void Unequip();
	// void Begin_Unequip();
	// void End_Unequip();

	//void Begin_Aiming();
	//void End_Aiming();

	void Begin_Fire();
	void Firing();
	void End_Fire();

private:
	class ACharacter* OwnerCharacter;
	//bool bEquipped;
	//bool bEquipping;
	//bool bAiming;
	bool bFiring;
};

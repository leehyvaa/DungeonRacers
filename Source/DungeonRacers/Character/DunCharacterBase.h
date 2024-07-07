// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "DunCharacterBase.generated.h"



UCLASS(Abstract)
class DUNGEONRACERS_API ADunCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ADunCharacterBase();

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
public:	
	//virtual void Tick(float DeltaTime) override;

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

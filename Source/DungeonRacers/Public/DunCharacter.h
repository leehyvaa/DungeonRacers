// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DunCharacter.generated.h"
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DUNGEONRACERS_API ADunCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADunCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Character/DunCharacterBase.h"
#include "DunCharacter.generated.h"

class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class UAnimMontage;
class USAttributeComponent;
class UParticleSystem;
class USActionComponent;


UCLASS()
class DUNGEONRACERS_API ADunCharacter : public ADunCharacterBase
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

private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputMappingContext* DefaultInputMapping;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* Input_Move;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* Input_LookMouse;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* Input_Jump;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* Input_Interact;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* Input_Sprint;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MouseLockAction;
	
	void Move(const FInputActionInstance& Instance);
	void LookMouse(const FInputActionValue& InputValue);
	void SprintStart();
	void SprintStop();
	void PrimaryInteract();

	
	void CursorTrace();
};

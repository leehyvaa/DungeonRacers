// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Character/DunCharacterBase.h"
#include "Weapon/IDunWeapon.h"
#include "DunCharacter.generated.h"

class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;
class UDunInteractionComponent;
class UAnimMontage;
class UDunAttributeComponent;
class UParticleSystem;
class UDunActionComponent;

UCLASS()
class DUNGEONRACERS_API ADunCharacter : public ADunCharacterBase, public IIDunWeapon
{
	GENERATED_BODY()

public:
	ADunCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UDunInteractionComponent> InteractionComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<ADunWeaponBase> Weapon;
	
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
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

	
public:
	virtual class ADunWeaponBase* GetWeapon() override { return Weapon; }
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) override;
	
};

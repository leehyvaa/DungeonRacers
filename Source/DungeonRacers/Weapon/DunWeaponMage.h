// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "Weapon/DunWeaponBase.h"
#include "DunWeaponMage.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONRACERS_API ADunWeaponMage : public ADunWeaponBase
{
	GENERATED_BODY()


public:
	static ADunWeaponMage* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

};

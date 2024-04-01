// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "Weapon/DunWeaponBase.h"
#include "DunWeaponWarrior.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONRACERS_API ADunWeaponWarrior : public ADunWeaponBase
{
	GENERATED_BODY()
public:
	static ADunWeaponWarrior* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

};

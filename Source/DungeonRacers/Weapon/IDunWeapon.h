// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDunWeapon.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIDunWeapon : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DUNGEONRACERS_API IIDunWeapon
{
	GENERATED_BODY()

public:
	virtual class ADunWeaponBase* GetWeapon() = 0;
	virtual void GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection) = 0;
	//virtual void OnFocus() = 0;
	//virtual void OffFocus() = 0;
	
};

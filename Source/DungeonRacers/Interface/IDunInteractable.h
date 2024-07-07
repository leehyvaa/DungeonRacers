// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDunInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIDunInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DUNGEONRACERS_API IIDunInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnActorLoaded();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FText GetInteractText(APawn* InstigatorPawn);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);
};

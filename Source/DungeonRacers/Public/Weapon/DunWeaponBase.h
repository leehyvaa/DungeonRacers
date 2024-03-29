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
	// Sets default values for this actor's properties
	ADunWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Copyright KNJ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/IDunInteractable.h"
#include "DunItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class DUNGEONRACERS_API ADunItemChest : public AActor, public IIDunInteractable
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

	virtual void OnActorLoaded_Implementation() override;

protected:

	UPROPERTY(ReplicatedUsing="OnRep_LidOpened", BlueprintReadOnly, SaveGame) // RepNotify
	bool bLidOpened;

	UFUNCTION()
	void OnRep_LidOpened();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> LidMesh;

public:	
	// Sets default values for this actor's properties
	ADunItemChest();

};

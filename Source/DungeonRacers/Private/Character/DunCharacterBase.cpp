// Copyright KNJ


#include "Character/DunCharacterBase.h"
#include "Global.h"

ADunCharacterBase::ADunCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//플레이어 본인에만 충돌 안되게


	
	
	// template<typename T> static void CreateActorComponent(AActor* inActor, 
	// 	T** inComponent, FName inName, USceneComponent* inParent = NULL)
	// {
	// 	*inComponent = inActor->CreateDefaultSubobject<T>(inName);
	// }
}






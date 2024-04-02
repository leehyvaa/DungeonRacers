// Copyright KNJ


#include "Weapon/DunWeaponBase.h"
//#include "Global.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Animation/AnimMontage.h"
#include "Engine/StaticMeshActor.h"
#include "particles/ParticleSystem.h"
#include "Materials/MaterialInstanceConstant.h"



#include "Actor/DunProjectileBase.h"
#include "Weapon/IDunWeapon.h"
#include "Character/DunCharacterBase.h"

// Sets default values
ADunWeaponBase::ADunWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bEquipped = false;
	// DunHelpers::CreateComponent<USkeletalMeshComponent>(this, &Mesh, "Mesh");
	// USkeletalMesh* mesh;
	// CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'");
	// Mesh->SetSkeletalMesh(mesh);
	//
	// CHelpers::GetAsset<UAnimMontage>(&GrabMontage, "AnimMontage'/Game/Character/Montages/Rifle_Grab_Montage.Rifle_Grab_Montage'");
	// CHelpers::GetAsset<UAnimMontage>(&UngrabMontage, "AnimMontage'/Game/Character/Montages/Rifle_Ungrab_Montage.Rifle_Ungrab_Montage'");
	// CHelpers::GetAsset<UAnimMontage>(&AttackMontage, "AnimMontage'/Game/Character/Montages/Rifle_Fire_Montage.Rifle_Fire_Montage'");
	// CHelpers::GetAsset<UParticleSystem>(&FlashParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Muzzleflash.VFX_Muzzleflash'");
	// CHelpers::GetAsset<UParticleSystem>(&EjectParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Eject_bullet.VFX_Eject_bullet'");
	// CHelpers::GetClass<ADunProjectileBase>(&ProjectileClass, "Blueprint'/Game/BP_CBullet.BP_CBullet_C'");
	// CHelpers::GetAsset<UParticleSystem>(&ImpactParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Impact_Default.VFX_Impact_Default'");
	// CHelpers::GetAsset<UMaterialInstanceConstant>(&DecalMaterial,"MaterialInstanceConstant'/Game/Materials/M_Decal_Inst.M_Decal_Inst'");
}

// Called when the game starts or when spawned
void ADunWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), 
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket
	);
	
}


void ADunWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	////CheckFalse(bAiming);

	IIDunWeapon* rifle = Cast<IIDunWeapon>(OwnerCharacter);
	////CheckNull(rifle);

	FVector start, end, direction;
	rifle->GetLocationAndDirection(start, end, direction);

	//ź���� ��ο�
	//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 10.f);

	

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;

	if (GetWorld()->LineTraceSingleByChannel(hitResult,start,end,ECollisionChannel::ECC_WorldDynamic,params))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!staticMeshActor)
		{
			UStaticMeshComponent* meshComponent = 
				Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
			if (!!meshComponent)
			{
				if (meshComponent->BodyInstance.bSimulatePhysics)
				{
					////rifle->OnFocus();
					return;
				}
			} // << : meshComponent
		} // << : staticMeshActor
	} // << : if
	////rifle->OffFocus();

}



//
// void ADunWeaponBase::Begin_Fire()
// {
// 	// CheckFalse(bEquipped);
// 	// CheckTrue(bEquipping);
// 	// CheckFalse(bAiming);
// 	// CheckTrue(bFiring);
//
// 	Firing();
//
// }
//
// void ADunWeaponBase::Firing()
// {
// 	IIDunWeapon* rifle = Cast<IIDunWeapon>(OwnerCharacter);
// 	CheckNull(rifle);
//
// 	FVector start, end, direction;
// 	rifle->GetLocationAndDirection(start, end, direction);
//
// 	//ź���� ��ο�
// 	//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 10.f);
//
// 	OwnerCharacter->PlayAnimMontage(AttackMontage);
// 	UGameplayStatics::SpawnEmitterAttached(FlashParticle, Mesh, "MuzzleFlash", FVector::ZeroVector, FRotator::ZeroRotator,
// 		EAttachLocation::KeepRelativeOffset);
//
// 	UGameplayStatics::SpawnEmitterAttached(EjectParticle, Mesh, "EjectBullet", FVector::ZeroVector, FRotator::ZeroRotator,
// 		EAttachLocation::KeepRelativeOffset);
//
// 	FVector muzzleLocation = Mesh->GetSocketLocation("MuzzleFlash");//�Ž� ���̷����� �����̸��� �˻��ؼ� �ش� ��ġ�� ������
// 	if (!!ProjectileClass)
// 		GetWorld()->SpawnActor<ADunProjectileBase>(ProjectileClass, muzzleLocation, direction.Rotation());
//
//
// 	FCollisionQueryParams params;
// 	params.AddIgnoredActor(this);
// 	params.AddIgnoredActor(OwnerCharacter);
//
// 	FHitResult hitResult;
//
// 	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_Visibility, params))
// 	{
// 		FRotator rotator = hitResult.ImpactNormal.Rotation();//�Ѿ� ��ݽ� �Ի簢�ε� �ݴ�� ������ �ݻ簢
//
// 		//������ ��ġ�� ��ƼŬ�� �������� �����ϴµ� ���
// 		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, hitResult.Location, rotator);
//
// 		//�Ѿ� �����ڱ� ����
// 		UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMaterial, FVector(5),
// 			hitResult.Location, rotator,10.0f);
// 	}
//
// 	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECollisionChannel::ECC_WorldDynamic, params))
// 	{
// 		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
// 		if (!!staticMeshActor)
// 		{
// 			UStaticMeshComponent* meshComponent =
// 				Cast<UStaticMeshComponent>(staticMeshActor->GetRootComponent());
// 			if (!!meshComponent)
// 			{
// 				if (meshComponent->BodyInstance.bSimulatePhysics)
// 				{
// 					direction = staticMeshActor->GetActorLocation() - OwnerCharacter->GetActorLocation();
// 					direction.Normalize();
//
// 					meshComponent->AddImpulseAtLocation(direction * meshComponent->GetMass() * 100,
// 						OwnerCharacter->GetActorLocation());
//
//
// 					return;
// 				}
// 			} // << : meshComponent
// 		} // << : staticMeshActor
// 	} // << : if
// 	//rifle->OffFocus();
// }
//
// void ADunWeaponBase::End_Fire()
// {
// }
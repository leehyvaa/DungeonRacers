// Copyright KNJ


#include "Character/DunCharacter.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/DunInteractionComponent.h"
#include "Components/CapsuleComponent.h"
#include "Logging/StructuredLog.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Weapon/DunWeaponMage.h"
#include "Weapon/DunWeaponWarrior.h"

ADunCharacter::ADunCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->TargetArmLength = 400.0f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->SetUsingAbsoluteRotation(true);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	//CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	//GetCharacterMovement()->bConstrainToPlane = true; 캐릭터이동을 평면에 제한
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	InteractionComp = CreateDefaultSubobject<UDunInteractionComponent>("InteractionComp");

	TSubclassOf<UAnimInstance> animInstance;
	DunHelpers::GetClass<UAnimInstance>(&animInstance, "AnimBlueprint'/Game/Blueprints/Character/ABP_PlayerCharacter.ABP_PlayerCharacter_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

}

void ADunCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerWeapon = ADunWeaponMage::Spawn(GetWorld(), this);
}

void ADunCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADunCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	const APlayerController* PC = GetController<APlayerController>();
	const ULocalPlayer* LP = PC->GetLocalPlayer();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	Subsystem->ClearAllMappings();
	
	// Add mappings for our game, more complex games may have multiple Contexts that are added/removed at runtime
	Subsystem->AddMappingContext(DefaultInputMapping, 0);
	
	// New Enhanced Input system
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	// General
	InputComp->BindAction(Input_Move, ETriggerEvent::Triggered, this, &ADunCharacter::Move);
	InputComp->BindAction(Input_Jump, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	InputComp->BindAction(Input_Interact, ETriggerEvent::Triggered, this, &ADunCharacter::PrimaryInteract);
	
	// Sprint while key is held
	InputComp->BindAction(Input_Sprint, ETriggerEvent::Started, this, &ADunCharacter::SprintStart);
	InputComp->BindAction(Input_Sprint, ETriggerEvent::Completed, this, &ADunCharacter::SprintStop);
	
	// MKB
	InputComp->BindAction(Input_LookMouse, ETriggerEvent::Triggered, this, &ADunCharacter::LookMouse);
	
}

void ADunCharacter::Move(const FInputActionInstance& Instance)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	// Get value from input (combined value from WASD keys or single Gamepad stick) and convert to Vector (x,y)
	const FVector2D AxisValue = Instance.GetValue().Get<FVector2D>();

	// Move forward/back
	AddMovementInput(ControlRot.Vector(), AxisValue.Y);

	// Move Right/Left strafe
	const FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, AxisValue.X);
}

void ADunCharacter::LookMouse(const FInputActionValue& InputValue)
{
	const FVector2D Value = InputValue.Get<FVector2D>();
	
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void ADunCharacter::SprintStart()
{
}

void ADunCharacter::SprintStop()
{
}

void ADunCharacter::PrimaryInteract()
{
	InteractionComp->PrimaryInteract();
}


void ADunCharacter::CursorTrace()
{
}

void ADunCharacter::GetLocationAndDirection(FVector& OutStart, FVector& OutEnd, FVector& OutDirection)
{
	OutDirection = CameraComp->GetForwardVector();
	FTransform transform = CameraComp->GetComponentToWorld();
	FVector cameraLocation = transform.GetLocation();
	OutStart = cameraLocation + OutDirection;
	FVector conDirection = UKismetMathLibrary::RandomUnitVectorInEllipticalConeInDegrees(OutDirection, 0.2f, 0.3f);
	conDirection *= 3000.0f;
	OutEnd = cameraLocation + conDirection;
}
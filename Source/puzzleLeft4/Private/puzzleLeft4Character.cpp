// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "puzzleLeft4.h"
#include "puzzleLeft4Character.h"
#include "puzzleLeft4Projectile.h"
#include "Animation/AnimInstance.h"

//////////////////////////
// ApuzzleLeft4Character//
//////////////////////////

ApuzzleLeft4Character::ApuzzleLeft4Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//RifleGun = new URifleWeaponComponent();

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->RelativeLocation = FVector(0.f, 0.f, -150.f);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ApuzzleLeft4Character::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//InputComponent->BindAction("Reload", IE_Pressed, this, &ApuzzleLeft4Character::Reload);

	//Fire Projectile
	//InputComponent->BindAction("Fire", IE_Pressed, this, &ApuzzleLeft4Character::OnFireP);

	//Fire Line Trace/Ray Cast
	InputComponent->BindAction("Fire", IE_Pressed, this, &ApuzzleLeft4Character::OnFireT);

	//Horizontal & Vertical Movement
	InputComponent->BindAxis("MoveForward", this, &ApuzzleLeft4Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ApuzzleLeft4Character::MoveRight);

	//Mouse OR anything that provides an absolute delta
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//Controller OR anything with a analog joystick
	InputComponent->BindAxis("TurnRate", this, &ApuzzleLeft4Character::TurnAtRate);
	InputComponent->BindAxis("LookUpRate", this, &ApuzzleLeft4Character::LookUpAtRate);

	RifleGun = Cast<URifleWeaponComponent>(this->GetComponentByClass(URifleWeaponComponent::StaticClass()));
	RifleGun->MainCameraComponent = FirstPersonCameraComponent;
}

void ApuzzleLeft4Character::OnFireP()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			// spawn the projectile at the muzzle
			World->SpawnActor<ApuzzleLeft4Projectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void ApuzzleLeft4Character::OnFireT()
{
	FCollisionQueryParams QueryParams; // General Raycast

	if (RifleGun->UpdateAmmo())
	{
		RifleGun->FireWeapon();

		AddControllerPitchInput(-RifleGun->Recoil * GetWorld()->GetDeltaSeconds());
	}
	else
	{
		RifleGun->Reload();
	}
}

void ApuzzleLeft4Character::OnDeath()
{
	//Destroy Pawn Here
	//OR whatever needs to be done upon the death of the Player
	//On 2nd thought this probably should be put into the HealthComponent
	//Maybe just make the current healthcomponent into  a base class
	//Then make separate Player & Enemy HealthComponents to cater to each of their needs
}

void ApuzzleLeft4Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value/2);
	}
}

void ApuzzleLeft4Character::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value/2);
	}
}

void ApuzzleLeft4Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ApuzzleLeft4Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

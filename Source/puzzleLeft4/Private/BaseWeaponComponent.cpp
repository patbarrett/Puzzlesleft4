// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "BaseWeaponComponent.h"


// Sets default values for this component's properties
UBaseWeaponComponent::UBaseWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseWeaponComponent::InitializeComponent()
{
	Super::InitializeComponent();

	// ...
	
}


// Called every frame
void UBaseWeaponComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

/*
if (GetWorld()->LineTraceSingle(
HitResult,
FirstPersonCameraComponent->GetComponentLocation(),
FirstPersonCameraComponent->GetComponentLocation() + FirstPersonCameraComponent->GetForwardVector() * 800,
QueryParams,
ObjectQueryParams))
{
*/

bool UBaseWeaponComponent::CastRay(UCameraComponent* MainCam)
{
	FCollisionQueryParams QueryParams; // General Raycast
	//QueryParams.TraceTag = MyTraceTag;
	QueryParams.AddIgnoredActor(this->GetOwner());

	FCollisionObjectQueryParams ObjectQueryParams; // Collision Parameters
	ObjectQueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

	//GetWorld()->DebugDrawTraceTag = MyTraceTag;

	if (GetWorld()->LineTraceSingle(
		HitTarget,
		MainCam->GetComponentLocation(),
		MainCam->GetComponentLocation() + MainCam->GetForwardVector() * WeaponRange,
		QueryParams,
		ObjectQueryParams))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool UBaseWeaponComponent::UpdateAmmo()
{
	if (CurrentAmmo - AmmoCost >= 0)
	{
		CurrentAmmo -= AmmoCost;
		return true;
	}
	else
	{
		return false;
	}
}

void UBaseWeaponComponent::Reload()
{
	if (CurrentReserveAmmo > MaxCurrent && CurrentAmmo != MaxCurrent)
	{
		CurrentReserveAmmo -= MaxCurrent - CurrentAmmo;
		CurrentAmmo = MaxCurrent;
		//Play Reload Sound
	}
	else if (CurrentReserveAmmo <= MaxCurrent && CurrentAmmo != MaxCurrent)
	{
		CurrentAmmo = CurrentReserveAmmo;
		CurrentReserveAmmo = 0;
		//Play Reload Sound
	}
	else
	{
		//Play Cannot Reload Sound
	}
}

void UBaseWeaponComponent::UpdateIsShootable()
{
	if (!isShootable)
	{
		if (TimePassed >= FireRate)
		{
			isShootable = true;
			TimePassed = 0.0f;
		}
		else
		{
			TimePassed += World->GetDeltaSeconds();
		}
	}
}
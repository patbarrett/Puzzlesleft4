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

bool UBaseWeaponComponent::CastRay(FVector Origin, FVector Direction)
{
	FCollisionQueryParams QueryParams; // General Raycast
	//QueryParams.TraceTag = MyTraceTag;
	QueryParams.AddIgnoredActor(this->GetOwner());

	FCollisionObjectQueryParams ObjectQueryParams; // Collision Parameters
	ObjectQueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

	//GetWorld()->DebugDrawTraceTag = MyTraceTag;

	if (GetWorld()->LineTraceSingle(
		Target,
		Origin,
		Origin + Direction * WeaponRange,
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


// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;

	

	// ...
}


// Called when the game starts
void UHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();
	
	// ...
	
}

// Called every frame
void UHealthComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UHealthComponent::InflictDamage(float Damage)
{
	//Health = Damage;
	//Health = 0.0f;
	if (Health - Damage > 0)
	{
		Health -= Damage;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("This is Dead"));
	}
}


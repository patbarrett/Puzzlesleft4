// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "BaseHealthComponent.h"


// Sets default values for this component's properties
UBaseHealthComponent::UBaseHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;



	// ...
}


// Called when the game starts
void UBaseHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();

	// ...

	ThisMesh = Cast<USkeletalMeshComponent>(this->GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
}

// Called every frame
void UBaseHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UBaseHealthComponent::InflictDamage(float Damage, FVector Direction, float Value)
{
	if (Health - Damage > 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Player Was Damaged"));
		Health -= Damage;
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Player Was Damaged"));
		OnDeath(Direction, Value);
		return false;
	}
}

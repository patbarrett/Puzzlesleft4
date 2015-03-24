// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "PlayerHealthComponent.h"

UPlayerHealthComponent::UPlayerHealthComponent()
{

}

void UPlayerHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();
	ParentObj = this->GetOwner();
	ParentCapsule = Cast<UCapsuleComponent>(ParentObj->GetComponentByClass(UCapsuleComponent::StaticClass()));
}

void UPlayerHealthComponent::OnDeath(FVector ForceDirection, float ForceValue)
{

}



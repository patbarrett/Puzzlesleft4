// Fill out your copyright notice in the Description page of Project Settings.

#include "puzzleLeft4.h"
#include "EnemyHealthComponent.h"

UEnemyHealthComponent::UEnemyHealthComponent()
{
	
}

void UEnemyHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();
	ParentObj = this->GetOwner();
	ParentCapsule = Cast<UCapsuleComponent>(ParentObj->GetComponentByClass(UCapsuleComponent::StaticClass()));
}

void UEnemyHealthComponent::OnDeath(FVector ForceDirection, float ForceValue)
{
	ParentObj->SetLifeSpan(1.0f);
	ParentCapsule->SetSimulatePhysics(true);
	//ParentCapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//ParentCapsule->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	//ParentCapsule->SetPhysicsLinearVelocity(ForceDirection * ForceValue);
}
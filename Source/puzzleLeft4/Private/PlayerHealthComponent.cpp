#include "puzzleLeft4.h"
#include "PlayerHealthComponent.h"

UPlayerHealthComponent::UPlayerHealthComponent()
{

}

void UPlayerHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UPlayerHealthComponent::OnDeath(FVector ForceDirection, float ForceValue)
{

	UE_LOG(LogTemp, Display, TEXT("Player Was Killed"));
	Die = true;
	/*this->GetOwner()->SetLifeSpan(0.01f);
	ThisMesh->SetSimulatePhysics(true);
	ThisMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ThisMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	ThisMesh->SetPhysicsLinearVelocity(ForceDirection * ForceValue);*/
}
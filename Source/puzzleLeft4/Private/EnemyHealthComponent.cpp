#include "puzzleLeft4.h"
#include "EnemyHealthComponent.h"

UEnemyHealthComponent::UEnemyHealthComponent()
{

}

void UEnemyHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UEnemyHealthComponent::OnDeath(FVector ForceDirection, float ForceValue)
{
	if (this->GetOwner()->GetComponentByClass(UCapsuleComponent::StaticClass()))
	{
		this->GetOwner()->SetLifeSpan(1.0f);
		this->GetOwner()->GetComponentByClass(UCapsuleComponent::StaticClass())->DestroyComponent(false);
	}

	ThisMesh->SetSimulatePhysics(true);
	ThisMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ThisMesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	ThisMesh->SetPhysicsLinearVelocity(ForceDirection * ForceValue);

	//ParentObj->SetLifeSpan(1.0f);
	//ParentCapsule->SetSimulatePhysics(true);
	//ParentCapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//ParentCapsule->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	//ParentCapsule->SetPhysicsLinearVelocity(ForceDirection * ForceValue);
}
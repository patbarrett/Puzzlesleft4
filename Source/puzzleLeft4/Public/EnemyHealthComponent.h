#include "HealthComponent.h"
#include "EnemyHealthComponent.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLELEFT4_API UEnemyHealthComponent : public UHealthComponent
{
	GENERATED_BODY()

public:
	UEnemyHealthComponent();
	virtual void InitializeComponent() override;
	virtual void OnDeath(FVector ForceDirection, float ForceValue) override;

};


// Fill out your copyright notice in the Description page of Project Settings.

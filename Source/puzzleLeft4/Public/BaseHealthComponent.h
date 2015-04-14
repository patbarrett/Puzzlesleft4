// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BaseHealthComponent.generated.h"


UCLASS(ClassGroup = (Custom))
class PUZZLELEFT4_API UBaseHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseHealthComponent();

	// Called when the game starts
	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool Die;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float Health;
	
	USkeletalMeshComponent* ThisMesh;

	UFUNCTION(BlueprintCallable, Category = "DealHealthDamage")
	bool InflictDamage(float Damage, FVector Direction, float Value);

	virtual void OnDeath(FVector ForceDirection, float ForceValue) PURE_VIRTUAL(UBaseHealthComponent OnDeath, );
};
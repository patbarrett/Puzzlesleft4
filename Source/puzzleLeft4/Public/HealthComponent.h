// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom))
class PUZZLELEFT4_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	AActor* ParentObj;
	UCapsuleComponent* ParentCapsule;

	float Health;

	void Init();

	UFUNCTION(BlueprintCallable, Category = "DealHealthDamage")
	bool InflictDamage(FVector ForceDirection, float ForceValue, float Damage);

	virtual void OnDeath(FVector ForceDirection,float ForceValue)PURE_VIRTUAL(UHealthComponent OnDeath,);
	//virtual void FireWeapon() PURE_VIRTUAL(UBaseWeaponComponent FireWeapon, );

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom),meta=(BlueprintSpawnableComponent))
class TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 35;

public:
	void Rotate(float RelativeSpeed);
	
	
};

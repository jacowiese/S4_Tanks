// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max for per track, in Newtons (force = mass * acceleration)
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; 
	
};

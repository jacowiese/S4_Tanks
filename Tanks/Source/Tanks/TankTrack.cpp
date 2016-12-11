// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	// TODO: Clamp actual throttle value to player can't over-drive
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *GetName(), Throttle)

	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


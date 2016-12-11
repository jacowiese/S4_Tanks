// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (LeftTrack != nullptr && RightTrack != nullptr) {
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendTurnRight(float Throw) {
	if (LeftTrack != nullptr && RightTrack != nullptr) {
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-Throw);
	}
}

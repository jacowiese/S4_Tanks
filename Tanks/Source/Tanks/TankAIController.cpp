// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank * aiTank = GetControlledTank();
	if (aiTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessed tank: %s."), *aiTank->GetName())
	}
}


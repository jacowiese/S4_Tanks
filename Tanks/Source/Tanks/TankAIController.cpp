// Fill out your copyright notice in the Description page of Project Settings.

#include "Tanks.h"
#include "TankPlayerController.h"
#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const {
	APawn *playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return (playerPawn) ? Cast<ATank>(playerPawn) : nullptr;
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank *aiTank = GetControlledTank();
	if (aiTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessed tank: %s."), *aiTank->GetName())
	}

	ATank *playerTank = GetPlayerTank();
	if (playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI knows the player tank is: %s."), *playerTank->GetName())
	}
}


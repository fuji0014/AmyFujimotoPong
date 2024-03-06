// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Board/Goal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere)
	int GameScorePlayer = 0;

	UPROPERTY(EditAnywhere)
	int GameScoreAI = 0;

	UPROPERTY(EditAnywhere)
	int GameWinScore = 5;

	UFUNCTION()
	void UpdateScore(EGoalType GoalType);

	UFUNCTION()
	void PrintScore();

	UFUNCTION()
	void ResetScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};

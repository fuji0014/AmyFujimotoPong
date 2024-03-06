// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameState.h"

void APongGameState::UpdateScore(EGoalType GoalType)
{
	if (GoalType == EGoalType::RightGoal)
	{
		if (GameScorePlayer < GameWinScore-1)
		{
			GameScorePlayer++;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PLAYER SCORED!");
			PrintScore();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "YOU WIN!!! Game restarting...");
			ResetScore();
		}
			
	}
	else
	{
		if (GameScoreAI < GameWinScore-1)
		{
			GameScoreAI++;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "AI SCORED!");
			PrintScore();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "YOU LOST!!! Game restarting...");
			ResetScore();
		}
			
	}
}

void APongGameState::PrintScore()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Current score is %d : %d"), GameScorePlayer, GameScoreAI));
}

void APongGameState::ResetScore()
{
	GameScoreAI = 0;
	GameScorePlayer = 0;
	PrintScore();
}

void APongGameState::BeginPlay()
{
	Super::BeginPlay();
}

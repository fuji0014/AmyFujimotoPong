// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerPaddle.h"
#include "../Ball/Ball.h"
#include "AIPaddle.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API AAIPaddle : public APlayerPaddle
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIPaddle();

	class ABall* Ball;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

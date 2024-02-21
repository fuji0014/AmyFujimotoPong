// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallSpawner.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API ABallSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawner();

	UPROPERTY(EditAnywhere, Category = "Class to Spawn")
	TSubclassOf<class ABall> BallBlueprint;

	void SpawnBall();

	UPROPERTY(Transient)
	class ABall* BallObject;

	UPROPERTY(Transient)
	bool bIsBallObjectActive = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBallDestroyed(AActor* DestroyedActor);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

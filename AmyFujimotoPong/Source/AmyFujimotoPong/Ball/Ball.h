// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API ABall : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class USphereComponent* CollisionSphere;
	
	UPROPERTY(VisibleAnywhere, Category = "Ball")
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class UArrowComponent* SpawnDirection;

public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(EditAnywhere, Category = "Class to Spawn")
	TSubclassOf<class ABall> BallBlueprint;
	
	void SpawnBall();

	class ABall* BallObject;

	UPROPERTY(BlueprintReadOnly)
	FVector InitialBallLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

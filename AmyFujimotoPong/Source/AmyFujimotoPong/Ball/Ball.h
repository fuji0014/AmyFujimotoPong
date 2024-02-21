// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API ABall : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Ball")
	class UArrowComponent* SpawnDirection;

	void DefaultProjectileMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

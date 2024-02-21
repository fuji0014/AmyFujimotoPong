// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardBorder.generated.h"

UCLASS()
class AMYFUJIMOTOPONG_API ABoardBorder : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Actor Components")
	class USceneComponent* ActorRootComponent;

	UPROPERTY(EditAnywhere, Category = "Actor Components")
	class UStaticMeshComponent* ActorMesh;
	
public:	
	// Sets default values for this actor's properties
	ABoardBorder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

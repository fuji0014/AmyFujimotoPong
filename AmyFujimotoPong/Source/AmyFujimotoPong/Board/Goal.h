// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

UENUM(BlueprintType)
enum class EGoalType :uint8 {
	LeftGoal = 0,
	RightGoal = 1
};

UCLASS()
class AMYFUJIMOTOPONG_API AGoal : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Goal")
	class UBoxComponent* BoxComponent;
	
public:	
	// Sets default values for this actor's properties
	AGoal();

	UPROPERTY(EditAnywhere, Category = "Goal")
	EGoalType GoalPosition;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

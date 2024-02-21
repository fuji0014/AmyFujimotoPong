// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawner.h"
#include "Ball.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABallSpawner::ABallSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABallSpawner::SpawnBall()
{
	if (!IsValid(BallObject))
	{
		if (bIsBallObjectActive == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("bIsBallObjectActive false"));
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			BallObject = GetWorld()->SpawnActor<ABall>(BallBlueprint, GetActorLocation(), GetActorRotation(), SpawnParams);

			if (BallObject)
			{
				BallObject->OnDestroyed.AddDynamic(this, &ABallSpawner::OnBallDestroyed);
				bIsBallObjectActive = true;
				UE_LOG(LogTemp, Warning, TEXT("bIsBallObjectActive true"));
			}
		}
	}
}

void ABallSpawner::OnBallDestroyed(AActor* DestroyedActor)
{
	UE_LOG(LogTemp, Warning, TEXT("bIsBallObjectActive back to false"));
	bIsBallObjectActive = false;
	DestroyedActor->OnDestroyed.RemoveAll(this);
}

// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpawnBall();
}


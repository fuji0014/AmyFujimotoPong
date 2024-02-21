// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPaddle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAIPaddle::AAIPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AAIPaddle::BeginPlay()
{
	Super::BeginPlay();
	Ball = Cast<ABall>(UGameplayStatics::GetActorOfClass(GetWorld(), ABall::StaticClass()));
}

// Called every frame
void AAIPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Ball != NULL)
	{
		FVector BallLocation = Ball->GetActorLocation();
		FVector TargetLocation = GetActorLocation();
		TargetLocation.Z = Ball->GetActorLocation().Z;
		FVector NewLocation = FMath::Lerp(GetActorLocation(), TargetLocation, 0.01f);
		SetActorLocation(NewLocation);
	}
}

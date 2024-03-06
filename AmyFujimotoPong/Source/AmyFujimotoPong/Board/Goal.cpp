// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "../Ball/Ball.h"
#include "Components/BoxComponent.h"
#include "../PongGameState.h"


// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnCollisionBoxBeginOverlap);	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoal::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) {	//Ball
		if (ABall* Ball = Cast<ABall>(OtherActor)) {
			Ball->Destroy();
			APongGameState* GS = Cast<APongGameState>(GetWorld()->GetGameState());

			if (GoalPosition == EGoalType::LeftGoal) {
				if (GS)
					GS->UpdateScore(EGoalType::LeftGoal);
			}
			else {
				if (GS)
					GS->UpdateScore(EGoalType::RightGoal);
			}

		}
		/*
			if(OtherAction->IsA<ABall>()) - alternate solution
		*/
	}	
}
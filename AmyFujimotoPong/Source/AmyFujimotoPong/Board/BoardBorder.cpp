// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardBorder.h"

// Sets default values
ABoardBorder::ABoardBorder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorRootComponent = CreateDefaultSubobject<USceneComponent>("Actor Root");
	SetRootComponent(ActorRootComponent);

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Actor Mesh");
	ActorMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABoardBorder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoardBorder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


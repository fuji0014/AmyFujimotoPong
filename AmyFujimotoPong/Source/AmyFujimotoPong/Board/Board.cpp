// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABoard::ABoard()
{
 	PrimaryActorTick.bCanEverTick = true;

	ActorRootComponent = CreateDefaultSubobject<USceneComponent>("Actor Root");
	SetRootComponent(ActorRootComponent);

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Actor Mesh");
	ActorMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm->SetupAttachment(RootComponent);
	MainCamera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	//PC->SetViewTargetWithBlend(this, 3.f, EViewTargetBlendFunction::VTBlend_Cubic);
	PC->SetViewTarget(this);	//for camera to now gradually zoom in
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "Engine/StaticMeshActor.h"

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	VisualMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualMeshRoot"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	BoxComponent->SetSimulatePhysics(true);
	BoxComponent->SetEnableGravity(false);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	BoxComponent->SetCollisionProfileName("Pawn");	//blockalldynamic
	//BoxComponent->SetBoxExtent(FVector(70, 32, 127));
	BoxComponent->SetLinearDamping(10);	//to limit the amount of bouncing

	SetRootComponent(BoxComponent);
	VisualMeshRoot->SetupAttachment(RootComponent);
	VisualMesh->SetupAttachment(VisualMeshRoot);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisualMesh->SetCollisionProfileName(TEXT("IgnoreAll"));

	//BoxComponent->GetBodyInstance()->bLockXRotation = true;
	BoxComponent->GetBodyInstance()->bLockXRotation = true;
	BoxComponent->GetBodyInstance()->bLockYRotation = true;
	BoxComponent->GetBodyInstance()->bLockZRotation = true;
	BoxComponent->GetBodyInstance()->bLockXTranslation = true;
	BoxComponent->GetBodyInstance()->bLockYTranslation = true;
	//BoxComponent->GetBodyInstance()->bLockZTranslation = true;
}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &APlayerPaddle::OnHitActor);
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Controller)
	{
		FVector Direction(0);
		if (MoveUpAmount != 0)
		{
			Direction = GetActorLocation() + (GetActorUpVector() * MoveUpAmount);
			SetActorLocation(Direction);
		}
	}

}

void APlayerPaddle::MoveUp(float Amount)
{
	MoveUpAmount = Amount;
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent != NULL)
	{
		PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);

	}
}

void APlayerPaddle::OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	/*
	if (OtherActor) {
		if (AStaticMeshActor* BoardBorder = Cast<AStaticMeshActor>(OtherActor)) {
			UStaticMeshComponent* MeshComp = BoardBorder->GetComponentByClass<UStaticMeshComponent>();
		}
	}
	*/

	if (OtherActor)
	{
		FString Message = FString("OnHitActor: ") + OtherActor->GetName();
		PrintMessageOnScreen(Message);
	}
}

void APlayerPaddle::PrintMessageOnScreen(FString Message)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Red, Message);
	}
}
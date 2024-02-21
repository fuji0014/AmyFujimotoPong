// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	//CollisionSphere->SetEnableGravity(false);
	//CollisionSphere->SetSimulatePhysics(true);
	CollisionSphere->SetCollisionProfileName("BlockAllDynamic");
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SetRootComponent(CollisionSphere);
	VisualMesh->SetupAttachment(RootComponent);
	SetActorEnableCollision(true);

	//CollisionSphere->GetBodyInstance()->bLockXRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockYRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockZRotation = true;
	CollisionSphere->GetBodyInstance()->bLockXTranslation = true;
	//CollisionSphere->GetBodyInstance()->bLockYTranslation = true;
	//CollisionSphere->GetBodyInstance()->bLockZTranslation = true;

	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.f;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1;
	ProjectileMovement->Friction = 0.f;

	SpawnDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnDirection"));
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	SpawnBall();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::SpawnBall()
{
	if (!IsValid(BallObject))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		UWorld* World = GetWorld();
		//GetInstigator();
		BallObject = World->SpawnActor<ABall>(BallBlueprint, GetActorLocation(), GetActorRotation(), SpawnParams);
	}

}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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
	CollisionSphere->SetCollisionProfileName("Pawn");
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetRootComponent(CollisionSphere);

	VisualMesh->SetupAttachment(RootComponent);
	SetActorEnableCollision(true);

	SpawnDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnDirection"));
	SpawnDirection->SetupAttachment(RootComponent);
		
	//CollisionSphere->GetBodyInstance()->bLockXRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockYRotation = true;
	//CollisionSphere->GetBodyInstance()->bLockZRotation = true;
	CollisionSphere->GetBodyInstance()->bLockXTranslation = true;
	//CollisionSphere->GetBodyInstance()->bLockYTranslation = true;
	//CollisionSphere->GetBodyInstance()->bLockZTranslation = true;

	DefaultProjectileMovement();
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{	
	Super::BeginPlay();
	SetActorRotation(SpawnDirection->GetRelativeRotation());
	FVector ArrowDirection = GetActorForwardVector();
	ProjectileMovement->Velocity = ArrowDirection * ProjectileMovement->InitialSpeed;

	UE_LOG(LogTemp, Warning, TEXT("Spawn Rotation: %s"), *SpawnDirection->GetRelativeRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Ball Rotation: %s"), *GetActorRotation().ToString());
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::DefaultProjectileMovement()
{
	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->InitialSpeed = 100.f;
	ProjectileMovement->MaxSpeed = 200.f;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.2;
	ProjectileMovement->Friction = 0.f;
}
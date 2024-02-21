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
	CollisionSphere->SetCollisionProfileName("BlockAllDynamic");
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

	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.f;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1;
	ProjectileMovement->Friction = 0.f;

	InitialBallLocation = GetActorLocation();
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
	//SpawnDirection->SetWorldRotation(GetActorRotation());
	BallObject = Cast<ABall>(UGameplayStatics::GetActorOfClass(GetWorld(), ABall::StaticClass()));
	SpawnBall();
}

void ABall::SpawnBall()
{
	if (BallObject == NULL)
	{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Red, "SPAWNING");
		}
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		UWorld* World = GetWorld();
		//GetInstigator();
		BallObject = World->SpawnActor<ABall>(BallBlueprint, InitialBallLocation, SpawnDirection->GetRelativeRotation(), SpawnParams);
		UE_LOG(LogTemp, Warning, TEXT("Ball Rotation: %s"), *GetActorRotation().ToString());
	}
	
}
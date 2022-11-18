// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyVehicle.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemyVehicle::AEnemyVehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Vehicle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vehicle"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/FennecStaticMesh/Fennec_Fennec.Fennec_Fennec'"));
	Vehicle->SetStaticMesh(MeshAsset.Object);

	Health = 50;
}

// Called when the game starts or when spawned
void AEnemyVehicle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Raycast();
}

void AEnemyVehicle::Raycast() 
{
	FHitResult OutHit;

	FVector Start = Vehicle->GetComponentLocation();
	// (position you are going to - start position).normalized
	FVector ForwardVector =  -Start;
	ForwardVector.Normalize();

	FVector End = Start + (ForwardVector * 5000.f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this->GetOwner());
	// draw raycast debug line
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
}


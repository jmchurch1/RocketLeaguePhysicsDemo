// Fill out your copyright notice in the Description page of Project Settings.


#include "Explosion.h"

// Sets default values
AExplosion::AExplosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Explosion"));
	if (Sphere)
	{
		SetRootComponent(Sphere);
	}
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/Explosion/Sphere.Sphere'"));
	ConstructorHelpers::FObjectFinder<UMaterial>SphereMaterial(TEXT("Material'/Game/Explosion/m_sphere.m_sphere'"));
	Sphere->SetStaticMesh(MeshAsset.Object);
	Sphere->SetMaterial(0, SphereMaterial.Object);

	currentMultiplier = 1.0;
}

// Called when the game starts or when spawned
void AExplosion::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentMultiplier += DeltaTime * Speed;

	FString TheFloatStr = FString::SanitizeFloat(currentMultiplier);
	GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr);

	if (currentMultiplier > MaximumSize) {
		Destroy();
	}

	Sphere->SetWorldScale3D(Sphere->GetRelativeScale3D() * currentMultiplier);
}


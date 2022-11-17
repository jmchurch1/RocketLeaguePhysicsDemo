// Fill out your copyright notice in the Description page of Project Settings.


#include "Goon.h"

// Sets default values
AGoon::AGoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Goon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Goon"));
	if (Goon)
	{
		SetRootComponent(Goon);
	}
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshAsset(TEXT("SkeletalMesh'/Game/SCK_Casual01/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	Goon->SetSkeletalMesh(MeshAsset.Object);
	ConstructorHelpers::FObjectFinder<UPhysicsAsset>PhysicsAsset(TEXT("PhysicsAsset'/Game/SCK_Casual01/Mannequin/Character/Mesh/SK_Mannequin_PhysicsAsset.SK_Mannequin_PhysicsAsset'"));
	Goon->SetPhysicsAsset(PhysicsAsset.Object);
	// makes it so collision can occur
	Goon->SetNotifyRigidBodyCollision(true);
	// makes it so overlap can occur
	Goon->SetGenerateOverlapEvents(true);
	// problem?
	Goon->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Goon->SetCollisionObjectType(ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void AGoon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


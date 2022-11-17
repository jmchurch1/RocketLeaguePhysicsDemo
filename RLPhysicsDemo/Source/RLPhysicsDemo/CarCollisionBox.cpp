// Fill out your copyright notice in the Description page of Project Settings.


#include "CarCollisionBox.h"

// Sets default values
ACarCollisionBox::ACarCollisionBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);

}

// Called when the game starts or when spawned
void ACarCollisionBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarCollisionBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


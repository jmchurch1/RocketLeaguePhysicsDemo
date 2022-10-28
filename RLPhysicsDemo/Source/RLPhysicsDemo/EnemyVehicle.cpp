// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyVehicle.h"

// Sets default values
AEnemyVehicle::AEnemyVehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Vehicle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vehicle"));

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

}


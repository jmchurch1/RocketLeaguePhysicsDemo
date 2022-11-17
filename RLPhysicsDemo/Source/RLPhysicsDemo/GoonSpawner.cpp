// Fill out your copyright notice in the Description page of Project Settings.


#include "GoonSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Goon.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)

// Sets default values
AGoonSpawner::AGoonSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGoonSpawner::BeginPlay()
{
	Super::BeginPlay();
	// start up the timer
	GetWorldTimerManager().SetTimer(TimerHandler, this, &AGoonSpawner::TimerFunction, 1, true, 0);
}


void AGoonSpawner::TimerFunction() {
	// https://www.youtube.com/watch?v=PMg24GMjRvM&ab_channel=DevEnabled
	// track the remaining time
	TimeRemaining--;

	// inline if else call
	if (TimeRemaining == 0)
	{
		FVector randPosition = FVector(FMath::RandRange(StartSpawningPosition, EndSpawningPosition), FMath::RandRange(StartSpawningPosition, EndSpawningPosition), 2);
		FActorSpawnParameters SpawnParams;
		AGoon* spawnedGoon = (AGoon*)GetWorld()->SpawnActor<AGoon>(AGoon::StaticClass(), randPosition, FRotator(0,0,0), SpawnParams);
		TimeRemaining = SpawnTimeRemaining;
		PrintString(FString::Printf(TEXT("Spawned Goon")));
	}
}




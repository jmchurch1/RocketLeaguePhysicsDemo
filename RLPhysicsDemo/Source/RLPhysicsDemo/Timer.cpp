// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer.h"
#include "Kismet/GameplayStatics.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)
// Sets default values
ATimer::ATimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();
	
	// start up the timer
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATimer::TimerFunction, 1, true, 0);
}


void ATimer::TimerFunction() {
	// https://www.youtube.com/watch?v=PMg24GMjRvM&ab_channel=DevEnabled
	// track the remaining time
	TimeRemaining--;

	// inline if else call
	TimeRemaining == 0 ? PrintString("Finished Looping"), UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName(), false)) : PrintString("Decreasing Time!");

	PrintString(FString::Printf(TEXT("Seconds Remaining: %d"), TimeRemaining));
}

void ATimer::IncrementTimeRemaining(int time)
{
	TimeRemaining += time;
	TimeRemaining > MaxTime ? TimeRemaining = MaxTime : TimeRemaining = TimeRemaining; 
}
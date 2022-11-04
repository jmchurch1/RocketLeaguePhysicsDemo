// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoonSpawner.generated.h"

UCLASS()
class RLPHYSICSDEMO_API AGoonSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoonSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int TimeRemaining = 3;

public:	
	void TimerFunction();

	FTimerHandle TimerHandler;
};

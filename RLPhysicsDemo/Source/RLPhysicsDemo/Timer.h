// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Timer.generated.h"

UCLASS()
class RLPHYSICSDEMO_API ATimer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Timer")
	int32 TimeRemaining = 20;

public:	
	void TimerFunction();

	void IncrementTimeRemaining(int time);

	FTimerHandle TimerHandle;
};

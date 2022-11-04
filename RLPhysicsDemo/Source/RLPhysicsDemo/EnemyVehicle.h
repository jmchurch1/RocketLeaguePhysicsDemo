// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyVehicle.generated.h"

UCLASS()
class RLPHYSICSDEMO_API AEnemyVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Raycast();

	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		UStaticMeshComponent* Vehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		UActorComponent* PlayerReference;
};

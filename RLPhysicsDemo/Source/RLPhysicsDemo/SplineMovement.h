// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/TimelineComponent.h"
#include "SplineMovement.generated.h"

UCLASS()
class RLPHYSICSDEMO_API ASplineMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		USplineComponent* SplineComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spline")
		UStaticMeshComponent* Vehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		float Speed;
	
	float Alpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		UTimelineComponent* Timeline;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
		UStaticMeshComponent* getEnemyVehicle();

	UFUNCTION(BlueprintCallable, Category = "Enemy")
		void decrementHealth(float damage);
};

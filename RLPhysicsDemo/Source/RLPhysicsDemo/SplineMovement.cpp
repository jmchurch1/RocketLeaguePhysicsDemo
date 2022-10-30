// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineMovement.h"

// Sets default values
ASplineMovement::ASplineMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Track"));
	if (SplineComponent)
	{
		SetRootComponent(SplineComponent);
	}

	Vehicle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vehicle"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/FennecStaticMesh/Fennec_Fennec.Fennec_Fennec'"));
	Vehicle->SetStaticMesh(MeshAsset.Object);
}

// Called when the game starts or when spawned
void ASplineMovement::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASplineMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float trackLength = SplineComponent->GetSplineLength();

	Alpha += DeltaTime * Speed;
	if (Alpha > 1)
		Alpha -= 1;

	// debug text: https://forums.unrealengine.com/t/convert-float-to-fstring-c/275580
	float currentDistance = FMath::Lerp(0.0, trackLength, Alpha);
	
	Vehicle->SetRelativeLocationAndRotation(
		SplineComponent->GetLocationAtDistanceAlongSpline(currentDistance, ESplineCoordinateSpace::Local),
		SplineComponent->GetRotationAtDistanceAlongSpline(currentDistance, ESplineCoordinateSpace::Local),
		false, false
		);
}
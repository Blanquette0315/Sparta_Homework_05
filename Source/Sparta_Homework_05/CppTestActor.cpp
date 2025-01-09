// Fill out your copyright notice in the Description page of Project Settings.


#include "CppTestActor.h"

// Sets default values
ACppTestActor::ACppTestActor()
	: CurPos{ 0 , 0 }
	, EventCnt(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppTestActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Origin Pos : (%f, %f)"), CurPos.X, CurPos.Y);

	FVector2d PrevPos = CurPos;
	float FinalDistance = 0.f;
	for (int i = 0; i < 10; ++i)
	{
		RandomMove();
		UE_LOG(LogTemp, Warning, TEXT("Changed Pos : (%f, %f)"), CurPos.X, CurPos.Y);
		float Distance = CalDistance(PrevPos, CurPos);
		UE_LOG(LogTemp, Warning, TEXT("Distance : %f"), Distance);
		CreateEvent();
		PrevPos = CurPos;
		FinalDistance += Distance;
	}

	UE_LOG(LogTemp, Warning, TEXT("Final Distance : %f"), FinalDistance);
	UE_LOG(LogTemp, Warning, TEXT("EventCallCnt : %d"), EventCnt);
}

// Called every frame
void ACppTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Moves CurPos in a random direction.
void ACppTestActor::RandomMove()
{
	CurPos.X += FMath::RandRange(0, 1);
	CurPos.Y += FMath::RandRange(0, 1);
	
	return;
}

float ACppTestActor::CalDistance(const FVector2d First, const FVector2d Second)
{
	return sqrt(pow(Second.X - First.X, 2) + pow(Second.Y - First.Y, 2));
}

void ACppTestActor::CreateEvent()
{
	if (FMath::RandBool())
	{
		UE_LOG(LogTemp, Warning, TEXT("!! An event has occurred !!"));
		EventCnt += 1;
	}

}
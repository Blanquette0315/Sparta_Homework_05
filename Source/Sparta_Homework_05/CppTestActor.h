// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppTestActor.generated.h"

UCLASS()
class SPARTA_HOMEWORK_05_API ACppTestActor : public AActor
{
	GENERATED_BODY()
	
	FVector2d CurPos;
	int32 EventCnt;

public:
	// Sets default values for this actor's properties
	ACppTestActor();

	// Moves CurPos in a random direction.
	void RandomMove();

	float CalDistance(const FVector2d First, const FVector2d Second);

	void CreateEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

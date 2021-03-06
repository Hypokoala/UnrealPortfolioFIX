// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FlockingAgentBase.generated.h"

UCLASS()
class UNREALPORTFOLIOPRJCT_API AFlockingAgentBase : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float AvoidanceRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
		float AlignmentWeight;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
		float CohesionWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weights")
		float AvoidanceWeight;

	TArray<AActor*> Actors;
	float avoidRadiusSquared;
	FVector lastMove;

	// Sets default values for this character's properties
	AFlockingAgentBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 

	void GetCommonData();

	void Move(FVector movement);

	// Behavior.
	FVector CombinedBehavior();
	FVector AlignmentBehavior();
	FVector CohesionBehavior();
	FVector AvoidanceBehavior();
};

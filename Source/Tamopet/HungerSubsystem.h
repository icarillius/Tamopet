 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HungerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TAMOPET_API UHungerSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
protected:
	//outputs tick, and overrides so works for world sub system
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

public:
	//hunger var on start
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int hunger = 100;

	//decrease hunger function
	UFUNCTION(BlueprintCallable)
	int DecreaseHunger();
	//increase hunger function
	UFUNCTION(BlueprintCallable)
	int IncreaseHunger();
	//lose function
	UFUNCTION(BlueprintCallable)
	int LoseHunger();

};

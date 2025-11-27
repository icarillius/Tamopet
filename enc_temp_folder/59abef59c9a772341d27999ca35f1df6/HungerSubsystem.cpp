// Fill out your copyright notice in the Description page of Project Settings.


#include "HungerSubsystem.h"

void UHungerSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick by subsystem"));
	//runs decrease hunger function
	DecreaseHunger();
}

TStatId UHungerSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UHungerSubsystem, STATGROUP_Tickables);
}

int UHungerSubsystem::DecreaseHunger()
{
	// on 0 lose via hunger function.
	if (hunger == 0)
	{
		LoseHunger();
	}
	//while between 1-100 lose 1 hunger per delta tick
	if (hunger > 0 && hunger < 101)
	{
		hunger = hunger - 1;
	}

	//output log
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Hunger: %i"), hunger));

	return hunger;

}

int UHungerSubsystem::IncreaseHunger()
{
	// if under 81 then add 20 to score NEEDS TO BE REFACTORED create incriment var and use this instead?
	if (hunger < 81) {
		hunger = hunger + 20;
	}
	// output for increase of hunger
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT(" Increase Hunger: %i"), hunger));

	return hunger;
}

int UHungerSubsystem::LoseHunger()
{
	//lose game function.should really end the subsystem at this point right???
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT(" You Lose ")));

	return 0;
}

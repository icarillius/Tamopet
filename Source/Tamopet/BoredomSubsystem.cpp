// Fill out your copyright notice in the Description page of Project Settings.


#include "BoredomSubsystem.h"

void UBoredomSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick by subsystem"));
	//runs decrease hunger function
	DecreaseBoredom();
}

TStatId UBoredomSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UBoredomSubsystem, STATGROUP_Tickables);
}

int UBoredomSubsystem::DecreaseBoredom()
{
	// on 0 lose via hunger function.
	if (boredom == 0)
	{
		LoseBoredom();
	}
	//while between 1-100 lose 1 hunger per delta tick
	if (boredom > 0 && boredom < 101)
	{
		boredom = boredom - 1;
	}

	//output log
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Hunger: %i"), boredom));

	return boredom;

}

int UBoredomSubsystem::IncreaseBoredom()
{
	// if under 81 then add 20 to score NEEDS TO BE REFACTORED create incriment var and use this instead?
	if (boredom < 81) {
		boredom = boredom + 20;
	}
	// output for increase of boredom
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT(" Increase Hunger: %i"), boredom));

	return boredom;
}

int UBoredomSubsystem::LoseBoredom()
{
	//lose game function.should really end the subsystem at this point right???
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT(" You Lose ")));

	return 0;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/AIControllers/AIC_EnemyTurret.h"

#include "Enemy/BP_Enemy.h"

void AAIC_EnemyTurret::FireProjectile(const FVector& TargetLocation) const
{
	UObject* target = this->GetPawn();
	if (Cast<ABP_Enemy>(target))
	{
		UFunction* eventToTrigger = target->FindFunction("FireProjectile");	//find event on blueprint
		
		//create parameters for calling event with targetLocation input
		struct projectileParameters { FVector targetLocation; };
		projectileParameters params;
		params.targetLocation = TargetLocation;
		
		if (IsValid(eventToTrigger))
		{
			target->ProcessEvent(eventToTrigger, &params);	//call event if it exsits
		}
		else UE_LOG(LogTemp, Display, TEXT("AIC_EnemyTurret -> eventToTrigger not valid"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("AIC_EnemyTurret -> failed cast"));
	}
}

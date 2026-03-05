// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task/BTTaskDebug_Print.h"


EBTNodeResult::Type UBTTaskDebug_Print::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Message);
	return OutputState ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;	//return succeeded if (desired) output state is true
}

UBTTaskDebug_Print::UBTTaskDebug_Print()
{
	NodeName = "DEBUG: Print";
}

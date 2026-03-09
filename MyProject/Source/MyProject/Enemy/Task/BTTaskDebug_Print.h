// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTaskDebug_Print.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTaskDebug_Print : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	explicit UBTTaskDebug_Print();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
		FString Message = "Default";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
		bool OutputState = true;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Kismet/KismetSystemLibrary.h"

#include "BTTask_CheckLOS.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTTask_CheckLOS : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	explicit UBTTask_CheckLOS();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	FVector OriginOffset = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS")
	float TraceLength = 100.0f, TraceRadius = 30;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="LOS-Debug")
	float DrawTime;
};

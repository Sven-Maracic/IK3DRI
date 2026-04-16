// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/ValueOrBBKey.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Enemy/AIC_Base.h"
#include "BTService_LookAt.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBTService_LookAt : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
public:
	UBTService_LookAt();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Attack")
	FValueOrBBKey_Vector TargetLocation = FVector::ZeroVector;
	
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Debug")
	bool IsDebug = false;
	
protected:
	AAIC_Base* enemy;
};

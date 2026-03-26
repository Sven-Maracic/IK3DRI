// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KismetTraceUtils.h"
#include "Kismet/GameplayStatics.h"
#include "BFL_ConeCheck.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBFL_ConeCheck : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
	static bool ConeTraceMulti(const UObject* WorldContextObject, const FVector Start, const FRotator Direction, float ConeHeight, float ConeHalfAngle, ECollisionChannel CollisionChannel, AActor* ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult>& OutHits, FLinearColor TraceColor = FLinearColor::Red, FLinearColor TraceHitColor = FLinearColor::Green, float DrawTime = 5.0f);
};

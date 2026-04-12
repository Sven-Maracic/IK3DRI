// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Service/BTService_CheckLOS.h"

#include "AIController.h"
#include "KismetTraceUtils.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTService_CheckLOS::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	enemyOwner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	startPos = enemyOwner->GetActorLocation() + OriginOffset.GetValue(OwnerComp);
	traceLength = TraceLength.GetValue(OwnerComp);
}

void UBTService_CheckLOS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UpdateObjects(OwnerComp);	
	
	FVector playerLocation = playerPawn->GetActorLocation();
	FVector targetVector = playerLocation - startPos;
	
	if (IsValid(playerPawn))
	{
		if (targetVector.Length() <= traceLength)
		{
			float dotProd = FVector::DotProduct(enemyOwner->GetActorForwardVector(), targetVector.GetSafeNormal());
			float angleBetween = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(dotProd, -1.0f, 1.0f)));
			if (angleBetween <= LosAngle.GetValue(OwnerComp))
			{
				FHitResult hitResult;
				if (GetWorld()->LineTraceSingleByChannel(hitResult, startPos, playerLocation, ECC_Visibility))
				{
					if (IsDebug)
					{
						UE_LOG(LogTemp, Display, TEXT("%f"), angleBetween);
						
						DrawDebugLineTraceSingle(GetWorld(), startPos, playerLocation, EDrawDebugTrace::ForOneFrame, true, hitResult, FLinearColor::Green, FLinearColor::Red, DrawTime);
					
						UE_LOG(LogTemp, Log, TEXT("%s hit!"), *hitResult.Component->GetName());
					}
					if (hitResult.GetActor() == playerPawn)
					{
						OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationOutput.SelectedKeyName, playerPawn->GetActorLocation());
						OwnerComp.GetBlackboardComponent()->SetValueAsBool(PlayerDetectedOutput.SelectedKeyName, true);
					}
				}
			}
		}
		else if (IsDebug)
		{
			FHitResult temp;
			DrawDebugLine(GetWorld(), startPos, startPos +  (enemyOwner->GetActorForwardVector()*traceLength).RotateAngleAxis(LosAngle, FVector(0,0,1)), FColor::Red, false, -1, 0, 1.0f);
			DrawDebugLine(GetWorld(), startPos, startPos +  (enemyOwner->GetActorForwardVector()*traceLength).RotateAngleAxis(-LosAngle, FVector(0,0,1)), FColor::Red, false, -1, 0, 1.0f);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BTService_CheckLOS -> Player Pawn Not Found"));
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

UBTService_CheckLOS::UBTService_CheckLOS()
{
	NodeName = TEXT("BTService_CheckLOS -> Check line of sight for player");
}

void UBTService_CheckLOS::InitializeFromAsset(UBehaviorTree& Asset)
{
	if (const UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		LocationOutput.ResolveSelectedKey(*BBAsset);
		PlayerDetectedOutput.ResolveSelectedKey(*BBAsset);
	}
	Super::InitializeFromAsset(Asset);
}
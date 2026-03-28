// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Service/BTService_CheckLOS.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Libraries/BFL_ConeCheck.h"

void UBTService_CheckLOS::UpdateObjects(const UBehaviorTreeComponent& OwnerComp)
{
	EnemyOwner = Cast<ABP_Enemy>(OwnerComp.GetAIOwner()->GetPawn());
	StartPos = EnemyOwner->GetActorLocation() + OriginOffset;
	Direction = EnemyOwner->GetActorForwardVector().Rotation();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	TraceLength = TraceLengthKey.GetValue(OwnerComp);
}

void UBTService_CheckLOS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UpdateObjects(OwnerComp);	
	
	FVector playerLocation = PlayerPawn->GetActorLocation();
	FVector targetVector = playerLocation - StartPos;
	
	if (targetVector.Length() <= TraceLength)
	{
		FHitResult hitResult;
		float dotProd = FVector::DotProduct(EnemyOwner->GetActorForwardVector(), targetVector.GetSafeNormal());
		float angleBetween = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(dotProd, -1.0f, 1.0f)));
		if (angleBetween <= 30.0f)
		{
			if (GetWorld()->LineTraceSingleByChannel(hitResult, StartPos, playerLocation, ECC_Visibility))
			{
				if (IsDebug) UE_LOG(LogTemp, Display, TEXT("%f"), angleBetween);
				if (IsDebug) DrawDebugLineTraceSingle(GetWorld(), StartPos, playerLocation, EDrawDebugTrace::ForOneFrame, true, hitResult, FLinearColor::Green, FLinearColor::Red, 0);
				if (hitResult.GetActor() == PlayerPawn)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationOutput.SelectedKeyName, PlayerPawn->GetActorLocation());
					OwnerComp.GetBlackboardComponent()->SetValueAsBool(PlayerDetectedOutput.SelectedKeyName, true);
				}
				
			}
			
			if (IsDebug) UE_LOG(LogTemp, Log, TEXT("%s hit!"), *hitResult.Component->GetName());
		}
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

UBTService_CheckLOS::UBTService_CheckLOS()
{
	NodeName = TEXT("Check line of sight for player");
}

void UBTService_CheckLOS::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	if (const UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		LocationOutput.ResolveSelectedKey(*BBAsset);
		PlayerDetectedOutput.ResolveSelectedKey(*BBAsset);
	}
}

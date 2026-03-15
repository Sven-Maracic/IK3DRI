// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Decorator/BTDecorator_NoInfConditionalLoop.h"

#include "BehaviorTree/BTCompositeNode.h"

void UBTDecorator_NoInfConditionalLoop::OnNodeDeactivation(FBehaviorTreeSearchData& SearchData, EBTNodeResult::Type NodeResult)
{
	if (NodeResult != EBTNodeResult::Aborted && NodeResult != EBTNodeResult::Failed)
	{
		const UBlackboardComponent* BlackboardComp = SearchData.OwnerComp.GetBlackboardComponent();
		const bool bEvalResult = BlackboardComp && EvaluateOnBlackboard(*BlackboardComp);

		if (bEvalResult != IsInversed())
		{
			GetParentNode()->SetChildOverride(SearchData, GetChildIndex());
		}
	}
}

UBTDecorator_NoInfConditionalLoop::UBTDecorator_NoInfConditionalLoop()
{
	NodeName = TEXT("Conditional loop with no infinite failing");
}

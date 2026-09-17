// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <ShooterAI.h>

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = TEXT("Update Last Known Player Location");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	AShooterSamCharacter* PlayerCharacter = OwnerController->PlayerCharacter;
	UBlackboardComponent* BlackboardComp = OwnerController->GetBlackboardComponent();

	if (OwnerController && PlayerCharacter && BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(GetSelectedBlackboardKey(), PlayerCharacter->GetActorLocation());
	}
}

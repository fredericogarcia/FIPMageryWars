#include "MageryWarsAbilitySystemComponent.h"

UMageryWarsAbilitySystemComponent::UMageryWarsAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}


void UMageryWarsAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UMageryWarsAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


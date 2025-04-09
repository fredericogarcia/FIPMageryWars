#include "System/MageryWarsPlayerState.h"
#include "MageryWarsAbilitySystemComponent.h"
#include "MageryWarsAttributeSet.h"

AMageryWarsPlayerState::AMageryWarsPlayerState()
{
	bReplicates = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UMageryWarsAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UMageryWarsAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

UMageryWarsAbilitySystemComponent* AMageryWarsPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMageryWarsAttributeSet* AMageryWarsPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}


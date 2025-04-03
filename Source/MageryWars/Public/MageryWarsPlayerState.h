// 

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "MageryWarsAbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "MageryWarsPlayerState.generated.h"

class UMageryWarsAttributeSet;
class UMageryWarsAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class MAGERYWARS_API AMageryWarsPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMageryWarsPlayerState();

	virtual UMageryWarsAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UMageryWarsAttributeSet* GetAttributeSet() const;

protected:
	UPROPERTY()
	TObjectPtr<UMageryWarsAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UMageryWarsAttributeSet> AttributeSet;
};

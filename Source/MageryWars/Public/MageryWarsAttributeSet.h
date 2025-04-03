#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MageryWarsAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class MAGERYWARS_API UMageryWarsAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UMageryWarsAttributeSet();

	// Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Health", ReplicatedUsing = OnRep_CurrentHealth);
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UMageryWarsAttributeSet, CurrentHealth);
	// Max Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Health", ReplicatedUsing = OnRep_MaxHealth);
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMageryWarsAttributeSet, MaxHealth);
	
	// Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Mana", ReplicatedUsing = OnRep_CurrentMana);
	FGameplayAttributeData CurrentMana;
	ATTRIBUTE_ACCESSORS(UMageryWarsAttributeSet, CurrentMana);
	// Max Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes | Mana", ReplicatedUsing = OnRep_MaxMana);
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UMageryWarsAttributeSet, MaxMana);

protected:
	// Replication Notifies
	UFUNCTION()	
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);

	UFUNCTION()	
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()	
	virtual void OnRep_CurrentMana(const FGameplayAttributeData& OldCurrentMana);

	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);

	// Attribute change handlers
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	// Replication
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "MageryWarsAbilitySystemComponent.h"
#include "MageryWarsAttributeSet.h"
#include "GameFramework/Character.h"
#include "MageryWarsCharacter.generated.h"

UCLASS()
class MAGERYWARS_API AMageryWarsCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMageryWarsCharacter();

	virtual UMageryWarsAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UMageryWarsAttributeSet* GetAttributes() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	UMageryWarsAbilitySystemComponent* AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	UMageryWarsAttributeSet* Attributes;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

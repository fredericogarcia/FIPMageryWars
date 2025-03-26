#include "MageryWarsCharacter.h"

// Sets default values
AMageryWarsCharacter::AMageryWarsCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UMageryWarsAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	Attributes = CreateDefaultSubobject<UMageryWarsAttributeSet>("Attributes");

	SetNetUpdateFrequency(100.f);

}

UMageryWarsAbilitySystemComponent* AMageryWarsCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMageryWarsAttributeSet* AMageryWarsCharacter::GetAttributes() const
{
	return Attributes;
}

// Called when the game starts or when spawned
void AMageryWarsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageryWarsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMageryWarsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


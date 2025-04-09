#include "MageryWarsCharacter.h"
#include "System/MageryWarsPlayerState.h"


// Sets default values
AMageryWarsCharacter::AMageryWarsCharacter(): AbilitySystemComponent(nullptr), Attributes(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
}

UMageryWarsAbilitySystemComponent* AMageryWarsCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMageryWarsAttributeSet* AMageryWarsCharacter::GetAttributeSet() const
{
	return Attributes;
}

void AMageryWarsCharacter::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	
	if(!HasAuthority()) return;
	
	for(const TSubclassOf AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AMageryWarsCharacter::OnRep_PlayerState() // by server
{
	Super::OnRep_PlayerState();

	if (AMageryWarsPlayerState* PS = GetPlayerState<AMageryWarsPlayerState>())
	{
		AbilitySystemComponent = Cast<UMageryWarsAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);
		Attributes = PS->GetAttributeSet();

		GiveDefaultAbilities();
	}
}

void AMageryWarsCharacter::PossessedBy(AController* NewController) // by client
{
	Super::PossessedBy(NewController);

	if (AMageryWarsPlayerState* PS = GetPlayerState<AMageryWarsPlayerState>())
	{
		AbilitySystemComponent = Cast<UMageryWarsAbilitySystemComponent>(PS->GetAbilitySystemComponent());
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);
		Attributes = PS->GetAttributeSet();

		GiveDefaultAbilities();
	}
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

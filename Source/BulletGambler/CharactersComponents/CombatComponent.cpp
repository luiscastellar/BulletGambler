//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#include "CombatComponent.h"
#include "BulletGambler/Weapon/BaseWeapon.h"
#include "BulletGambler/Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/StaticMeshSocket.h"
#include "Components/SphereComponent.h"
#include <Net/UnrealNetwork.h>


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	BaseWalkSpeed = 600.f;
	AimWalkSpeed = 450.f;
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	SetIsReplicatedByDefault(true);

	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Character is null in CombatComponent"));
	}
}

void UCombatComponent::SetAiming(bool bIsAiming)
{
	bAiming = bIsAiming;
	ServerSetAiming(bIsAiming);
	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = bAiming ? AimWalkSpeed : BaseWalkSpeed;
	}

}

void UCombatComponent::FireButtonPressed(bool bPressed)
{
	bFireButtonPressed = bPressed;
}

void UCombatComponent::ServerSetAiming_Implementation(bool bIsAiming)
{
	bAiming = bIsAiming;
	if (Character)
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = bAiming ? AimWalkSpeed : BaseWalkSpeed;
	}
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent, EquippedWeapon);
	DOREPLIFETIME(UCombatComponent, bAiming);
}

void UCombatComponent::EquipWeapon(ABaseWeapon* WeaponToEquip)
{
	if (Character == nullptr || WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);

	EquippedWeapon->AttachToComponent(
		Character->GetWeaponAttachPoint(),
		FAttachmentTransformRules::SnapToTargetNotIncludingScale
	);

	EquippedWeapon->SetOwner(Character);
}


//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#include "CombatComponent.h"
#include "BulletGambler/Weapon/BaseWeapon.h"
#include "BulletGambler/Characters/BaseCharacter.h"
#include "Engine/StaticMeshSocket.h"
#include "Components/SphereComponent.h"
#include <Net/UnrealNetwork.h>


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent, EquippedWeapon);
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


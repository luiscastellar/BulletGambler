//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#include "CombatComponent.h"
#include "BulletGambler/Weapon/BaseWeapon.h"
#include "BulletGambler/Characters/BaseCharacter.h"
#include "Engine/StaticMeshSocket.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCombatComponent::EquipWeapon(ABaseWeapon* WeaponToEquip)
{
	if (Character == nullptr || WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWT_Equipped);

	EquippedWeapon->AttachToComponent(
		Character->GetWeaponAttachPoint(),
		FAttachmentTransformRules::SnapToTargetNotIncludingScale
	);

	EquippedWeapon->SetOwner(Character);
	EquippedWeapon->ShowPickupWidget(false);
}


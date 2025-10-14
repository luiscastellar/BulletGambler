//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BULLETGAMBLER_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

	public:	

		UCombatComponent();

		friend class ABaseCharacter;

		void EquipWeapon(class ABaseWeapon* WeaponToEquip);

	protected:

		virtual void BeginPlay() override;

	private:	
		
		class ABaseCharacter* Character;
		ABaseWeapon* EquippedWeapon;
};

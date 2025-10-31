//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

#define TRACE_LENGTH 80000.f

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BULLETGAMBLER_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

	public:	

		UCombatComponent();

		friend class ABaseCharacter;

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

		void EquipWeapon(class ABaseWeapon* WeaponToEquip);

	protected:

		virtual void BeginPlay() override;
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		void SetAiming(bool bIsAiming);

		UFUNCTION(Server, Reliable)
		void ServerSetAiming(bool bIsAiming);

		void FireButtonPressed(bool bPressed);

		UFUNCTION(Server, Reliable)
		void ServerFire();

		UFUNCTION(NetMulticast, Reliable)
		void MulticastFire();

		void TraceUnderCrosshairs(FHitResult& TraceHitResult);

	private:	
		
		class ABaseCharacter* Character;

		UPROPERTY(Replicated)
		ABaseWeapon* EquippedWeapon;

		UPROPERTY(Replicated)
		bool bAiming;

		UPROPERTY(EditAnywhere)
		float BaseWalkSpeed;

		UPROPERTY(EditAnywhere)
		float AimWalkSpeed;

		bool bFireButtonPressed;

		FVector HitTarget;

		FHitResult HitResult;
};

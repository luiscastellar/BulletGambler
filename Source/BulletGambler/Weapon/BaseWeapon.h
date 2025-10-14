//LUIS CASTELLAR DOMINGUEZ / COPYRIGHT

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class BULLETGAMBLER_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
	public:	

		ABaseWeapon();

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

		void ShowPickupWidget(bool bShowWidget);

	protected:

		virtual void BeginPlay() override;

		UFUNCTION()
		virtual void OnSphereOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

		UFUNCTION()
		virtual void OnSphereEndOverlap(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	private:

		UPROPERTY(VisibleAnywhere, Category = "Weapon properties")
		UStaticMeshComponent* WeaponMesh;

		UPROPERTY(VisibleAnywhere, Category = "Weapon properties")
		class USphereComponent* AreaSphere; 

		UPROPERTY(ReplicatedUsing = OnRep_WeaponState, VisibleAnywhere, Category = "Weapon properties")
		EWeaponState WeaponState;

		UFUNCTION()
		void OnRep_WeaponState();

		UPROPERTY(VisibleAnywhere, Category = "Weapon properties")
		class UWidgetComponent* PickupWidget;

	public:

		void SetWeaponState(EWeaponState State);
		FORCEINLINE USphereComponent* GetAreaSphere() const { return AreaSphere; }
};

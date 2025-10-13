/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWT_Initial UMETA(DisplayName = "Initial State"),
	EWT_Equipped UMETA(DisplayName = "Equipped"),
	EWT_Dropped UMETA(DisplayName = "Dropped"),

	EWT_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class BULLETGAMBLER_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	

	ABaseWeapon();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Weapon properties")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon properties")
	class USphereComponent* AreaSphere;

    UPROPERTY(VisibleAnywhere)
	EWeaponState WeaponState;
};

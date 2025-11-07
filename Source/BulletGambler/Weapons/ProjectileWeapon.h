/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "ProjectileWeapon.generated.h"

class ABaseProjectile;

UCLASS()
class BULLETGAMBLER_API AProjectileWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:

	virtual void Fire(const FVector& HitTarget) override;

private:

	UPROPERTY(EditAnywhere, Category = "Weapon|Projectile")
	TSubclassOf<ABaseProjectile> ProjectileClass;
};

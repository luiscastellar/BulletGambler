/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class BULLETGAMBLER_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
	public:	

		ABaseProjectile();

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "VFX")
		class UNiagaraSystem* ProjectileTrailNiagaraSystem;

	protected:

		virtual void BeginPlay() override;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VFX", meta = (AllowPrivateAccess = "true"))
		class UNiagaraComponent* ProjectileTrailNiagaraComponent;

	private:

		UPROPERTY(EditAnywhere, Category = "Projectile")
		class UBoxComponent* CollisionBox;

		UPROPERTY(EditAnywhere, Category = "Projectile")
		class UProjectileMovementComponent* ProjectileMovementComponent;

};

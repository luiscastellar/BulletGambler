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

	protected:

		virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Projectile")
	class UBoxComponent* CollisionBox;

};

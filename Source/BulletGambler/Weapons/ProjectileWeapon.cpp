/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#include "ProjectileWeapon.h"
#include "Projectiles/BaseProjectile.h"

void AProjectileWeapon::Fire(const FVector& HitTarget)
{
	Super::Fire(HitTarget);

	APawn* InstigatorPawn = Cast<APawn>(GetOwner());
	FVector ToTarget = HitTarget - SpawnPoint->GetComponentLocation();
	FRotator TargetRotation = ToTarget.Rotation();
	if (ProjectileClass && InstigatorPawn)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = GetOwner();
		SpawnParams.Instigator = InstigatorPawn;
		UWorld* World = GetWorld();
		if (World)
		{
			World->SpawnActor<ABaseProjectile>(
				ProjectileClass,
				SpawnPoint->GetComponentLocation(),
				TargetRotation,
				SpawnParams);
		}
	}
}

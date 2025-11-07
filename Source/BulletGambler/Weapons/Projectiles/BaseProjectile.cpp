/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#include "BaseProjectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"

ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);

	CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->bRotationFollowsVelocity = true;

	ProjectileTrailNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileTrailNiagaraComponent"));
	ProjectileTrailNiagaraComponent->SetupAttachment(RootComponent);
	ProjectileTrailNiagaraComponent->SetAutoActivate(true);
}

void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (ProjectileTrailNiagaraComponent && ProjectileTrailNiagaraSystem)
	{
		ProjectileTrailNiagaraComponent->SetAsset(ProjectileTrailNiagaraSystem);
	}
}


/*LUIS CASTELLAR DOMINGUEZ / COPYRIGHT*/

#include "BaseWeapon.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "BulletGambler/Characters/BaseCharacter.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	SetRootComponent(WeaponMesh);

	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(RootComponent);
	AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(RootComponent);
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	//if (HasAuthority())
	//{
	//	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//	AreaSphere->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
	//	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseWeapon::OnSphereOverlap);
	//} 

	if (PickupWidget)
	{
		PickupWidget->SetVisibility(false);
	}
}

void ABaseWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(OtherActor);
	if (BaseCharacter && PickupWidget)
	{
		PickupWidget->SetVisibility(true);
	}

}

void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include <NiagaraFunctionLibrary.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
AGun::AGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneRoot;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("MuzzleFlashParticleSystem"));
	MuzzleFlashParticleSystem->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	MuzzleFlashParticleSystem->Deactivate();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	MuzzleFlashParticleSystem->Deactivate();
	MuzzleFlashParticleSystem->Activate();

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ShootSound, GetActorLocation());

	if (OwnerController) {
		FVector ViewpointLocation;
		FRotator ViewpointRotation;
		OwnerController->GetPlayerViewPoint(ViewpointLocation, ViewpointRotation);

		FVector EndLocation = ViewpointLocation + ViewpointRotation.Vector() * MaxRange;

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		bool IsHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			ViewpointLocation,
			EndLocation,
			ECollisionChannel::ECC_GameTraceChannel2,
			Params
		);

		if (IsHit) {
			//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 12, FColor::Red, false, 2.0f);

			if (ImpactParticleSystem) {
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(
					GetWorld(),
					ImpactParticleSystem,
					HitResult.ImpactPoint,
					HitResult.ImpactNormal.Rotation()
				);

				AActor* HitActor = HitResult.GetActor();
				if (HitActor) {
					UGameplayStatics::ApplyDamage(HitActor, BulletDamage, OwnerController, this, UDamageType::StaticClass());
				}
			}

			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, HitResult.ImpactPoint);
		}

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No owner controller!"));
	}
}


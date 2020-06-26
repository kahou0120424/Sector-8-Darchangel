// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

///////////////////////////////////////////////////////////////////////
//Distance Formula
double Distance(FVector a, FVector b)
{
	double distance = abs(sqrt(pow(b.X - a.X, 2) + pow(b.Y - a.Y, 2)));
	return distance;
}
///////////////////////////////////////////////////////////////////////

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f); //Capsule Size

	bUseControllerRotationPitch = false; // Not allowing the character to rotate
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // allow the charactor ratote to the direction it is moving  
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); //rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); // name of the component
	CameraBoom->SetupAttachment(RootComponent); // child of the RootComponent


	CameraBoom->TargetArmLength = 300.0f; // how far away the camera from the player
	CameraBoom->bUsePawnControlRotation = true; //rotate the arm base of the controller 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // attact the camera on the end of the boom, let the boom adjust the mass controller rotation of the camera
	FollowCamera->bUsePawnControlRotation = false; // Camera did not rotate relative to the r
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::Raycast()
{

	FVector Start = this->GetActorLocation();
	FVector ForwardVector = this->GetActorForwardVector();


	Start = Start + ForwardVector;
	FVector End = Start + (ForwardVector * 5000.0f);

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	//Draw raycast
	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams);

	if (isHit)
	{		
		isPull = true;
		playerPos = this->GetActorLocation();
		targetLocation = OutHit.Actor->GetActorLocation();
		velocity = -GetActorForwardVector();
	}


}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isPull == true)
	{
		float distance = Distance(playerPos, OutHit.Actor->GetActorLocation());		
		timer = speed; // no acceloration		
		percent = timer / seconds;
		velocity += velocity * timer;	
		FString TheFloatStr = FString::SanitizeFloat(distance);	
		if (distance >= 200)
		{
			OutHit.Actor->AddActorLocalOffset((velocity), false, 0, ETeleportType::None);
		}
		else
		{
			isPull = false;
			percent = 0;
			timer = 0;
		}
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	PlayerInputComponent->BindAction("ChainsOfHell", IE_Pressed, this, &AMainCharacter::Raycast);
}

void AMainCharacter::MoveForward(float Axis)
{
	
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Axis);
	
}

void AMainCharacter::MoveRight(float Axis)
{
	
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Axis);
	
}






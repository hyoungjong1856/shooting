// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
// SomWorks :D // MIT LICENSE // Epic VR Template Convert C++ Open Source Project.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UserConstant.h"
#include "TP_VirtualRealityPawn_Motion.generated.h"



UCLASS()
class SOMTEMPLATE_VR_API ATP_VirtualRealityPawn_Motion : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Components", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* CameraBase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* VRCamera;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	class ATP_MotionController* LeftController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	class ATP_MotionController* RightController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	float ThumbDeadzone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	bool bRightStickDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	bool bLeftStickDown;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	float DefaultPlayerHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VRTemplate|Variables", meta = (AllowPrivateAccess = "true"))
	bool bUseControllerRollToRotate;
	
	typedef struct Movement_Control_Variable
	{
		float Movement_Speed;
		Player_Direction Previous_State;
		Player_Direction Current_State;
	} Movement_Control_Variable;
	
	Movement_Control_Variable X_Axis, Y_Axis, Z_Axis;

protected:
	
public:
	// Sets default values for this pawn's properties
	ATP_VirtualRealityPawn_Motion();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Resets HMD orientation and position in VR
	void OnResetVR();

	// Player movement function when have input
	void DirectionUp(float NewAxisValue);
	void DirectionDown(float NewAxisValue);
	void MotionControllerThumbLeft_Y(float NewAxisValue);
	void MotionControllerThumbLeft_X(float NewAxisValue);
	void MotionControllerThumbRight_Y(float NewAxisValue);
	void MotionControllerThumbRight_X(float NewAxisValue);

	// Control player's acceleration movement
	void AccelerationMovementControl(Movement_Control_Variable* Axis, FVector DirectionVector, float AxisValue);
	
	// Fire projectile
	UFUNCTION()
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> ProjectileClass;



	//UFUNCTION()
	//	FRotator GetRotationFromInput(float UpAxis, float RightAxis, class ATP_MotionController* MotionController);
	
};

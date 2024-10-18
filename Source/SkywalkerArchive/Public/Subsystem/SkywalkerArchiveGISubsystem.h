// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/SaveGame.h"

#include "SaveGame/SkywalkerLocalPlayerSaveGame.h"

#include "SkywalkerArchiveGISubsystem.generated.h"

/**
 *
 */
UCLASS()
class SKYWALKERARCHIVE_API USkywalkerArchiveGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	USkywalkerArchiveGISubsystem();

	/**
	* �жϴ浵�Ƿ����
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool IsSaveGameExist(const FString& SlotName, const int32 UserIndex);

	/**
	* ����浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool SaveGame(const FString& SlotName, const int32 UserIndex);

	/**
	* ���ش浵
	*/
	UFUNCTION(BlueprintCallable, Category = "Skywalker|SaveGame")
	bool LoadGame(const FString& SlotName, const int32 UserIndex);

private:
	/**
	* SkywalkerLocalPlayerSaveGame ʵ��
	*/
	UPROPERTY()
	USkywalkerLocalPlayerSaveGame* LocalPlayerSaveGame = nullptr;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystem/SkywalkerArchiveGISubsystem.h"

#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(SkywalkerArchive, Log, All);

USkywalkerArchiveGISubsystem::USkywalkerArchiveGISubsystem() :UGameInstanceSubsystem()
{
	// ���� USkywalkerLocalPlayerSaveGame
	LocalPlayerSaveGame = Cast<USkywalkerLocalPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(USkywalkerLocalPlayerSaveGame::StaticClass()));
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("Create USkywalkerLocalPlayerSaveGame failed!"));
	}
}

bool USkywalkerArchiveGISubsystem::IsSaveGameExist(const FString& SlotName, const int32 UserIndex)
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex);
}

bool USkywalkerArchiveGISubsystem::SaveGame(const FString& SlotName, const int32 UserIndex)
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// ����浵
	return UGameplayStatics::SaveGameToSlot(LocalPlayerSaveGame, SlotName, UserIndex);
}

bool USkywalkerArchiveGISubsystem::LoadGame(const FString& SlotName, const int32 UserIndex)
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// TODO: ���ش浵

	return true;
}

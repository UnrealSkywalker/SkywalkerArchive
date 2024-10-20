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

void USkywalkerArchiveGISubsystem::SetSaveGame(const FString& SlotName, const int32 UserIndex)
{
	SaveGameSlotName = SlotName;
	SaveGameUserIndex = UserIndex;
}

bool USkywalkerArchiveGISubsystem::IsSaveGameExist()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	return UGameplayStatics::DoesSaveGameExist(SaveGameSlotName, SaveGameUserIndex);
}

bool USkywalkerArchiveGISubsystem::SaveGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// ����浵
	return UGameplayStatics::SaveGameToSlot(LocalPlayerSaveGame, SaveGameSlotName, SaveGameUserIndex);
}

bool USkywalkerArchiveGISubsystem::LoadGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// TODO Shyfan ���ش浵

	return true;
}

bool USkywalkerArchiveGISubsystem::DeleteGame()
{
	if (LocalPlayerSaveGame == nullptr)
	{
		UE_LOG(SkywalkerArchive, Error, TEXT("USkywalkerLocalPlayerSaveGame is nullptr!"));
		return false;
	}

	// ɾ���浵
	return UGameplayStatics::DeleteGameInSlot(SaveGameSlotName, SaveGameUserIndex);
}

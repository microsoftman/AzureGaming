// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->SetMenuInterface(MenuInterface);
}

bool UMainMenu::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	MainMenuHostBtn->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Display, TEXT("Clicked HostServer button"));

	if (MenuInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No MenuInterface found"));
		return;
	}

	MenuInterface->Host();

	/*
	UGameplayStatics::OpenLevel(GetWorld(), "ThirdPersonExampleMap");

	UGameInstance* instance = UGameplayStatics::GetGameInstance(GetWorld());
	APlayerController* PlayerController = instance->GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;
	
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
	*/
}

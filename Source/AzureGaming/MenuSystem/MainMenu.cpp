// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

void UMainMenu::SetMenuInterface(IMenuInterface* menuInterface)
{
	this->MenuInterface = menuInterface;
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
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "AzureGamingGameInstance.h"

#include "Engine/Engine.h"
#include "MenuSystem/MainMenu.h"
#include "UObject/ConstructorHelpers.h"

UAzureGamingGameInstance::UAzureGamingGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (MenuBPClass.Class != NULL)
	{
		MenuClass = MenuBPClass.Class;
		//UE_LOG(LogTemp, Warning, TEXT("Found Menu Class"));
	}
}

void UAzureGamingGameInstance::Init()
{
}

void UAzureGamingGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;

	UMainMenu *Menu = CreateWidget<UMainMenu>(this, MenuClass);

	if (!ensure(Menu != nullptr)) return;

	Menu->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;

	Menu->SetMenuInterface(this);
}

void UAzureGamingGameInstance::Host()
{
	UGameplayStatics::OpenLevel(GetWorld(), "ThirdPersonExampleMap");

	UGameInstance* instance = UGameplayStatics::GetGameInstance(GetWorld());
	APlayerController* PlayerController = instance->GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}

void UAzureGamingGameInstance::Join(const FString& Address)
{

}
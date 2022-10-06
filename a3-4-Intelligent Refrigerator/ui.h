#pragma once
#include "service.h"
#include "UndoRedo.h"


typedef struct
{
	Service* service;
	UndoService* undoServices;

}Console;

Console* CreateConsole(Service* service, UndoService* undoServices);

void DestroyConsole(Console* console);
void PrintMenuUi(Console* console);
void PrintItemUi(Console* console);
void FilterItemUi(Console* console);
void UpdateExpDateUi(Console* console, char name[], char category[]);
void UpdateCategoryUi(Console* console, char name[], char category[]);
void UpdateNameUi(Console* console, char name[], char category[]);
void UpdateQuantityUi(Console* console, char name[], char category[]);
void AddItemUi(Console* console);
void RemoveItemUi(Console* console);
void UpdateItemUi(Console* console);
void DisplaySoonToExpireUi(Console* console);
void DisplaySoonToExpireAllUi(Console* console);
void DisplaySoonToExpireCatUi(Console* console, char category[]);
void MainLoop(Console* console);

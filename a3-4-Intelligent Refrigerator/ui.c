#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Console* CreateConsole(Service* service, UndoService* undoServices)
{
	Console* console = (Console*)malloc(sizeof(Console));

	if (console == NULL)
		return NULL;

	console->service = service;
	console->undoServices = undoServices;
	return console;
}

void DestroyConsole(Console* console)
{
	free(console);
}

void PrintMenuUi(Console* console)
{
	printf("\n1. Print all items\n");
	printf("2. Add item\n");
	printf("3. Remove item\n");
	printf("4. Filter items by name\n");
	printf("5. Update item\n");
	printf("6. Display foods from x category to expire in the following y days\n");
	printf("7. Undo\n");
	printf("8. Redo\n");
	printf("9. Exit\n");
}

void PrintItemUi(Console* console)
{
	char ch[256];
	for (size_t i = 0; i < GetLength(console->service->repo); ++i)
	{
		strcpy(ch, toStr(GetElemOnPos(console->service->repo, i)));
		printf("%s\n", ch);

	}
}

void FilterItemUi(Console* console)
{
	char searchString[50];
	printf("Enter a substring for searching!:\n");
	gets(searchString);
	fgets(searchString, 50, stdin);
	searchString[strcspn(searchString, "\n")] = 0;

	IntellingetRefrigerator result[100];
	size_t size;

	GetItemContainingString(console->service, searchString, result, &size);
	char medicineString[256];

	SortByQuantity(result, size);
	for (size_t i = 0; i < size; ++i)
	{
		strcpy(medicineString, toStr(result[i]));
		printf("%s\n", medicineString);
	}
}

void AddItemUi(Console* console)
{
	char name[20], category[20];
	double quantity;
	int expday, expmonth, expyear, catinput;

	printf("Enter name: ");
	int count = scanf("%s", name);
	if (count == 0)
	{
		printf("Invalid name!\n");
		return;
	}
	printf("\n");

	printf(" 1. Meat | 2.Dairy | 3.Sweets | 4. Fruit\n");
	printf("Choose category: ");
	count = scanf("%d", &catinput);
	if (count == 0)
	{
		printf("Invalid category!\n");
		return;
	}
	else
	{
		if (catinput == 1)
			strcpy(category, "meat");
		if (catinput == 2)
			strcpy(category, "dairy");
		if (catinput == 3)
			strcpy(category, "sweets");
		if (catinput == 4)
			strcpy(category, "fruit");
	}
	printf("\n");

	printf("Enter quantity:");
	count = scanf("%lf", &quantity);
	if (count == 0)
	{
		printf("Invalid quantity!\n");
		return;
	}
	printf("\n");

	printf("Enter expiration day: ");
	count = scanf("%d", &expday);
	if (count == 0)
	{
		printf("Invalid day");
		return;
	}
	printf("Enter expiration month: ");
	count = scanf("%d", &expmonth);
	if (count == 0)
	{
		printf("Invalid month");
		return;
	}
	printf("Enter expiration year: ");
	count = scanf("%d", &expyear);
	if (count == 0)
	{
		printf("Invalid year");
		return;
	}

	int result = AddItemService(console->service, name, category, quantity, expday, expmonth, expyear);
	if (result == 1)
	{
		printf("Invalid input or Medicine already exists!\n");
		return;
	}

	Repository repoCopy = DuplicateRepo(*console->service->repo);
	AddEntry(console->undoServices, repoCopy);

}

void RemoveItemUi(Console* console)
{
	char name[20], category[20];
	int catinput;

	printf("Enter name: ");
	int count = scanf("%s", name);
	if (count == 0)
	{
		printf("Invalid name!\n");
		return;
	}
	printf("\n");

	printf(" 1. Meat | 2.Dairy | 3.Sweets | 4. Fruit\n");
	printf("Choose category: ");
	count = scanf("%d", &catinput);
	if (count == 0)
	{
		printf("Invalid category!\n");
		return;
	}
	else
	{
		if (catinput == 1)
			strcpy(category, "meat");
		if (catinput == 2)
			strcpy(category, "dairy");
		if (catinput == 3)
			strcpy(category, "sweets");
		if (catinput == 4)
			strcpy(category, "fruit");
	}
	printf("\n");

	int result = RemoveItemService(console->service, name, category);
	if (result == 1)
	{
		printf("Invalid input!\n");
		return;
	}

	Repository repoCopy = DuplicateRepo(*console->service->repo);
	AddEntry(console->undoServices, repoCopy);
}

void UpdateNameUi(Console* console, char name[], char category[])
{
	printf("\nNew name: ");
	char newname[10];
	scanf("%s", newname);
	UpdateNameService(console->service, name, category, newname);
}

void UpdateCategoryUi(Console* console, char name[], char category[])
{
	printf(" 1.Meat | 2.Dairy | 3.Sweets | 4.Fruit\n");
	printf("New category: ");
	int newcatinput;
	int count = scanf("%d", &newcatinput);
	if (count == 0)
	{
		printf("Invalid category!\n");
		return;
	}
	else
	{
		char newcategory[10];
		strcpy(newcategory, "null");
		if (newcatinput == 1)
			strcpy(newcategory, "meat");
		if (newcatinput == 2)
			strcpy(newcategory, "dairy");
		if (newcatinput == 3)
			strcpy(newcategory, "sweets");
		if (newcatinput == 4)
			strcpy(newcategory, "fruit");
		UpdateCategoryService(console->service, name, category, newcategory);
	}
}

void UpdateQuantityUi(Console* console, char name[], char category[])
{
	printf("New quantity: ");
	double newquantity = 0;
	scanf("%lf", &newquantity);
	UpdateQuantityService(console->service, name, category, newquantity);
}

void UpdateExpDateUi(Console* console, char name[], char category[])
{
	printf("\nNew expiration day: ");
	int newday = 0, newmonth = 0, newyear = 0;
	scanf("%d", &newday);
	printf("\nNew expiration month: ");
	scanf("%d", &newmonth);
	printf("\nNew expiraton year: ");
	scanf("%d", &newyear);
	UpdateExpDateService(console->service, name, category, newday, newmonth, newyear);
}

void UpdateItemUi(Console* console)
{
	char name[10], category[10];
	int catinput;
	printf("Name: ");
	int count = scanf("%s", &name);
	if (count == 0)
	{
		printf("Incalid name!\n");
		return;
	}
	printf("\n");
	printf(" 1. Meat | 2.Dairy | 3.Sweets | 4. Fruit\n");
	printf("Category: ");
	count = scanf("%d", &catinput);
	if (count == 0)
	{
		printf("Invalid category!\n");
		return;
	}
	else
	{
		if (catinput == 1)
			strcpy(category, "meat");
		if (catinput == 2)
			strcpy(category, "dairy");
		if (catinput == 3)
			strcpy(category, "sweets");
		if (catinput == 4)
			strcpy(category, "fruit");
	}
	printf("\n");
	printf("1. Update name\n");
	printf("2. Update category\n");
	printf("3. Update quantity\n");
	printf("4. Update expiration date\n");
	int input;
	printf("Input: ");
	scanf("%d", &input);
	printf("\n");
	if (input == 3)
	{
		UpdateQuantityUi(console, name, category);

		Repository repoCopy = DuplicateRepo(*console->service->repo);
		AddEntry(console->undoServices, repoCopy);
	}
	if (input == 4)
	{
		UpdateExpDateUi(console, name, category);

		Repository repoCopy = DuplicateRepo(*console->service->repo);
		AddEntry(console->undoServices, repoCopy);
	}
	if (input == 1)
	{
		UpdateNameUi(console, name, category);

		Repository repoCopy = DuplicateRepo(*console->service->repo);
		AddEntry(console->undoServices, repoCopy);
	}
	if (input == 2)
	{
		UpdateCategoryUi(console, name, category);

		Repository repoCopy = DuplicateRepo(*console->service->repo);
		AddEntry(console->undoServices, repoCopy);
	}
}

void DisplaySoonToExpireUi(Console* console)
{
	printf(" 1.Meat | 2.Dairy | 3.Sweets | 4.Fruit | 5.All\n");
	printf("New category: ");
	int catinput;
	int count = scanf("%d", &catinput);
	if (catinput == 5)
	{
		DisplaySoonToExpireAllUi(console);
	}
	else
	{
		char category[10];
		strcpy(category, "null");
		if (catinput == 1)
			strcpy(category, "meat");
		if (catinput == 2)
			strcpy(category, "dairy");
		if (catinput == 3)
			strcpy(category, "sweets");
		if (catinput == 4)
			strcpy(category, "fruit");
		if (strcmp(category, "null") == 0)
		{
			printf("Invalid option\n");
			return;
		}
		DisplaySoonToExpireCatUi(console, category);
	}
}

void DisplaySoonToExpireAllUi(Console* console)
{
	printf("\nNumber of days: ");
	int day;
	int dcount = scanf("%d", &day);
	if (dcount == 0)
	{
		printf("Invalid number of days");
		return;
	}

	IntellingetRefrigerator result[100];
	size_t size;

	DisplaySoonToExpireAllService(console->service, result, &size, day);
	char medicineString[256];

	SortByQuantity(result, size);
	for (size_t i = 0; i < size; ++i)
	{
		strcpy(medicineString, toStr(result[i]));
		printf("%s\n", medicineString);
	}
}

void DisplaySoonToExpireCatUi(Console* console, char category[])
{
	printf("\nNumber of days: ");
	int day;
	int dcount = scanf("%d", &day);
	if (dcount == 0)
	{
		printf("Invalid number of days");
		return;
	}


	IntellingetRefrigerator result[100];
	size_t size;

	DisplaySoonToExpireCatService(console->service, result, &size, category, day);
	char medicineString[256];

	SortByQuantity(result, size);
	for (size_t i = 0; i < size; ++i)
	{
		strcpy(medicineString, toStr(result[i]));
		printf("%s\n", medicineString);
	}
}


void MainLoop(Console* console)
{
	int input, ok = 1;
	while (ok == 1)
	{
		PrintMenuUi(console);
		printf("\nChoose input: ");
		scanf("%d", &input);
		printf("\n");
		if (input == 1)
			PrintItemUi(console);
		if (input == 2)
			AddItemUi(console);
		if (input == 3)
			RemoveItemUi(console);
		if (input == 4)
			FilterItemUi(console);
		if (input == 5)
			UpdateItemUi(console);
		if (input == 6)
			DisplaySoonToExpireUi(console);
		if (input == 7)
		{
			int result = UndoAction(console->undoServices, console->service->repo);
			if (result == 1)
			{
				printf("No more undos remaining!\n");
			}
		}
		if (input == 8)
		{
			int result = RedoAction(console->undoServices, console->service->repo);
			if (result == 1)
			{
				printf("No more redos remaining!\n");
			}
		}
		if (input == 9)
		{
			ok = 3;
			printf("Exit\n");
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include "service.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>


Service* CreateService(Repository* repo)
{
	Service* service = (Service*)malloc(sizeof(Service));

	if (service == NULL)
		return NULL;

	service->repo = repo;

	return service;
}

void DestroyService(Service* service)
{
	free(service);
}

int UniqueItem(Service* service, char name[], char category[])
{
	for (size_t i = 0; i < GetLength(service->repo); ++i)
		if (strcmp(name, GetElemOnPos(service->repo, i).name) == 0 && strcmp(category, getCategory(GetElemOnPos(
			service->repo, i))) == 0) return 0;
	return 1;
}

int AddItemService(Service* service, char name[], char category[], double quantity, int expday, int expmonth, int expyear)
{
	if (!ValidParam(name, category, quantity, expday, expmonth, expyear)) return 1;
	if (!UniqueItem(service, name, category))
	{
		double newquantity = 0;
		for (size_t i = 0; i < GetLength(service->repo); ++i)
			if (strcmp(name, GetElemOnPos(service->repo, i).name) == 0 && strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
				newquantity = getQuantity(GetElemOnPos(service->repo, i));
		newquantity += quantity;
		UpdateQuantityService(service, name, category, newquantity);
		return 0;
	}
	else {
		IntellingetRefrigerator item = CreateRefrigerator(name, category, quantity, expday, expmonth, expyear);
		AddItem(service->repo, item);
		return 0;
	}
}

int RemoveItemService(Service* service, char name[], char category[])
{
	int found = 1;
	for (size_t i = 0; i < GetLength(service->repo); i++)
	{
		if (strcmp(name, getName(GetElemOnPos(service->repo, i))) == 0 &&
			strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			found = 0;
			RemoveItem(service->repo, i);
		}
	}
	return found;
}

int UpdateQuantityService(Service* service, char name[], char category[], double NewQuantity)
{
	for (size_t i = 0; i < GetLength(service->repo); i++)
	{
		if (strcmp(name, getName(GetElemOnPos(service->repo, i))) == 0 &&
			strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			UpdateQuantity(service->repo, i, NewQuantity);
			return 1;
		}
	}
	return 0;
}
int UpdateExpDateService(Service* service, char name[], char category[], int expday, int expmonth, int expyear)
{
	for (size_t i = 0; i < GetLength(service->repo); i++)
	{
		if (strcmp(name, getName(GetElemOnPos(service->repo, i))) == 0 &&
			strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			UpdateExpDate(service->repo, i, expday, expmonth, expyear);
			return 1;
		}
	}
	return 0;
}

int UpdateNameService(Service* service, char name[], char category[], char newname[])
{
	for (size_t i = 0; i < GetLength(service->repo); i++)
	{
		if (strcmp(name, getName(GetElemOnPos(service->repo, i))) == 0 &&
			strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			UpdateCategory(service->repo, i, newname);
			return 1;
		}
	}
	return 0;
}

int UpdateCategoryService(Service* service, char name[], char category[], char newcategory[])
{
	for (size_t i = 0; i < GetLength(service->repo); i++)
	{
		if (strcmp(name, getName(GetElemOnPos(service->repo, i))) == 0 &&
			strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			UpdateCategory(service->repo, i, newcategory);
			return 1;
		}
	}
	return 0;
}

void GetItemContainingString(Service* service, char searchString[], IntellingetRefrigerator* result, size_t* size)
{
	*size = 0;
	char name[256];

	for (size_t i = 0; i < GetLength(service->repo); ++i)
	{
		strcpy(name, GetElemOnPos(service->repo, i).name);
		if (strstr(name, searchString))
		{
			result[*size] = GetElemOnPos(service->repo, i);
			(*size)++;
		}

	}
}

void SortByQuantity(IntellingetRefrigerator* array, size_t size)
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = i + 1; j < size; ++j)
		{
			double ch1;
			ch1 = getQuantity(array[i]);
			double ch2;
			ch2 = getQuantity(array[j]);

			if (ch1 < ch2)
			{

				IntellingetRefrigerator aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
}

void DisplaySoonToExpireAllService(Service* service, IntellingetRefrigerator* result, size_t* size, int day)
{
	int expday = 0, expmonth = 0, expyear = 0;
	getExpireDate(service, day, &expday, &expmonth, &expyear);
	*size = 0;
	char name[256];
	for (size_t i = 0; i < GetLength(service->repo); ++i)
	{
		strcpy(name, GetElemOnPos(service->repo, i).name);
		if (expyear > getExpYear(GetElemOnPos(service->repo, i)))
		{
			result[*size] = GetElemOnPos(service->repo, i);
			(*size)++;
		}
		else if (expyear <= getExpYear(GetElemOnPos(service->repo, i)) && expmonth > getExpMonth(GetElemOnPos(service->repo, i)))
		{
			result[*size] = GetElemOnPos(service->repo, i);
			(*size)++;
		}
		else if (expyear <= getExpYear(GetElemOnPos(service->repo, i)) && expmonth >= getExpMonth(GetElemOnPos(service->repo, i)) && expday >= getExpDay(GetElemOnPos(service->repo, i)))
		{
			result[*size] = GetElemOnPos(service->repo, i);
			(*size)++;
		}
	}
}

void DisplaySoonToExpireCatService(Service* service, IntellingetRefrigerator* result, size_t* size, char category[], int day)
{
	int expday = 0, expmonth = 0, expyear = 0;
	getExpireDate(service, day, &expday, &expmonth, &expyear);
	*size = 0;
	char name[256];

	for (size_t i = 0; i < GetLength(service->repo); ++i)
	{
		if (strcmp(category, getCategory(GetElemOnPos(service->repo, i))) == 0)
		{
			strcpy(name, GetElemOnPos(service->repo, i).name);
			if (expyear > getExpYear(GetElemOnPos(service->repo, i)))
			{
				result[*size] = GetElemOnPos(service->repo, i);
				(*size)++;
			}
			else if (expyear <= getExpYear(GetElemOnPos(service->repo, i)) && expmonth > getExpMonth(GetElemOnPos(service->repo, i)))
			{
				result[*size] = GetElemOnPos(service->repo, i);
				(*size)++;
			}
			else if (expyear <= getExpYear(GetElemOnPos(service->repo, i)) && expmonth >= getExpMonth(GetElemOnPos(service->repo, i)) && expday >= getExpDay(GetElemOnPos(service->repo, i)))
			{
				result[*size] = GetElemOnPos(service->repo, i);
				(*size)++;
			}
		}
	}
}

void getExpireDate(Service* service, int day, int* expday, int* expmonth, int* expyear)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	tm.tm_year -= 100;
	tm.tm_mon += 1;
	*expday = tm.tm_mday + day;
	*expmonth = tm.tm_mon;
	*expyear = tm.tm_year;
	printf("\n");
	while (*expday > 31)
	{
		if (*expmonth == 1)
			*expday -= 31;
		else if (*expmonth == 2)
			*expday -= 28;
		else if (*expmonth == 3)
			*expday -= 31;
		else if (*expmonth == 4)
			*expday -= 30;
		else if (*expmonth == 5)
			*expday -= 31;
		else if (*expmonth == 6)
			*expday -= 30;
		else if (*expmonth == 7)
			*expday -= 31;
		else if (*expmonth == 8)
			*expday -= 31;
		else if (*expmonth == 9)
			*expday -= 30;
		else if (*expmonth == 10)
			*expday -= 31;
		else if (*expmonth == 11)
			*expday -= 30;
		else if (*expmonth == 12)
			*expday -= 31;

		*expmonth += 1;
		if (*expmonth > 12)
		{
			*expyear += 1;
			*expmonth -= 12;
		}
	}
}

void RunAllTestsService()
{
	TestAddService();
	TestRemoveService();
	TestUpdateService();
	TestFilterService();
	TestSorting();
}

void TestAddService()
{
	Repository* repo = CreateRepo(1);

	IntellingetRefrigerator* services = CreateService(repo);
	int result = AddItemService(services, "apple", "fruit", 50, 5, 5, 23);

	assert(result == 0);

	result = AddItemService(services, "apple", "p", 50, 5, 5, 23);

	assert(result == 1);

	result = AddItemService(services, "apple", "fruit", 50, 5, 5, 21);

	assert(result == 1);

	result = AddItemService(services, "apple", "meat", 50, 5, 5, 23);

	assert(result == 0);

	result = AddItemService(services, "apple", "fruit", 50, 0, 5, 23);

	assert(result == 1);

	DestroyService(services);
	DestroyRepo(repo);
}

void TestRemoveService()
{
	Repository* repo = CreateRepo(1);

	IntellingetRefrigerator* services = CreateService(repo);
	InitRepo(repo);

	int result = RemoveItemService(services, "apple", "fruit");

	assert(result == 1);

	result = RemoveItemService(services, "apple", "fruit");

	assert(result == 1);

	DestroyService(services);
	DestroyRepo(repo);
}

void TestUpdateService()
{
	Repository* repo = CreateRepo(1);

	IntellingetRefrigerator* services = CreateService(repo);
	InitRepo(repo);

	int result = UpdateNameService(services, "apple", "fruit", "pear");

	assert(result == 0);

	result = UpdateCategoryService(services, "apple", "fruit", "hg");

	assert(result == 0);

	result = UpdateExpDateService(services, "apple", "fruit", 12, 2, 21);

	assert(result == 0);

	result = UpdateExpDateService(services, "apple", "fruit", 1, 1, 23);

	assert(result == 0);

	DestroyService(services);
	DestroyRepo(repo);
}

void TestFilterService()
{
	Repository* repo = CreateRepo(1);

	IntellingetRefrigerator* services = CreateService(repo);
	InitRepo(repo);

	IntellingetRefrigerator result[51];
	size_t size;

	GetItemContainingString(services, "co", result, &size);

	assert(size == 2);
	assert(Equal(result[0], repo->array->elements[0]) == 1);
	assert(Equal(result[1], repo->array->elements[1]) == 0);


	DestroyService(services);
	DestroyRepo(repo);
}

void TestSorting()
{
	Repository* repo = CreateRepo(1);

	IntellingetRefrigerator* services = CreateService(repo);
	InitRepo(repo);

	IntellingetRefrigerator result[51];
	size_t size = 5;

	SortByQuantity(result, size);

	int sorted = 1;
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (result[i].quantity > result[i + 1].quantity)
		{
			sorted = 0;
			break;
		}
	}

	assert(sorted == 1);

	DestroyService(services);
	DestroyRepo(repo);
}
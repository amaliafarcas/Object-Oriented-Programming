#define _CRT_SECURE_NO_WARNINGS
#include "domain.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>



IntellingetRefrigerator CreateRefrigerator(char name[], char category[], double quantity, int expday, int expmonth, int expyear)
{
	IntellingetRefrigerator item;
	strcpy(item.name, name);
	strcpy(item.category, category);
	item.quantity = quantity;
	item.expday = expday;
	item.expmonth = expmonth;
	item.expyear = expyear;

	return item;
}

char* getName(IntellingetRefrigerator item)
{
	return item.name;
}

char* getCategory(IntellingetRefrigerator item)
{
	return item.category;
}

double getQuantity(IntellingetRefrigerator item)
{
	return item.quantity;
}

int getExpDay(IntellingetRefrigerator item)
{
	return item.expday;
}

int getExpMonth(IntellingetRefrigerator item)
{
	return item.expmonth;
}

int getExpYear(IntellingetRefrigerator item)
{
	return item.expyear;
}

void setName(IntellingetRefrigerator* item, char name[])
{
	strcpy(item->name, name);
}

void setCategory(IntellingetRefrigerator* item, char category[])
{
	strcpy(item->category, category);
}

void setQuantity(IntellingetRefrigerator* item, double quantity)
{
	item->quantity = quantity;
}

void setExpDay(IntellingetRefrigerator* item, int day)
{
	item->expday = day;
}

void setExpMonth(IntellingetRefrigerator* item, int month)
{
	item->expmonth = month;
}

void setExpYear(IntellingetRefrigerator* item, int year)
{
	item->expyear = year;
}

char* toStr(IntellingetRefrigerator item)
{
	char final_string[256] = "Name: ";
	strcat(final_string, item.name);
	strcat(final_string, " | Category: ");
	strcat(final_string, item.category);
	strcat(final_string, " | Quantity: ");

	char quantity[256];
	int sizee = snprintf(quantity, 100, "%.2f", item.quantity);
	strcat(final_string, quantity);
	strcat(final_string, " | Expiration date: ");

	char eday[256];
	sizee = sprintf(eday, "%d", item.expday);
	strcat(final_string, eday);
	strcat(final_string, ".");

	char emonth[256];
	sizee = sprintf(emonth, "%d", item.expmonth);
	strcat(final_string, emonth);
	strcat(final_string, ".");

	char eyear[256];
	sizee = sprintf(eyear, "%d", item.expyear);
	strcat(final_string, eyear);
	strcat(final_string, "\0");

	return final_string;

}

int ValidParam(char name[], char category[], double quantity, int expday, int expmonth, int expyear)
{
	if (!ValidName(name) || !ValidCategory(category) || !ValidQuantity(quantity) || !ValidExpDate(expday, expmonth, expyear))
		return 0;
	return 1;
}

int ValidName(char name[])
{
	if (strlen(name) == 0) return 0;
	return 1;
}

int ValidCategory(char category[])
{
	char categories[4][51] = { "dairy", "sweets", "meat", "fruit" };
	int found = 0;
	for (int i = 0; i < 4; ++i)
		if (strcmp(category, categories[i]) == 0)
		{
			found = 1;
			break;
		}
	return found;
}

void Assign(IntellingetRefrigerator source, IntellingetRefrigerator* destination)
{

	strcpy(destination->name, source.name);
	strcpy(destination->category, source.category);
	destination->quantity = source.quantity;
	destination->expday = source.expday;
	destination->expmonth = source.expmonth;
	destination->expyear = source.expyear;
}

int Equal(IntellingetRefrigerator first, IntellingetRefrigerator second)
{
	if (strcmp(first.name, second.name) == 0 && strcmp(first.category, second.category) == 0 &&
		first.quantity == second.quantity && first.expday == second.expday && first.expmonth == second.expday && first.expyear == second.expyear)
		return 1;
	return 0;
}

int ValidQuantity(double quantity)
{
	if (quantity > 0x3f3f3f3f) return 0;
	return 1;
}

int ValidExpDate(int expday, int expmonth, int expyear)
{
	if (expmonth > 13 || expmonth < 1) return 0;
	if (expyear < 22) return 0;
	if (expday < 1) return 0;
	if (expmonth == 1)
		if (expday > 31) return 0;
	if (expmonth == 2)
		if (expday > 28) return 0;
	if (expmonth == 3)
		if (expday > 31) return 0;
	if (expmonth == 4)
		if (expday > 30) return 0;

	if (expmonth == 5)
		if (expday > 31) return 0;
	if (expmonth == 6)
		if (expday > 30) return 0;
	if (expmonth == 7)
		if (expday > 31) return 0;
	if (expmonth == 8)
		if (expday > 30) return 0;

	if (expmonth == 9)
		if (expday > 30) return 0;
	if (expmonth == 10)
		if (expday > 31) return 0;
	if (expmonth == 11)
		if (expday > 30) return 0;
	if (expmonth == 12)
		if (expday > 31) return 0;

	return 1;
}

void RunAllTestsRefrigerator()
{
	TestCreateItemAndGetters();
	TestSetters();
	TestEquality();
	TestAssignment();
	TestToString();
	TestValidation();
}

void TestCreateItemAndGetters()
{
	IntellingetRefrigerator c1 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);

	char* name = getName(c1);
	char* category = getCategory(c1);
	assert(strcmp("apple", name) == 0);
	assert(strcmp("fruit", category) == 0);
	assert(getQuantity(c1) == 50);
	assert(getExpDay(c1) == 5);
	assert(getExpMonth(c1) == 5);
	assert(getExpYear(c1) == 23);
}

void TestSetters()
{
	IntellingetRefrigerator c1 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);

	setQuantity(&c1, 100);
	setName(&c1, "lindt");

	assert(strcmp("lindt", getName(c1)) == 0);
	assert(strcmp("fruit", getCategory(c1)) == 0);
	assert(getQuantity(c1) == 100);
}

void TestEquality()
{
	IntellingetRefrigerator c1 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
	IntellingetRefrigerator c2 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
	IntellingetRefrigerator c3 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 22);

	assert(Equal(c1, c2) == 1);
	assert(Equal(c1, c3) == 0);
}

void TestAssignment()
{
	IntellingetRefrigerator c1 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
	IntellingetRefrigerator c2 = CreateRefrigerator("apple", "fruit", 50, 5, 7, 23);

	Assign(c2, &c1);
	assert(strcmp("apple", getName(c1)) == 0);
	assert(strcmp("fruit", getCategory(c1)) == 0);
	assert(getQuantity(c1) == 50);
}

void TestToString()
{
	IntellingetRefrigerator c1 = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);

	char* countryString = toStr(c1);
	assert(strstr(countryString, "apple") != NULL);
	assert(strstr(countryString, "fruit") != NULL);
	assert(strstr(countryString, "50") != NULL);
}

void TestValidation()
{
	assert(ValidParam("apple", "kjh", 50, 5, 5, 21) == 0);
	assert(ValidParam("apple", "fruit", 50, 5, 5, 23) == 1);
	assert(ValidParam("apple", "meat", 50, 5, 5, 23) == 1);
	assert(ValidParam("apple", "sweets", 50, 5, 5, 23) == 1);
	assert(ValidParam("apple", "dairy", 50, 5, 5, 23) == 1);
	assert(ValidParam("apple", "fruit", 50, 5, 12, 23) == 1);
	assert(ValidParam("apple", "fruit", 50, 2, 31, 23) == 0);
	assert(ValidParam("apple", "fruit", 0, 0, 0, 0) == 0);
}

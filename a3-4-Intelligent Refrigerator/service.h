#pragma once

#include "repo.h"

typedef struct
{
	Repository* repo;
}Service;

/// <summary>
/// Constructor for a CountryService object
/// </summary>
/// <param name="repository">The repository on which it operates</param>
/// <returns>A new CountryService object</returns>
Service* CreateService(Repository* repo);

/// <summary>
/// Destructor for the CountryService object
/// </summary>
/// <param name="services">The object to be destroyed</param>
void DestroyService(Service* service);

/// <summary>
/// Adds a new item to the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="quantity">The quantity of the item</param>
/// <param name="expday">The exp day of the item</param>
/// <param name="expmonth">The exp month of the item</param>
/// <param name="expyear">The exp year of the item</param>
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int AddItemService(Service* service, char name[], char category[], double quantity, int expday, int expmonth, int expyear);

/// <summary>
/// Removes an item from the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int RemoveItemService(Service* service, char name[], char category[]);

/// <summary>
/// Updates the quantity of an item from the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="NewQuantity">The new quantity of the item</param>
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int UpdateQuantityService(Service* service, char name[], char category[], double NewQuantity);

/// <summary>
/// Updates the name of an item from the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="expday">The new exp day of the item</param>
/// <param name="expmonth">The new exp month of the item</param>
/// <param name="expyear">The new exp year of the item</param
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int UpdateExpDateService(Service* service, char name[], char category[], int expday, int expmonth, int expyear);

/// <summary>
/// Updates the name of an item from the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="newname">The new name of the item</param>
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int UpdateNameService(Service* service, char name[], char category[], char newname[]);

/// <summary>
/// Updates the name of an item from the repository
/// </summary>
/// <param name="services">The services object</param>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="newcategpry">The new category of the item</param>
/// <returns>0 if the operation was succesful, 1 otherwise</returns>
int UpdateCategoryService(Service* service, char name[], char category[], char newcategory[]);

/// <summary>
/// Filters the items in the repo by a string
/// </summary>
/// <param name="services">The services object</param>
/// <param name="searchString">The substring to search by</param>
/// <param name="result">The resulting items of the search</param>
/// <param name="size">The size of the array containing the resulting countries</param>
void GetItemContainingString(Service* service, char searchString[], IntellingetRefrigerator* result, size_t* size);

/// <summary>
/// Sorts an array of items ascendingly by their quantity
/// </summary>
/// <param name="array">An array of items</param>
/// <param name="size">The size of the array</param>
void SortByQuantity(IntellingetRefrigerator* array, size_t size);

/// <summary>
/// Filters the items in the repo by the number of days they expire in
/// </summary>
/// <param name="services">The services object</param>
/// <param name="result">The resulting items of the search</param>
/// <param name="size">The size of the array</param>
/// <param name="day">The number of maximum number of days an item to expire in</param>
void DisplaySoonToExpireAllService(Service* service, IntellingetRefrigerator* result, size_t* size, int day);

/// <summary>
/// Filters the items in the repo from a given category by the number of days they expire in
/// </summary>
/// <param name="services">The services object</param>
/// <param name="result">The resulting items of the search</param>
/// <param name="size">The size of the array</param>
/// <param name="category">The name of the category the items should belong to</param>
/// <param name="day">The number of maximum number of days an item to expire in</param>
void DisplaySoonToExpireCatService(Service* service, IntellingetRefrigerator* result, size_t* size, char category[], int day);

/// <summary>
/// Gets the maximum expiration date (from the current date) by the number of days introduced from the console
/// </summary>
/// <param name="services">The services object</param>
/// <param name="day">The number of maximum number of days an item to expire in</param>
/// <param name="expday">The max exp day of the item</param>
/// <param name="expmonth">The max exp month of the item</param>
/// <param name="expyear">The max exp year of the item</param
void getExpireDate(Service* service, int day, int* expday, int* expmonth, int* expyear);

void RunAllTestsService();
void TestAddService();
void TestRemoveService();
void TestUpdateService();
void TestFilterService();
void TestSorting();
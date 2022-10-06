#pragma once

#include "DynamicArray.h"
#include <stddef.h>

typedef struct
{
	DynamicArray* array;

}Repository;

/// <summary>
/// Constructor for a Repository object
/// </summary>
/// <param name="maxLength">The maximum size of the repository</param>
/// <returns>The new Repository object</returns>
Repository* CreateRepo(size_t maxLength);

/// <summary>
/// Destructor for a repository
/// </summary>
/// <param name="repo">The repo to be destroyed</param>
void DestroyRepo(Repository* repo);

/// <summary>
/// Adds a new item to the repository
/// </summary>
/// <param name="repo">The repository where to add the item</param>
/// <param name="item">The new item to be added</param>
void AddItem(Repository* repo, IntellingetRefrigerator item);

/// <summary>
/// Removes an item from the repository
/// </summary>
/// <param name="repo">The repository from where to remove the item</param>
/// <param name="position">The position of the item</param>
void RemoveItem(Repository* repo, size_t position);

/// <summary>
/// Updates the quantity of an item of the repo
/// </summary>
/// <param name="repo">The repo that contains the item</param>
/// <param name="position">The position of the item</param>
/// <param name="quantity">The new quantity of the item</param>
void UpdateQuantity(Repository* repo, rsize_t position, double newQuatity);

/// <summary>
/// Updates the exp date of an item of the repo
/// </summary>
/// <param name="repo">The repo that contains the item</param>
/// <param name="position">The position of the item</param>
/// <param name="newday">The new exp day of the item</param>
/// <param name="newmonth">The new exp month of the item</param>
/// <param name="newyear">The new exp year of the item</param>
void UpdateExpDate(Repository* repo, rsize_t position, int newday, int newmonth, int newyear);

/// <summary>
/// Updates the name of an item of the repo
/// </summary>
/// <param name="repo">The repo that contains the item</param>
/// <param name="position">The position of the item</param>
/// <param name="name">The new name of the item</param>
void UpdateName(Repository* repo, rsize_t position, char name[]);

/// <summary>
/// Updates the category of an item of the repo
/// </summary>
/// <param name="repo">The repo that contains the item</param>
/// <param name="position">The position of the item</param>
/// <param name="category">The new category of the item</param>
void UpdateCategory(Repository* repo, rsize_t position, char category[]);

/// <summary>
/// Adds some initial values to the repo
/// </summary>
/// <param name="repo">The repo to be modified</param>
void InitRepo(Repository* repo);

/// <summary>
/// Copy constructor for a Repository object
/// </summary>
/// <param name="source">The repo to be copied</param>
/// <returns>A copy of the given repository</returns>
Repository DuplicateRepo(Repository source);

/// <summary>
/// Copies the elements of the source repo in the destination repo
/// </summary>
/// <param name="sourceRepo">The source repo</param>
/// <param name="destinationRepo">The destination repo</param>
void CopyRepo(Repository sourceRepo, Repository* destinationRepo);

/// <summary>
/// Getter for the length of the repo
/// </summary>
/// <param name="repo">The repository</param>
/// <returns>The length of the repository</returns>
size_t GetLength(Repository* repo);

/// <summary>
/// Indexing operator for the repository
/// </summary>
/// <param name="repo">The repository</param>
/// <param name="position">The position of the element</param>
/// <returns>The element on the given position in the repo</returns>
IntellingetRefrigerator GetElemOnPos(Repository* repo, size_t position);

void RunAllTestsRepo();
void TestCreateDestroyRepo();
void TestAdd();
void TestRemove();
void TestUpdaters();
void TestCopying();
void TestGetters();
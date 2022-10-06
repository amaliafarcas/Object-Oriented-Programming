#include "repo.h"
#include <stdlib.h>
#include <assert.h>



Repository* CreateRepo(size_t maxLength)
{
    Repository* repo = (Repository*)malloc(sizeof(Repository));

    if (repo == NULL)
        return NULL;

    repo->array = CreateArray(maxLength);
    if (repo->array == NULL)
        return NULL;

    return repo;
}

void DestroyRepo(Repository* repo)
{
    if (repo == NULL)
        return NULL;

    DestroyArray(repo->array);
    repo->array = NULL;

    free(repo);
}

void AddItem(Repository* repo, IntellingetRefrigerator item)
{
    AddElement(repo->array, item);
}

void RemoveItem(Repository* repo, size_t position)
{
    RemoveElement(repo->array, position);
}

void UpdateQuantity(Repository* repo, rsize_t position, double newQuatity)
{
    setQuantity(&repo->array->elements[position], newQuatity);
}

void UpdateExpDate(Repository* repo, rsize_t position, int newday, int newmonth, int newyear)
{
    setExpDay(&repo->array->elements[position], newday);
    setExpMonth(&repo->array->elements[position], newmonth);
    setExpYear(&repo->array->elements[position], newyear);
}

void UpdateName(Repository* repo, rsize_t position, char name[])
{
    setName(&repo->array->elements[position], name);
}

void UpdateCategory(Repository* repo, rsize_t position, char category[])
{
    setCategory(&repo->array->elements[position], category);
}

void InitRepo(Repository* repo)
{
    AddItem(repo, CreateRefrigerator("chocolate", "sweets", 3, 12, 12, 22));
    AddItem(repo, CreateRefrigerator("ricotta", "dairy", 1, 23, 03, 22));
    AddItem(repo, CreateRefrigerator("beef", "meat", 2.7, 30, 04, 22));
    AddItem(repo, CreateRefrigerator("apples", "fruit", 3, 12, 12, 23));
    AddItem(repo, CreateRefrigerator("lindt", "sweets", 2, 15, 11, 23));
    AddItem(repo, CreateRefrigerator("cake", "sweets", 1, 15, 03, 22));
    AddItem(repo, CreateRefrigerator("milk", "dairy", 1.5, 01, 04, 22));
    AddItem(repo, CreateRefrigerator("chicken", "meat", 2, 30, 04, 22));
    AddItem(repo, CreateRefrigerator("pears", "fruit", 3, 12, 12, 23));
    AddItem(repo, CreateRefrigerator("goat cheese", "dairy", 2, 15, 11, 22));
}

void CopyRepo(Repository sourceRepo, Repository* destinationRepo)
{
    Copy(*sourceRepo.array, destinationRepo->array);
}

Repository DuplicateRepo(Repository source)
{
    Repository newRepo;

    DynamicArray* newArray = CreateArray(1);
    DuplicateArray(*source.array, newArray);

    newRepo.array = newArray;
    if (newRepo.array == NULL)
    {
        newRepo.array->maxLength = 0;
        newRepo.array->length = 0;
    }

    return newRepo;
}


size_t GetLength(Repository* repo)
{
    return repo->array->length;
}

IntellingetRefrigerator GetElemOnPos(Repository* repo, size_t position)
{
    if (position > repo->array->length)
        return CreateRefrigerator("Invalid", "Invalid", 0, 0, 0, 0);
    return repo->array->elements[position];
}

void RunAllTestsRepo()
{
    TestCreateDestroyRepo();
    TestAdd();
    TestRemove();
    TestUpdaters();
    TestCopying();
    TestGetters();
}

void TestCreateDestroyRepo()
{
    Repository* repo = CreateRepo(4);
    assert(repo != NULL);
    assert(repo->array->maxLength == 4);
    assert(repo->array->length == 0);

    DestroyRepo(repo);
}

void TestAdd()
{
    Repository* repo = CreateRepo(1);

    IntellingetRefrigerator pear = CreateRefrigerator("pear", "fruit", 50, 5, 5, 23);
    AddItem(repo, pear);
    assert(Equal(repo->array->elements[0], pear));
    assert(repo->array->length == 1);

    IntellingetRefrigerator apple = CreateRefrigerator("apple", "fruit", 50, 5, 5, 22);
    AddItem(repo, apple);
    assert(Equal(repo->array->elements[1], apple));
    assert(repo->array->maxLength == 2);
    assert(repo->array->length == 2);

    DestroyRepo(repo);
}

void TestRemove()
{
    Repository* repo = CreateRepo(1);

    IntellingetRefrigerator pear = CreateRefrigerator("pear", "fruit", 50, 5, 5, 23);
    AddItem(repo, pear);
    IntellingetRefrigerator apple = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, apple);
    IntellingetRefrigerator plum = CreateRefrigerator("plum", "fruit", 50, 5, 5, 23);
    AddItem(repo, plum);

    RemoveItem(repo, 1);
    assert(Equal(repo->array->elements[0], pear));
    assert(Equal(repo->array->elements[1], plum));
    assert(repo->array->length == 2);
    assert(repo->array->maxLength == 4);

    AddItem(repo, apple);
    RemoveItem(repo, 0);
    assert(Equal(repo->array->elements[0], plum));
    assert(Equal(repo->array->elements[1], apple));
    assert(repo->array->length == 2);
    assert(repo->array->maxLength == 4);

    DestroyRepo(repo);
}

void TestUpdaters()
{
    Repository* repo = CreateRepo(3);

    IntellingetRefrigerator beef = CreateRefrigerator("beef", "meat", 25, 5, 7, 22);
    AddItem(repo, beef);
    IntellingetRefrigerator apple = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, apple);
    IntellingetRefrigerator lindt = CreateRefrigerator("lindt", "sweets", 1, 12, 11, 23);
    AddItem(repo, lindt);

    UpdateName(repo, 0, "chicken");
    assert(strcmp(repo->array->elements[0].name, "chicken") == 0);

    UpdateQuantity(repo, 0, 100);
    assert(repo->array->elements[0].quantity == 100);

    DestroyRepo(repo);
}

void TestCopying()
{
    Repository* repo = CreateRepo(1);

    IntellingetRefrigerator pear = CreateRefrigerator("pear", "fruit", 50, 5, 5, 23);
    AddItem(repo, pear);
    IntellingetRefrigerator apple = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, apple);
    IntellingetRefrigerator plum = CreateRefrigerator("plum", "fruit", 50, 5, 5, 23);
    AddItem(repo, plum);

    Repository repoCopy = DuplicateRepo(*repo);
    assert(repoCopy.array->length == repo->array->length);
    assert(repoCopy.array->maxLength == repo->array->maxLength);

    for (size_t i = 0; i < repo->array->length; ++i)
    {
        assert(Equal(repo->array->elements[i], repoCopy.array->elements[i]));
    }

    DestroyRepo(repo);
    DestroyArray(repoCopy.array);
}

void TestGetters()
{
    Repository* repo = CreateRepo(1);

    IntellingetRefrigerator beef = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, beef);
    IntellingetRefrigerator apple = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, apple);
    IntellingetRefrigerator lindt = CreateRefrigerator("apple", "fruit", 50, 5, 5, 23);
    AddItem(repo, lindt);

    assert(GetLength(repo) == 3);
    assert(Equal(GetElemOnPos(repo, 0), beef));
    assert(Equal(GetElemOnPos(repo, 1), apple));
    assert(Equal(GetElemOnPos(repo, 2), lindt));

    IntellingetRefrigerator invalidItem = CreateRefrigerator("Invalid", "Invalid", 0, 0, 0, 0);
    assert(Equal(GetElemOnPos(repo, 100), invalidItem));

    DestroyRepo(repo);
}

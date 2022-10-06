#pragma once
#include <stddef.h>


typedef struct {
	char name[30];
	char category[10];
	double quantity;
	int expday;
	int expmonth;
	int expyear;

}IntellingetRefrigerator;


/// <summary>
/// Constructor for a Refrigerator object
/// </summary>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="quantity">The quantity of the item</param>
/// <param name="expday">The expiration day of the item</param>
/// <param name="expmonth">The expiration month of the item</param>
/// <param name="expyear">The expiration year of the item</param>
/// <returns>The new IntellingetRefrigerator object</returns>
IntellingetRefrigerator CreateRefrigerator(char name[], char category[], double quantity, int expday, int expmonth, int expyear);

/// <summary>
/// Getter for the name of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The name of the item</returns>
char* getName(IntellingetRefrigerator item);

/// <summary>
/// Getter for the category of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The category of the item</returns>
char* getCategory(IntellingetRefrigerator item);

/// <summary>
/// Getter for the quantiy of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The quantity of the item</returns>
double getQuantity(IntellingetRefrigerator item);

/// <summary>
/// Getter for the exp day of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The exp day of the item</returns>
int getExpDay(IntellingetRefrigerator item);

/// <summary>
/// Getter for the exp month of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The exp month of the item</returns>
int getExpMonth(IntellingetRefrigerator item);

/// <summary>
/// Getter for the exp year of an item
/// </summary>
/// <param name="item">An item</param>
/// <returns>The exp year of the item</returns>
int getExpYear(IntellingetRefrigerator item);

/// <summary>
/// Setter for the name of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="name">The new name for the item</param>
void setName(IntellingetRefrigerator* item, char name[]);

/// <summary>
/// Setter for the category of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="category">The new category for the item</param>
void setCategory(IntellingetRefrigerator* item, char category[]);

/// <summary>
/// Setter for the quantity of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="quantity">The new quantity for the item</param>
void setQuantity(IntellingetRefrigerator* item, double quantity);

/// <summary>
/// Setter for the exp day of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="day">The new exp day for the item</param>
void setExpDay(IntellingetRefrigerator* item, int day);

/// <summary>
/// Setter for the exp month of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="month">The new exp month for the item</param>
void setExpMonth(IntellingetRefrigerator* item, int month);

/// <summary>
/// Setter for the exp year of an item
/// </summary>
/// <param name="item">An item to be modified</param>
/// <param name="year">The new exp year for the item</param>
void setExpYear(IntellingetRefrigerator* item, int year);

/// <summary>
/// Turns the given item into a string
/// </summary>
/// <param name="country">An item</param>
/// <returns>A string containing all attributes of sn item</returns>
char* toStr(IntellingetRefrigerator item);

/// <summary>
/// Assigns the values of an item to another
/// </summary>
/// <param name="source">The item to copy from</param>
/// <param name="destinationy">The item to copy to</param>
void Assign(IntellingetRefrigerator source, IntellingetRefrigerator* destination);

/// <summary>
/// Checks if two items are the same name
/// </summary>
/// <param name="firstitem">An item</param>
/// <param name="seconditem">Another item</param>
/// <returns>1 if the items are equal, 0 otherwise</returns>
int Equal(IntellingetRefrigerator first, IntellingetRefrigerator second);

/// <summary>
///	Checks the validity of the attributes of an item
/// </summary>
/// <param name="name">The name of the item</param>
/// <param name="category">The name of the category the item belongs to</param>
/// <param name="quantity">The quantity of the item</param>
/// <param name="expday">The expiration day of the item</param>
/// <param name="expmonth">The expiration month of the item</param>
/// <param name="expyear">The expiration year of the item</param>
/// <returns>1 if the parameters are valid, 0 otherwise</returns>
int ValidParam(char name[], char category[], double quantity, int expday, int expmonth, int expyear);

/// <summary>
///	Checks the validity of the name of an item
/// </summary>
/// <param name="name">The name of the item</param>
/// <returns>1 if the name is valid, 0 otherwise</returns>
int ValidName(char name[]);

/// <summary>
///	Checks the validity of the category of an item
/// </summary>
/// <param name="category">The category of the item</param>
/// <returns>1 if the category is valid, 0 otherwise</returns>
int ValidCategory(char category[]);

/// <summary>
///	Checks the validity of the quantity of an item
/// </summary>
/// <param name="quantity">The quantity of the item</param>
/// <returns>1 if the quantity is valid, 0 otherwise</returns>
int ValidQuantity(double quantity);

/// <summary>
///	Checks the validity of the exp date of an item
/// </summary>
/// <param name="expday">The expiration day of the item</param>
/// <param name="expmonth">The expiration month of the item</param>
/// <param name="expyear">The expiration year of the item</param>
/// <returns>1 if the exp date is valid, 0 otherwise</returns>
int ValidExpDate(int expday, int expmonth, int expyear);

void RunAllTestsRefrigerator();
void TestCreateItemAndGetters();
void TestSetters();
void TestEquality();
void TestAssignment();
void TestToString();
void TestValidation();
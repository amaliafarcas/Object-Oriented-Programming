#pragma once
#include "domain.h"
#include <vector>
#include <string>
#include <iostream>

class Repository
{
public:
	/// <summary>
	/// Default constructor for the repository class
	/// </summary>
	Repository();

	/// <summary>
	/// Destructor for the repository
	/// </summary>
	~Repository();

	/// <summary>
	/// Adds a new movie to the repository
	/// </summary>
	/// <param name="newMovie">The new movie to be added</param>
	virtual void AddElement(const Movie& newMovie);

	/// <summary>
	/// Removes an element from the repo by position
	/// </summary>
	/// <param name="position">The position of the element to be removed</param>
	virtual void RemoveElement(size_t position);

	/// <summary>
	/// Finds a movie in the repo by its name
	/// </summary>
	/// <param name="title">The name of the movie</param>
	/// <returns>The position of the movie</returns>
	virtual size_t FindElementByTitle(std::string title) const;

	/// <summary>
	/// Finds a movie in the repo by its title
	/// </summary>
	/// <param name="title">The name of the movie</param>
	/// <returns>The position of the movie</returns>
	virtual bool FindElementByGenre(std::string title) const;

	/// <summary>
	/// Updates the name of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newTitle">The new name of the movie</param>
	virtual void UpdateElementTitle(size_t position, std::string newTitle);

	/// <summary>
	/// Updates the genre of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newGenre">The new genre of the movie</param>
	virtual void UpdateElementGenre(size_t position, std::string newGenre);

	/// <summary>
	/// Updates the year of release of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newYear">The new year of the movie</param>
	virtual void UpdateElementYear(size_t position, size_t newYear);

	/// <summary>
	/// Updates the number of likes of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newLikes">The new likes of the movie</param>
	virtual void UpdateElementLikes(size_t position, size_t newLikes);

	/// <summary>
	/// Updates the trailer of a movie
	/// </summary>
	/// <param name="position"></param>
	/// <param name="newTrailer"></param>
	virtual void UpdateElementTrailer(size_t position, std::string newTrailer);

	size_t GetSize() const;
	std::vector<Movie> GetArray() const;
	friend std::ostream& operator<<(std::ostream& os, const Repository& repo);
	friend class RepositoryTests;
private:
	std::vector<Movie> elementsArray;
};

class RepositoryTests
{
public:
	//static void TestAll();
	//static void TestConstructorsAndAssignment();
	//static void TestAdd();
	//static void TestRemoveSubscript();
	//static void TestUpdate();
	//static void TestFind();
	//static void TestPrint();
};
#pragma once
#include "domain.h"
#include "DynamicVector.h"
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
	/// Constructor that initializez the repo with a dynamic array of a given size
	/// </summary>
	/// <param name="maxSize">The size of the array</param>
	Repository(size_t maxSize);

	/// <summary>
	/// Copy constructor for the repository
	/// </summary>
	/// <param name="other"></param>
	Repository(const Repository& other);

	/// <summary>
	/// Destructor for the repository
	/// </summary>
	~Repository();

	/// <summary>
	/// Copy assignment operator for the repository
	/// </summary>
	/// <param name="other">The repository to copy the data from</param>
	/// <returns>A repository with the same fields as other</returns>
	Repository& operator=(const Repository& other);

	/// <summary>
	/// Indexing operator for the repository
	/// </summary>
	/// <param name="position">The position of the element</param>
	/// <returns>The element on the given position in the repository</returns>
	Movie& operator[](size_t position);

	/// <summary>
	/// Insertion operator for the repository class
	/// </summary>
	/// <param name="os">The stream object to write to</param>
	/// <param name="repo">The repo to be written</param>
	/// <returns>A stream containing the elements of the repository</returns>
	friend std::ostream& operator<<(std::ostream& os, const Repository& repo);

	/// <summary>
	/// Equality operator for the repository
	/// </summary>
	/// <param name="other">The object to compare with</param>
	/// <returns>True if the repos have the same elements, False otherwise</returns>
	bool operator==(const Repository& other) const;

	/// <summary>
	/// Adds a new movie to the repository
	/// </summary>
	/// <param name="newMovie">The new movie to be added</param>
	void AddElement(const Movie& newMovie);

	/// <summary>
	/// Removes an element from the repo by position
	/// </summary>
	/// <param name="position">The position of the element to be removed</param>
	void RemoveElement(size_t position);

	/// <summary>
	/// Finds a movie in the repo by its name
	/// </summary>
	/// <param name="title">The name of the movie</param>
	/// <returns>The position of the movie</returns>
	size_t FindElementByTitle(std::string title) const;

	/// <summary>
	/// Finds a movie in the repo by its title
	/// </summary>
	/// <param name="title">The name of the movie</param>
	/// <returns>The position of the movie</returns>
	bool FindElementByGenre(std::string title) const;

	/// <summary>
	/// Updates the name of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newTitle">The new name of the movie</param>
	void UpdateElementTitle(size_t position, std::string newTitle);

	/// <summary>
	/// Updates the genre of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newGenre">The new genre of the movie</param>
	void UpdateElementGenre(size_t position, std::string newGenre);

	/// <summary>
	/// Updates the year of release of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newYear">The new year of the movie</param>
	void UpdateElementYear(size_t position, size_t newYear);

	/// <summary>
	/// Updates the number of likes of a movie
	/// </summary>
	/// <param name="position">The position of the movie</param>
	/// <param name="newLikes">The new likes of the movie</param>
	void UpdateElementLikes(size_t position, size_t newLikes);

	/// <summary>
	/// Updates the trailer of a movie
	/// </summary>
	/// <param name="position"></param>
	/// <param name="newTrailer"></param>
	void UpdateElementTrailer(size_t position, std::string newTrailer);

	size_t GetSize() const;
	DynamicVector<Movie> GetArray() const;

	friend class RepositoryTests;
private:
	DynamicVector<Movie>* elementsArray;
};

class RepositoryTests
{
public:
	static void TestAll();
	static void TestConstructorsAndAssignment();
	static void TestAdd();
	static void TestRemoveSubscript();
	static void TestUpdate();
	static void TestFind();
	static void TestPrint();
};
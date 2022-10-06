#pragma once
//#include "repository.h"
#include "FileRepository.h"
#include "validators.h"

class AdminServices
{
public:
	/// <summary>
	/// Constructor for the Services class
	/// </summary>
	/// <param name="repo">The repository on which the services class operates</param>
	AdminServices(Repository& repo);

	/// <summary>
	/// Adds a new movie to the repository
	/// Also performs data validation
	/// </summary>
	/// <param name="title">The title of movie</param>
	/// <param name="genre">The genre of the movie</param>
	/// <param name="year">The year in which the movie was released</param>
	/// <param name="likes">The number of likes of the movie</param>
	/// <param name="trailer">The link for the trailer of the movie</param>
	void AddMovie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer);

	/// <summary>
	/// Removes a movie from the repository
	/// </summary>
	/// <param name="name">The name of the movie which will be removed</param>
	void RemoveMovie(std::string name);

	/// <summary>
	/// Updates the title of a movie from the repository
	/// Performs data validation for the new title
	/// </summary>
	/// <param name="oldTitle">The old title of the movie</param>
	/// <param name="newTitle">The new title of the movie</param>
	void UpdateMovieTitle(std::string oldTitle, std::string newTitle);

	/// <summary>
	/// Updates the genre of a movie from the repository
	/// Performs data validation for the new breed
	/// </summary>
	/// <param name="name">The name of the movie</param>
	/// <param name="newGenre">The new breed of the movie</param>
	void UpdateMovieGenre(std::string name, std::string newGenre);

	/// <summary>
	/// Updates the age of a movie from the repository
	/// Performs data validation for the new age
	/// </summary>
	/// <param name="name">The name of the movie</param>
	/// <param name="newBreed">The new age of the movie</param>
	void UpdateMovieYear(std::string name, size_t newYear);

	/// <summary>
	/// Updates the age of a movie from the repository
	/// Performs data validation for the new age
	/// </summary>
	/// <param name="name">The name of the movie</param>
	/// <param name="newBreed">The new age of the movie</param>
	void UpdateMovieLikes(std::string name, size_t newLikes);

	/// <summary>
	/// Updates the photograph of a movie from the repository
	/// Performs data validation for the new photograph
	/// </summary>
	/// <param name="name">The name of the movie</param>
	/// <param name="newBreed">The new photograph of the movie</param>
	void UpdateMovieTrailer(std::string name, std::string newTrailer);

	/// <summary>
	/// Prints the contents of the repository
	/// </summary>
	Repository GetRepo() const;

	/// <summary>
	/// Adds 10 entries to the repository
	/// </summary>
	void InitializeRepo();

	friend class AdminServicesTests;
private:
	Repository& repository;
};


class AdminServicesTests
{
public:
	static void TestAll();
	static void TestConstructors();
	static void TestAdd();
	static void TestRemove();
	static void TestUpdate();
};
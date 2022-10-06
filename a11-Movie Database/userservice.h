#pragma once
#include "repository.h"
#include "MovieList.h"
#include <vector>

class UserServices
{
private:
	Repository& repo;
	std::vector<Movie> movielist;
	MovieList movies;
	MovieListWriter* writer;
	std::vector<Movie> watchlist;
	size_t index;
	std::string writeMode;
public:
	/// <summary>
	/// The constrcutor for the user service class
	/// </summary>
	/// <param name="repo"></param>
	UserServices(Repository& repo);
	
	/// <summary>
	/// Initializez the current movie list to the list in repo and sets the index to 0
	/// </summary>
	void InitializeMovieList();

	/// <summary>
	/// adds a movie to watch list
	/// </summary>
	/// <param name="movie">the movie to be added</param>
	void AddToWatchList(const Movie& movie);

	/// <summary>
	/// filters the movies in repo by genre
	/// </summary>
	/// <param name="genre">the genre of the movie</param>
	void FilterByGenre(std::string genre);

	/// <summary>
	/// verifies if the genre introduced by the user is valid
	/// </summary>
	/// <param name="genre">the genre introduced by the user</param>
	/// <returns>True if it exists in repo, false otherwise</returns>
	bool IsGenre(std::string genre);

	/// <summary>
	/// moves the index to the next movie in the list
	/// </summary>
	void NextMovie();

	/// <summary>
	/// likes a movie watched by the user
	/// </summary>
	/// <param name="title">the title of the movie to be liked</param>
	void RateWatchedMovie(std::string title);

	/// <summary>
	/// it deletes the movie from watch list and gives the user the posibility to like that movie
	/// </summary>
	/// <param name="title">the title of the movie</param>
	/// <param name="rate">yes/no like</param>
	void WatchMovie(std::string title, bool rate);

	~UserServices();
	void WriteData();

    std::vector<Movie> GetMovieList() const;
	/// Getters
	Movie GetCurrentMovie() const;
	std::vector<Movie> SeeWatchList() const;
	const std::string& GetFileName() const;
	const std::string& GetWriteMode() const;

	void SetWriteMode(const std::string& newMode);

	friend class UserServicesTests;
};

class UserServicesTests
{
public:
	static void TestAll();
	static void TestConstructor();
	static void TestSkippingAndAddingToWatchList();
	static void TestFilteringAndReinitialization();
	static void TestRateMovieandDeteleFromWatchList();
	static void TestGetters();
};
#pragma once
#include <string>
#include <iostream>

class Movie
{
private:
	std::string title;
	std::string genre;
	size_t year;
	size_t likes;
	std::string trailer;

public:
	/// <summary>
	/// Default constructor for the Movie class
	/// </summary>
	Movie();

	/// <summary>
	/// Constructor for the movie class with initializers for all fields
	/// </summary>
	/// <param name="title">The title of movie</param>
	/// <param name="genre">The genre of the movie</param>
	/// <param name="year">The year in which the movie was released</param>
	/// <param name="likes">The number of likes of the movie</param>
	/// <param name="trailer">The link for the trailer of the movie</param>
	Movie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer);
	
	/// <summary>
	/// Destructor for the movie
	/// </summary>
	~Movie();

	/// Getters
	std::string GetTitle() const;
	std::string GetGenre() const;
	size_t GetYear();
	size_t GetLikes() const;
	std::string GetTrailer() const;

	/// Setters
	void SetTitle(std::string title);
	void SetGenre(std::string genre);
	void SetYear(size_t yearofrelease);
	void SetLikes(size_t likes);
	void SetTrailer(std::string trailer);

	/// <summary>
	/// Equality operator for the movie class
	/// </summary>
	/// <param name="other">The movie to compare the current object with</param>
	/// <returns>True if the movies are identical, false otherwise</returns>
	bool operator==(const Movie& other) const;

	/// <summary>
	/// Insertion operator for the movie class
	/// </summary>
	/// <param name="os">The stream object to write the data of the movie to</param>
	/// <param name="dog">The movie whose fields will be written</param>
	/// <returns>A stream object which contains the data of the movie</returns>
	friend std::ostream& operator<<(std::ostream& os, const Movie& m);
	friend class MovieTests;

};

class MovieTests
{
public:
	static void TestAllMovie();
	static void TestConstructorsAndGettersMovie();
	static void TestSettersMovie();
	static void TestEqualityMovie();
	static void TestExtractionOperator();
};
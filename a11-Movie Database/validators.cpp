#include "../headers/validators.h"
#include <regex>

bool Validator::ValidMovieAttributes(std::string title, std::string genre, size_t year, size_t likes, std::string trailer)
{
	return ValidMovieTitle(title) && ValidMovieGenre(genre) && ValidMoviesYear(year) && ValidMoviesLikes(likes) && ValidMovieTrailer(trailer);
}

bool Validator::ValidMovieTitle(std::string title)
{
	return !title.empty();
}

bool Validator::ValidMovieGenre(std::string genre)
{
	return !genre.empty();
}

bool Validator::ValidMoviesYear(size_t year)
{
	return year>1500 && year <=2022;
}

bool Validator::ValidMoviesLikes(size_t likes)
{
	return likes>=0;
}

bool Validator::ValidMovieTrailer(std::string trailer)
{
	return !trailer.empty();
}

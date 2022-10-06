#pragma once
#include "domain.h"

class Validator
{
public:
	static bool ValidMovieAttributes(std::string title, std::string genre, size_t year, size_t likes, std::string trailer);
	static bool ValidMovieTitle(std::string title);
	static bool ValidMovieGenre(std::string genre);
	static bool ValidMoviesYear(size_t year);
	static bool ValidMoviesLikes(size_t likes);
	static bool ValidMovieTrailer(std::string trailer);
};
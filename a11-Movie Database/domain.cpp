#include "../headers/domain.h"
#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

Movie::Movie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer) :
	title { title }, genre { genre }, year { year }, likes { likes }, trailer { trailer }
{
}

Movie::Movie() : title{ "" }, genre{ "" }, year{ 0 }, likes{ 0 }, trailer{ "" }
{
}

Movie::~Movie()
{
}

std::string Movie::GetTitle() const
{
	return this->title;
}

std::string Movie::GetGenre() const
{
	return this->genre;
}

size_t Movie::GetYear() const
{
	return this->year;
}

size_t Movie::GetLikes() const
{
	return this->likes;
}

std::string Movie::GetTrailer() const
{
	return this->trailer;
}

void Movie::SetTitle(std::string title)
{
	this->title = title;
}

void Movie::SetGenre(std::string genre)
{
	this->genre = genre;
}

void Movie::SetYear(size_t yearofrelease)
{
	this->year = yearofrelease;
}

void Movie::SetLikes(size_t likes)
{
	this->likes = likes;
}

void Movie::SetTrailer(std::string trailer)
{
	this->trailer = trailer;
}

bool Movie::operator==(const Movie& other) const
{
	return this->title == other.title;
}

//std::ostream& operator<<(std::ostream& os, const Movie& movie)
//{
//	return os << "Title: " << movie.title << " | Genre: " << movie.genre << " | Year: " << movie.year << " | Likes: " << movie.likes << "\n\tTrailer: " << movie.trailer << "\n";
//}

std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
	return os << movie.title << " " << movie.genre << " " << movie.year << " " << movie.likes << " " << movie.trailer << '\n';
}

std::istream& operator>>(std::istream& is, Movie& movie)
{
	return is >> movie.title >> movie.genre >> movie.year >> movie.likes >> movie.trailer;
}

void MovieTests::TestAllMovie()
{
	TestConstructorsAndGettersMovie();
	TestSettersMovie();
	TestEqualityMovie();
	TestExtractionOperator();
}

void MovieTests::TestConstructorsAndGettersMovie()
{
	Movie m1;
	assert(m1.GetTitle() == "");
	assert(m1.GetGenre() == "");
	assert(m1.GetTrailer() == "");
	assert(m1.GetYear() == 0);
	assert(m1.GetLikes() == 0);

	Movie m2("It", "comedy", 2010, 10, "youtube.com");
	assert(m2.GetTitle() == "It");
	assert(m2.GetGenre() == "comedy");
	assert(m2.GetTrailer() == "youtube.com");
	assert(m2.GetYear() == 2010);
	assert(m2.GetLikes() == 10);
}

void MovieTests::TestSettersMovie()
{
	Movie m;
	m.SetTitle("It");
	m.SetGenre("comedy");
	m.SetTrailer("youtube.com");
	m.SetYear(2010);
	m.SetLikes(10);

	assert(m.GetTitle() == "It");
	assert(m.GetGenre() == "comedy");
	assert(m.GetTrailer() == "youtube.com");
	assert(m.GetYear() == 2010);
	assert(m.GetLikes() == 10);
}

void MovieTests::TestEqualityMovie()
{
	Movie m;
	m.SetTitle("It");
	m.SetGenre("comedy");
	m.SetTrailer("youtube.com");
	m.SetYear(2010);
	m.SetLikes(10);

	Movie n("It", "comedy", 2010, 10, "youtube.com");

	assert(m == n);
}

void MovieTests::TestExtractionOperator()
{
	Movie m;
	m.SetTitle("It");
	m.SetGenre("comedy");
	m.SetTrailer("youtube.com");
	m.SetYear(2010);
	m.SetLikes(10);
	std::stringbuf buffer;
	std::ostream os(&buffer);
	os << m;
	assert(buffer.str() == "Title: It | Genre: comedy | Year: 2010 | Likes: 10\n\tTrailer: youtube.com\n");
}

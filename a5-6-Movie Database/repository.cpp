#include "repository.h"
#include <iostream>
#include <assert.h>
#include <sstream>

Repository::Repository() :
	elementsArray{ nullptr }
{
}

Repository::Repository(size_t maxSize): 
	elementsArray {new DynamicVector<Movie>(maxSize)
}
{
}

Repository::Repository(const Repository& other):
	elementsArray{ new DynamicVector<Movie>(*other.elementsArray) }
{
}

Repository::~Repository()
{
	delete this->elementsArray;
	this->elementsArray = nullptr;
}

Repository& Repository::operator=(const Repository& other)
{
	if (this == &other) return *this;

	if (this->elementsArray == nullptr) this->elementsArray = new DynamicVector<Movie>();
	*this->elementsArray = *other.elementsArray;

	return *this;
}

Movie& Repository::operator[](size_t position)
{
	return (*this->elementsArray)[position];
}

bool Repository::operator==(const Repository& other) const
{
	return *this->elementsArray == *other.elementsArray;
}

void Repository::AddElement(const Movie& newMovie)
{
	this->elementsArray->AddElement(newMovie);
}

void Repository::RemoveElement(size_t position)
{
	this->elementsArray->RemoveElement(position);
}

size_t Repository::FindElementByTitle(std::string name) const
{
	size_t position = -1;
	for (size_t i = 0; i < this->GetSize(); ++i)
		if ((*this->elementsArray)[i].GetTitle() == name)
		{
			position = i;
			break;
		}
	return position;
}

bool Repository::FindElementByGenre(std::string genre) const
{
	size_t found = false;
	for (size_t i = 0; i < this->GetSize(); ++i)
		if ((*this->elementsArray)[i].GetGenre() == genre)
		{
			found = true;
			break;
		}
	return found;
}

void Repository::UpdateElementTitle(size_t position, std::string newTitle)
{
	(*this->elementsArray)[position].SetTitle(newTitle);
}

void Repository::UpdateElementGenre(size_t position, std::string newGenre)
{
	(*this->elementsArray)[position].SetGenre(newGenre);
}

void Repository::UpdateElementYear(size_t position, size_t newYear)
{
	(*this->elementsArray)[position].SetYear(newYear);
}

void Repository::UpdateElementLikes(size_t position, size_t newLikes)
{
	(*this->elementsArray)[position].SetLikes(newLikes);
}

void Repository::UpdateElementTrailer(size_t position, std::string newTrailer)
{
	(*this->elementsArray)[position].SetTrailer(newTrailer);
}

size_t Repository::GetSize() const
{
	return this->elementsArray->GetSize();
}

DynamicVector<Movie> Repository::GetArray() const
{
	return *elementsArray;
}

std::ostream& operator<<(std::ostream& os, const Repository& repo)
{
	return os << *repo.elementsArray;
}

void RepositoryTests::TestAll()
{
	TestConstructorsAndAssignment();
	TestAdd();
	TestRemoveSubscript();
	TestUpdate();
	TestFind();
	TestPrint();
}

void RepositoryTests::TestConstructorsAndAssignment()
{
	Repository repo1;
	assert(repo1.elementsArray == nullptr);

	Repository repo2(10);
	assert(repo2.elementsArray != nullptr);
	assert(repo2.GetSize() == 0);

	repo2.AddElement(Movie("It", "comedy", 2010, 10, "youtube.com"));
	repo1 = repo2;

	assert(*repo1.elementsArray == *repo2.elementsArray);
}

void RepositoryTests::TestAdd()
{
	Repository repo2(10);
	Movie d1("It", "comedy", 2010, 10, "youtube.com");
	Movie d2("It", "comedy", 2010, 10, "youtube.com");
	Movie d3("It", "comedy", 2010, 10, "youtube.com");
	Movie d4("It", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d1);
	repo2.AddElement(d2);
	repo2.AddElement(d3);
	repo2.AddElement(d4);

	assert(repo2[0] == d1);
	assert(repo2[1] == d2);
	assert(repo2[2] == d3);
	assert(repo2[3] == d4);
}

void RepositoryTests::TestRemoveSubscript()
{
	Repository repo2(10);
	Movie d1("It", "comedy", 2010, 10, "youtube.com");
	Movie d2("It", "comedy", 2010, 10, "youtube.com");
	Movie d3("It", "comedy", 2010, 10, "youtube.com");
	Movie d4("It", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d1);
	repo2.AddElement(d2);
	repo2.AddElement(d3);
	repo2.AddElement(d4);

	repo2.RemoveElement(1);

	assert(repo2[0] == d1);
	assert(repo2[1] == d3);
	assert(repo2[2] == d4);
}

void RepositoryTests::TestUpdate()
{
	Repository repo2(10);
	Movie d1("It", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d1);

	repo2.UpdateElementTitle(0, "oo");
	assert(repo2[0].GetTitle() == "oo");

	repo2.UpdateElementGenre(0, "drama");
	assert(repo2[0].GetGenre() == "drama");

	repo2.UpdateElementYear(0, 1500);
	assert(repo2[0].GetYear() == 1500);

	repo2.UpdateElementTrailer(0, "Movies.com");
	assert(repo2[0].GetTrailer() == "Movies.com");
}

void RepositoryTests::TestFind()
{
	Repository repo2(10);
	Movie d1("It", "comedy", 2010, 10, "youtube.com");
	Movie d2("It", "comedy", 2010, 10, "youtube.com");
	Movie d3("It2", "comedy", 2010, 10, "youtube.com");
	Movie d4("It", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d1);
	repo2.AddElement(d2);
	repo2.AddElement(d3);
	repo2.AddElement(d4);

	size_t position = repo2.FindElementByTitle("It2");
	bool found = repo2.FindElementByGenre("comedy");
	assert(position == 2);
	assert(found == true);
}

void RepositoryTests::TestPrint()
{
	Repository repo2(10);
	Movie d1("It", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d1);
	Movie d2("It1", "comedy", 2010, 10, "youtube.com");
	repo2.AddElement(d2);

	std::stringbuf buffer;
	std::ostream os(&buffer);
	os << repo2;
	assert(buffer.str() == "Title: It | Genre: comedy | Year: 2010 | Likes: 10\n\tTrailer: youtube.com\nTitle: It1 | Genre: comedy | Year: 2010 | Likes: 10\n\tTrailer: youtube.com\n\n");
}
#include "../headers/adminservice.h"
#include "../headers/MovieValidator.h"
#include <assert.h>
#include <sstream>
#include "exception"

AdminServices::AdminServices(Repository& repo):
	repository { repo }
{
}

void AdminServices::AddMovie(std::string title, std::string genre, size_t year, size_t likes, std::string trailer)
{
	//if (!Validator::ValidMovieAttributes(title, genre, year, likes, trailer)) throw std::exception("Invalid movie parameters!");
	//try {
		Movie newMovie = Movie(title, genre, year, likes, trailer);
		MovieValidator::validate(newMovie);

		bool found = false;
		for (size_t i = 0; i < this->repository.GetSize() && !found; ++i)
			if (this->repository.GetArray()[i] == newMovie) found = true;

		if (found) throw std::exception();//"A movie with the given title already exists!");
		this->repository.AddElement(newMovie);
	/*}
	catch (ValidationException& e)
	{
		std::cout << e.getMessage() << "\n";
	}*/
}

void AdminServices::RemoveMovie(std::string title)
{
	size_t position = this->repository.FindElementByTitle(title);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.RemoveElement(position);
}

void AdminServices::UpdateMovieTitle(std::string oldTitle, std::string newTitle)
{
	if (!Validator::ValidMovieTitle(newTitle)) throw std::exception();//"Invalid movie title!");
	size_t position = this->repository.FindElementByTitle(oldTitle);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.UpdateElementTitle(position, newTitle);
}

void AdminServices::UpdateMovieGenre(std::string title, std::string newGenre)
{
	if (!Validator::ValidMovieGenre(newGenre)) throw std::exception();//"Invalid movie gerne!");
	size_t position = this->repository.FindElementByTitle(title);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.UpdateElementGenre(position, newGenre);
}

void AdminServices::UpdateMovieYear(std::string title, size_t newYear)
{
	if (!Validator::ValidMoviesYear(newYear)) throw std::exception();//"Invalid movie year of release!");
	size_t position = this->repository.FindElementByTitle(title);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.UpdateElementYear(position, newYear);
}

void AdminServices::UpdateMovieLikes(std::string title, size_t newLikes)
{
	if (!Validator::ValidMoviesLikes(newLikes)) throw std::exception();//"Invalid movie likes!");
	size_t position = this->repository.FindElementByTitle(title);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.UpdateElementLikes(position, newLikes);
}

void AdminServices::UpdateMovieTrailer(std::string title, std::string newTrailer)
{
	if (!Validator::ValidMovieTrailer(newTrailer)) throw std::exception();//"Invalid movie trailer link!");
	size_t position = this->repository.FindElementByTitle(title);

	if (position >= this->repository.GetSize()) throw std::exception();//"Movie not found!");
	this->repository.UpdateElementTrailer(position, newTrailer);
}

Repository AdminServices::GetRepo() const
{
	return this->repository;
}

std::vector<Movie> AdminServices::GetAll()
{
    return this->repository.GetArray();
}

void AdminServices::InitializeRepo()
{
	/*AddMovie("CityLights", "comedy", 1931, 820249, "https://www.youtube.com/watch?v=7vl7F8S4cpQ");
	AddMovie("RearWindow", "thriller", 1954, 578456, "https://www.youtube.com/watch?v=6kCcZCMYw38");
	AddMovie("Casablanca", "drama", 1942, 785565, "https://www.youtube.com/watch?v=BkL9l7qovsE");
	AddMovie("TheGodfather", "crime", 1972, 654269, "https://www.youtube.com/watch?v=sY1S34973zA");
	AddMovie("TheLordoftheRings", "action", 2003, 74685564, "https://www.youtube.com/watch?v=r5X-hFf6Bwo");
	AddMovie("TheDarkKnight", "action", 2008, 98426458, "https://www.youtube.com/watch?v=EXeTwQWrcwY");
	AddMovie("Inception", "action", 2010, 4567515, "https://www.youtube.com/watch?v=YoHD9XEInc0");
	AddMovie("Venom", "action", 2018, 98551555, "https://www.youtube.com/watch?v=u9Mv98Gr5pY");
	AddMovie("RushHour", "comedy", 1998, 82221525, "https://www.youtube.com/watch?v=JMiFsFQcFLE");
	AddMovie("It", "thriller", 2017, 6584455, "https://www.youtube.com/watch?v=7no56Zw1e20");*/
}
//void AdminServicesTests::TestAll()
//{
//	TestConstructors();
//	TestAdd();
//	TestRemove();
//	TestUpdate();
//}
//
//void AdminServicesTests::TestConstructors()
//{
//	Repository repo(20);
//	AdminServices s2(repo);
//	assert(s2.repository.GetSize() == 0);
//
//	assert(s2.GetRepo() == repo);
//}
//
//void AdminServicesTests::TestAdd()
//{
//	Repository repo(20);
//
//	AdminServices s2(repo);
//	s2.AddMovie("It", "comedy", 2010, 10, "youtube.com");
//
//	assert(s2.repository[0].GetTitle() == "It");
//	assert(s2.repository[0].GetGenre() == "comedy");
//	assert(s2.repository[0].GetYear() == 2010);
//	assert(s2.repository[0].GetLikes() == 10);
//	assert(s2.repository[0].GetTrailer() == "youtube.com");
//
//	s2.AddMovie("Movie", "drama", 2000, 190, "youtube.com");
//
//	assert(s2.repository[1].GetTitle() == "Movie");
//	assert(s2.repository[1].GetGenre() == "drama");
//	assert(s2.repository[1].GetYear() == 2000);
//	assert(s2.repository[1].GetLikes() == 190);
//	assert(s2.repository[1].GetTrailer() == "youtube.com");
//}
//
//void AdminServicesTests::TestRemove()
//{
//	Repository repo(20);
//
//	AdminServices s2(repo);
//	
//
//	s2.AddMovie("It", "comedy", 2010, 10, "youtube.com");
//	s2.AddMovie("Movie", "drama", 2000, 190, "youtube.com");
//
//	s2.RemoveMovie("It");
//
//	assert(s2.repository[0].GetTitle() == "Movie");
//	assert(s2.repository[0].GetGenre() == "drama");
//	assert(s2.repository[0].GetYear() == 2000);
//	assert(s2.repository[0].GetLikes() == 190);
//	assert(s2.repository[0].GetTrailer() == "youtube.com");
//}
//
//void AdminServicesTests::TestUpdate()
//{
//	Repository repo(20);
//
//	AdminServices s2(repo);
//	s2.AddMovie("It", "comedy", 2010, 10, "youtube.com");
//
//	assert(s2.repository[0].GetTitle() == "It");
//	assert(s2.repository[0].GetGenre() == "comedy");
//	assert(s2.repository[0].GetYear() == 2010);
//	assert(s2.repository[0].GetLikes() == 10);
//	assert(s2.repository[0].GetTrailer() == "youtube.com");
//
//	s2.UpdateMovieYear("It", 2000);
//	assert(s2.repository[0].GetYear() == 2000);
//	s2.UpdateMovieLikes("It", 2000);
//	assert(s2.repository[0].GetLikes() == 2000);
//	s2.UpdateMovieTitle("It", "Ted");
//	assert(s2.repository[0].GetTitle() == "Ted");
//	s2.UpdateMovieGenre("Ted", "action");
//	assert(s2.repository[0].GetGenre() == "action");
//	s2.UpdateMovieTrailer("Ted", "Movies.ro");
//	assert(s2.repository[0].GetTrailer() == "Movies.ro");
//}
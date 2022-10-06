#include "userservice.h"
#include <assert.h>
#include <sstream>

UserServices::UserServices(Repository& repo):
	repo{ repo },
	movielist{ repo.GetArray() },
	watchlist{ DynamicVector<Movie>(1) }, index{ 0 }
{
}

void UserServices::InitializeMovieList()
{
	if (movielist == repo.GetArray())
		return;
	movielist = repo.GetArray();
	index = 0;
}

void UserServices::AddToWatchList(const Movie& movie)
{
	bool found = false;
	for (int i = 0; i < watchlist.GetSize(); i++)
		if (watchlist[i] == movie)
			found = true;
	if (found == true)
		throw std::exception("Movie alreday in watch list");
	else
		watchlist.AddElement(movie);
	NextMovie();
}

DynamicVector<Movie> UserServices::SeeWatchList() const
{
	return watchlist;
}

void UserServices::FilterByGenre(std::string genre)
{
	for (int i = 0; i < movielist.GetSize(); i++)
		if (movielist[i].GetGenre() != genre)
		{
			movielist.RemoveElement(i);
			i--;
		}
	index = 0;
}

bool UserServices::IsGenre(std::string genre)
{
	return repo.FindElementByGenre(genre);
}

void UserServices::NextMovie()
{
	if (index == movielist.GetSize() - 1)
	{
		index = 0;
		return;
	}
	index++;
}

void UserServices::RateWatchedMovie(std::string title)
{
	size_t i = repo.FindElementByTitle(title);
	if (i >= 0)
		repo.UpdateElementLikes(i, repo[i].GetLikes() + 1);
	else
		throw std::exception("No movie with such title");
}

void UserServices::WatchMovie(std::string title, bool rate)
{
	bool found = false;
	for (int i = 0; i < watchlist.GetSize(); i++)
		if (watchlist[i].GetTitle() == title)
		{
			watchlist.RemoveElement(i);
			found = true;
			break;
		}
	if (!found)
		throw std::exception("No such movie in your watch list");
	if (rate)
			RateWatchedMovie(title);
}

Movie& UserServices::GetCurrentMovie() const
{
	return movielist[index];
}

void UserServicesTests::TestAll()
{
	TestConstructor();
	TestSkippingAndAddingToWatchList();
	TestFilteringAndReinitialization();
	TestRateMovieandDeteleFromWatchList(); 
	TestGetters();
}

void UserServicesTests::TestConstructor()
{
	Repository repo(20);
	repo.AddElement(Movie("City Lights", "comedy", 1931, 820249, "https://www.youtube.com/watch?v=7vl7F8S4cpQ"));
	repo.AddElement(Movie("Rear Window", "thriller", 1954, 578456, "https://www.youtube.com/watch?v=6kCcZCMYw38"));
	repo.AddElement(Movie("Casablanca", "drama", 1942, 785565, "https://google.com"));
	repo.AddElement(Movie("The Godfather", "crime", 1972, 654269, "https://google.com"));
	repo.AddElement(Movie("The Lord of the Rings", "action", 2003, 74685564, "https://google.com"));
	repo.AddElement(Movie("The Dark Knight", "action", 2008, 98426458, "photo.ro"));
	repo.AddElement(Movie("Inception", "action", 2010, 4567515, "https://Movies.com/photos/1"));
	repo.AddElement(Movie("Venom", "action", 2018, 98551555, "https://Movies.com/photos/2"));
	repo.AddElement(Movie("Rush Hour", "comedy", 1998, 82221525, "https://Movies.com/photos/3"));
	repo.AddElement(Movie("It", "thrailler", 2017, 6584455, "https://Movies.com/photos/4"));
	UserServices s1(repo);
	assert(s1.movielist == repo.GetArray());
	assert(s1.index == 0);
	assert(s1.watchlist.GetSize() == 0);
}

void UserServicesTests::TestSkippingAndAddingToWatchList()
{
	Repository repo(20);
	repo.AddElement(Movie("Rush Hour", "comdey", 1998, 82221525, "https://Movies.com/photos/3"));
	repo.AddElement(Movie("It", "thrailler", 2017, 6584455, "https://Movies.com/photos/4"));
	UserServices s1(repo);

	s1.AddToWatchList(s1.repo[s1.index]);
	assert(s1.watchlist.GetSize() == 1);
	assert(s1.watchlist[0] == s1.repo[0]);
	assert(s1.index == 1);

	s1.NextMovie();
	assert(s1.index == 0);
}

void UserServicesTests::TestFilteringAndReinitialization()
{
	Repository repo(20);
	repo.AddElement(Movie("City Lights", "comedy", 1931, 820249, "https://www.youtube.com/watch?v=7vl7F8S4cpQ"));
	repo.AddElement(Movie("Rear Window", "thriller", 1954, 578456, "https://www.youtube.com/watch?v=6kCcZCMYw38"));
	repo.AddElement(Movie("Casablanca", "drama", 1942, 785565, "https://google.com"));
	repo.AddElement(Movie("The Godfather", "crime", 1972, 654269, "https://google.com"));
	repo.AddElement(Movie("The Lord of the Rings", "action", 2003, 74685564, "https://google.com"));
	repo.AddElement(Movie("The Dark Knight", "action", 2008, 98426458, "photo.ro"));
	repo.AddElement(Movie("Inception", "action", 2010, 4567515, "https://Movies.com/photos/1"));
	repo.AddElement(Movie("Venom", "action", 2018, 98551555, "https://Movies.com/photos/2"));
	repo.AddElement(Movie("Rush Hour", "comedy", 1998, 82221525, "https://Movies.com/photos/3"));
	repo.AddElement(Movie("It", "thrailler", 2017, 6584455, "https://Movies.com/photos/4"));
	UserServices s1(repo);

	s1.FilterByGenre("comedy");
	assert(s1.movielist.GetSize() == 2);
	assert(s1.movielist[0] == Movie("City Lights", "comedy", 1931, 820249, "https://www.youtube.com/watch?v=7vl7F8S4cpQ"));
	assert(s1.movielist[1] == Movie("Rush Hour", "comedy", 1998, 82221525, "https://Movies.com/photos/3"));
	bool found = s1.IsGenre("comedy");
	assert(found == true);

	s1.InitializeMovieList();
	assert(s1.movielist.GetSize() == 10);
	assert(s1.index == 0);

	s1.FilterByGenre("action");
	assert(s1.movielist.GetSize() == 4);

	s1.InitializeMovieList();
	assert(s1.movielist.GetSize() == 10);
	assert(s1.index == 0);

	s1.InitializeMovieList();
	assert(s1.movielist.GetSize() == 10);
	assert(s1.index == 0);
}

void UserServicesTests::TestRateMovieandDeteleFromWatchList()
{
	Repository repo(20);
	repo.AddElement(Movie("Rush Hour", "comdey", 1998, 82221525, "https://Movies.com/photos/3"));
	repo.AddElement(Movie("It", "thrailler", 2017, 6584455, "https://Movies.com/photos/4"));
	UserServices s1(repo);

	s1.AddToWatchList(s1.repo[1]);
	s1.AddToWatchList(s1.repo[0]);
	assert(s1.watchlist.GetSize()==2);

	s1.WatchMovie("It", true);
	assert(s1.watchlist.GetSize() == 1);
	
	assert(s1.repo[1].GetLikes() == 6584456);
	try
	{
		s1.AddToWatchList(s1.repo[0]);
		s1.WatchMovie("It", true);
	}
	catch (std::exception& ex)
	{
		//assert(true);
	}

}

void UserServicesTests::TestGetters()
{
	Repository repo(20);
	repo.AddElement(Movie("Rush Hour", "comdey", 1998, 82221525, "https://Movies.com/photos/3"));
	repo.AddElement(Movie("It", "thrailler", 2017, 6584455, "https://Movies.com/photos/4"));
	UserServices s1(repo);

	s1.AddToWatchList(s1.repo[s1.index]);

	s1.NextMovie();

	assert(s1.SeeWatchList() == s1.watchlist);
	assert(s1.GetCurrentMovie() == Movie("Rush Hour", "comdey", 1998, 82221525, "https://Movies.com/photos/3"));
	try
	{
		s1.AddToWatchList(s1.repo[s1.index]);
		//assert(false);
	}
	catch (std::exception& ex)
	{
		assert(true);
	}
}

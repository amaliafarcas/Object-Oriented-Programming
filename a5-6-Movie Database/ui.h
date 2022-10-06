#pragma once
#include "adminservice.h"
#include "userservice.h"

class Console
{
public:
	Console(AdminServices& adminServices, UserServices& userservices);

	void SelectMode();
	void MainLoopUser();
	void MainLoopAdministrator();

	void AddMovie();
	void RemoveMovie();
	void UpdateMovie();
	void UpdateMovieTitle(std::string oldTitle, std::string newTitle);
	void UpdateMovieGenre(std::string title, std::string newGenre);
	void UpdateMovieYear(std::string title, size_t newYear);
	void UpdateMovieLikes(std::string title, size_t newLikes);
	void UpdateMovieTrailer(std::string title, std::string newTrailer);
	void PrintAllMovies();

	void WatchListNoFilter();
	void WatchListFilter();
	void PrintWatchList();
	void AddMovieToWatchList();
	void DoNotAddMovieToWatchList();
	void FilterByGenre();
	void UserInitializeMovieList();
	void UserWatchMovie();

	void PrintAdminMenu();
	void PrintUserMenu();
private:
	AdminServices adminServices;
	UserServices userServices;
};

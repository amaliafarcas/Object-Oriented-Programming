#include "ui.h"
#include <iostream>

Console::Console(AdminServices& adminServices, UserServices& userservices):
	adminServices{ adminServices }, userServices { userservices }
{
	adminServices.InitializeRepo();
}

void Console::Start()
{
	SelectWriteMode();
	SelectMode();
}

void Console::SelectWriteMode()
{
	std::cout << "Please select how the data will be saved: \n";
	std::cout << "1. CSV\n";
	std::cout << "2. HTML\n";

	std::string mode;
	std::cin >> mode;

	if (mode.size() != 1)
	{
		std::cout << "Invalid mode!\n";
		exit(1);
	}

	switch (mode[0])
	{
	case '1':
	{
		userServices.SetWriteMode("CSV");
		return;
	}
	case '2':
	{
		userServices.SetWriteMode("HTML");
		return;
	}
	default:
	{
		std::cout << "Invalid mode!\n";
		exit(1);
	}
	}
}

void Console::SelectMode()
{
	bool done = false;

	while (!done)
	{
		std::cout << "Open application in:\n";
		std::cout << "1.Administrator mode\n";
		std::cout << "2.User mode\n";
		std::string mode;
		std::cin >> mode;
		if (mode.size() != 1)
		{
			std::cout << "Invalid command!\n";
			return;
		}

		switch (mode[0])
		{
		case '1':
		{
			MainLoopAdministrator();
			break;
		}
		case '2':
		{
			MainLoopUser();
			break;
		}
		default:
		{
			std::cout << "Invalid command!\n";
			done = true;
			break;
		}
		}
	}
}

void Console::MainLoopUser()
{
	std::string command;
	bool done = false;

	while (!done)
	{
		PrintUserMenu();
		std::cout << "Choose an option: ";
		std::cin >> command;
		if (command.size() != 1)
			std::cout << "Invalid command!\n";
		else
		{
			try
			{ 
				switch (command[0])
				{
				case '1':
				{
					WatchListNoFilter();
					break;
				}
				case '2':
				{
					WatchListFilter();
					break;
				}
				case '3':
				{
					PrintWatchList();
					break;
				}
				case '4':
				{
					UserWatchMovie();
					break;
				}
				case '5':
				{
					done = true;
					break;
				}
				default:
				{
					std::cout << "Invalid command!\n";
					break;
				}
				}

			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
	}
}

void Console::MainLoopAdministrator()
{
	std::string command;
	bool done = false;


	while (!done)
	{
		PrintAdminMenu();
		std::cout << "Command:\n";
		std::cin >> command;
		if (command.size() != 1)
			std::cout << "Invalid command!\n";

		else
		{
			try
			{
				switch (command[0])
				{
				case '1':
				{
					AddMovie();
					break;
				}
				case '2':
				{
					RemoveMovie();
					break;
				}
				case '3':
				{
					UpdateMovie();
					break;
				}
				case '4':
				{
					PrintAllMovies();
					break;
				}
				case '5':
				{
					done = true;
					break;
				}
				default:
				{
					std::cout << "Invalid command!\n";
					break;
				}
				}
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << '\n';
			}

		}
	}
}

void Console::AddMovie()
{
	std::string name, genre, trailer;
	size_t year, likes;
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Genre: ";
	std::cin >> genre;
	std::cout << "Year of release: ";
	std::cin >> year;
	std::cout << "Number of likes: ";
	std::cin >> likes;
	std::cout << "Trailer link: ";
	std::cin >> trailer;

	this->adminServices.AddMovie(name, genre, year, likes, trailer);
}

void Console::RemoveMovie()
{
	std::string title;
	std::cout << "Title of the movie you wish to remove: ";
	std::cin >> title;

	this->adminServices.RemoveMovie(title);
}

void Console::UpdateMovie()
{
	std::string title;
	std::cout << "Title of the movie you wish to update\n";
	std::cin >> title;
	std::cout << "What would you like to modify?\n"
		<< "1. name | 2. genre | 3. year | 4. likes | 5. trailer link\n";

	std::string updateAttribute;
	std::cin >> updateAttribute;

	if (updateAttribute.size() != 1)
	{
		std::cout << "Invalid command!\n";
		return;
	}

	switch (updateAttribute[0])
	{
	case '1':
	{
		std::string newTitle;
		std::cout << "Please input the new title\n";
		std::cin >> newTitle;
		UpdateMovieTitle(title, newTitle);
		break;
	}
	case '2':
	{
		std::string newGenre;
		std::cout << "Please input the new genre\n";
		std::cin >> newGenre;
		UpdateMovieGenre(title, newGenre);
		break;
	}
	case '3':
	{
		size_t newYear;
		std::cout << "Please input the new year\n";
		std::cin >> newYear;
		UpdateMovieYear(title, newYear);
		break;
	}
	case '4':
	{
		size_t newLikes;
		std::cout << "Please input the new likes\n";
		std::cin >> newLikes;
		UpdateMovieLikes(title, newLikes);
		break;
	}
	case '5':
	{
		std::string newTrailer;
		std::cout << "Please input the new trailer link\n";
		std::cin >> newTrailer;
		UpdateMovieTrailer(title, newTrailer);
		break;
	}
	default:
	{
		std::cout << "Invalid attribute!\n";
		break;
	}
	}
}

void Console::UpdateMovieTitle(std::string oldTitle, std::string newTitle)
{
	this->adminServices.UpdateMovieTitle(oldTitle, newTitle);
}

void Console::UpdateMovieGenre(std::string title, std::string newGenre)
{
	this->adminServices.UpdateMovieGenre(title, newGenre);
}

void Console::UpdateMovieYear(std::string title, size_t newYear)
{
	this->adminServices.UpdateMovieYear(title, newYear);
}

void Console::UpdateMovieLikes(std::string title, size_t newLikes)
{
	this->adminServices.UpdateMovieLikes(title, newLikes);
}

void Console::UpdateMovieTrailer(std::string title, std::string newTrailer)
{
	this->adminServices.UpdateMovieTrailer(title, newTrailer);
}

void Console::PrintAllMovies()
{
	std::cout<<adminServices.GetRepo();
}

void Console::WatchListNoFilter()
{
	std::cout << "\t1. Add to watch list\n";
	std::cout << "\t2. Next movie\n";
	std::cout << "\t3. Exit\n";

	bool exit = false;
	UserInitializeMovieList();

	while (!exit)
	{
		std::cout << userServices.GetCurrentMovie();

		//std::string command_link = "start " + userServices.GetCurrentMovie().GetTrailer();
		//system(command_link.c_str());

		std::cout << "\n\tCommand: ";
		int command = 0;
		while (command >= 4 || 0 >= command)
		{
			std::cin >> command;
			if (command >= 4 || 0 >= command)
				std::cout << "Invalid command\n";
		}
		if (command == 1)
			AddMovieToWatchList();
		if (command == 2)
			DoNotAddMovieToWatchList();
		if (command == 3)
			exit = true;
	}
}

void Console::WatchListFilter()
{
	std::cout << "\t1. Add to watch list\n";
	std::cout << "\t2. Next movie\n";
	std::cout << "\t3. Exit\n";


	bool exit = false;
	UserInitializeMovieList();
	FilterByGenre();

	while (!exit)
	{
		std::cout << userServices.GetCurrentMovie();
		std::cout << "\n\tCommand: ";
		int command = 0;
		while (command >= 4 || 0 >= command)
		{
			std::cin >> command;
			if (command >= 4 || 0 >= command)
				std::cout << "Invalid command\n";
		}
		if (command == 1)
			AddMovieToWatchList();
		if (command == 2)
			DoNotAddMovieToWatchList();
		if (command == 3)
			exit = true;
	}
}

void Console::PrintWatchList()
{
	//std::vector<Movie> list = userServices.SeeWatchList();
	//if (list.size() == 0)
	//	std::cout << "No movies in watch list";
	//else
	//	for (int i = 1; i < list.size(); ++i)
	//		std::cout << list[i];

	if (userServices.GetWriteMode() == "CSV")
	{
		userServices.WriteData();

		std::string command = "notepad " + userServices.GetFileName();

		system("D:");
		system("cd Ama\\ubb\\year1\\sem2\\oop\\a9-912-farcas-amaliamaria - Copy\\moviedatabase");
		system(command.c_str());
	}
	else
	{
		userServices.WriteData();

		system("D:");
		system("cd Ama\\ubb\\year1\\sem2\\oop\\a9-912-farcas-amaliamaria - Copy\\moviedatabase");
		system(userServices.GetFileName().c_str());
	}
}

void Console::AddMovieToWatchList()
{
	userServices.AddToWatchList(userServices.GetCurrentMovie());
}

void Console::DoNotAddMovieToWatchList()
{
	userServices.NextMovie();
}

void Console::FilterByGenre()
{
	bool found = false;

	while (!found)
	{
		std::string genre;
		std::cout << "Choose genre: ";
		std::cin >> genre;
		found = userServices.IsGenre(genre);
		if (!found)
			std::cout << "No movie with this genre!\n";
		else
			userServices.FilterByGenre(genre);
	}
}

void Console::UserInitializeMovieList()
{
	userServices.InitializeMovieList();
}

void Console::UserWatchMovie()
{
	std::cout << "Title of the movie you watched: ";
	std::string title;
	std::cin.ignore(1000, '\n');
	std::getline(std::cin, title);

	std::cout << "Do you want to rate this movie? (yes/no)";
	std::string rate;
	std::cin >> rate;

	bool yes = false;
	if (rate == "yes" || rate == "y")
		yes = true;
		

	userServices.WatchMovie(title, yes);
}

void Console::PrintAdminMenu()
{
	std::cout << "\n1.Add a new movie\n";
	std::cout << "2.Remove a movie by title\n";
	std::cout << "3.Update an existing movie\n";
	std::cout << "4.Print all available movies\n";
	std::cout << "5.Exit\n\n";
}

void Console::PrintUserMenu()
{
	std::cout << "\n1. See all movies\n";
	std::cout << "2. Filter by genre\n";
	std::cout << "3. See watch list\n";
	std::cout << "4. Mark movie as watched and rate it\n";
	std::cout << "5. Exit\n\n";
}

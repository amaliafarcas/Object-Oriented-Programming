#include "../headers/FileRepository.h"
#include <fstream>


FileRepository::FileRepository(const std::string& path, bool initialize) :
	Repository{ Repository() },
	filePath{ path },
	initialize{ initialize }
{
	ReadData();
}

void FileRepository::ReadData()
{
	std::ifstream inputFile;
	inputFile.open(filePath, std::ios::in);
	Movie next;
	while (inputFile >> next)
	{
		Repository::AddElement(next);
	}
	inputFile.close();
}

void FileRepository::WriteData()
{
	std::ofstream outputFile;
	outputFile.open(filePath, std::ios::out);

	for (const Movie& d : Repository::GetArray())
		outputFile << d;

	outputFile.close();
}

void FileRepository::AddElement(const Movie& newDog)
{
	Repository::AddElement(newDog);
	WriteData();
}

void FileRepository::RemoveElement(size_t position)
{
	Repository::RemoveElement(position);
	WriteData();
}

void FileRepository::UpdateElementTitle(size_t position, std::string newTitle)
{
	Repository::UpdateElementTitle(position, newTitle);
	WriteData();
}

void FileRepository::UpdateElementGenre(size_t position, std::string newTitle)
{
	Repository::UpdateElementGenre(position, newTitle);
	WriteData();
}

void FileRepository::UpdateElementYear(size_t position, size_t newYear)
{
	Repository::UpdateElementYear(position, newYear);
	WriteData();
}

void FileRepository::UpdateElementLikes(size_t position, size_t newLikes)
{
	Repository::UpdateElementLikes(position, newLikes);
	WriteData();
}


void FileRepository::UpdateElementTrailer(size_t position, std::string newTrailer)
{
	Repository::UpdateElementTrailer(position, newTrailer);
	WriteData();
}

bool FileRepository::IsInitializable() const
{
	return initialize;
}


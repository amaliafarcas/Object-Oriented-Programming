#pragma once
#include "Repository.h"

class FileRepository :
    public Repository
{
public:
    FileRepository(const std::string& path, bool initialize = false);

    void AddElement(const Movie& newMovie) override;
    void RemoveElement(size_t position) override;

    void UpdateElementTitle(size_t position, std::string newName) override;
    void UpdateElementGenre(size_t position, std::string newGenre) override;
    void UpdateElementYear(size_t position, size_t newYear) override;
    void UpdateElementLikes(size_t position, size_t newLikes) override;
    void UpdateElementTrailer(size_t position, std::string newTrailer) override;

    bool IsInitializable() const;
protected:
    std::string filePath;
    bool initialize;
private:
    void ReadData();
    void WriteData();
};

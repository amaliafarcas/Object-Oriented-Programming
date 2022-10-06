#ifndef QUIZZ_FILEREPO_H
#define QUIZZ_FILEREPO_H


#pragma once

#include "Participant.h"
#include "presenter.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

template<typename TElem>
class FileRepository
{
public:
    FileRepository(std::string& filePath);
    ~FileRepository();

    void addElement(TElem& elem);
    void deleteElement(TElem& elem);
    std::vector<TElem> getAll();
    int getSize();
    void update(TElem& elem);

private:
    std::vector<TElem> entities;
    std::string filePath;

    void writeToFile();
    void readFromFile();
};

template<typename TElem>
inline FileRepository<TElem>::FileRepository(std::string& filePath) :
        filePath{ filePath }
{
    this->readFromFile();
}

template<typename TElem>
inline FileRepository<TElem>::~FileRepository()
{
}

template<typename TElem>
inline void FileRepository<TElem>::addElement(TElem& elem)
{
    this->entities.push_back(elem);
    this->writeToFile();
}

template<typename TElem>
inline void FileRepository<TElem>::deleteElement(TElem& elem)
{
    auto find = std::find(this->entities.begin(), this->entities.end(), elem);
    if (find != this->entities.end())
        this->entities.erase(find);
}

template<typename TElem>
inline std::vector<TElem> FileRepository<TElem>::getAll()
{
    return this->entities;
}

template<typename TElem>
inline int FileRepository<TElem>::getSize()
{
    return this->entities.size();
}

template<typename TElem>
inline void FileRepository<TElem>::update(TElem& elem)
{
    auto found = std::find(this->entities.begin(), this->entities.end(), elem);

    if (found != this->entities.end())
    {
        this->entities.erase(found);
        this->entities.push_back(elem);
    }
}

template<typename TElem>
inline void FileRepository<TElem>::writeToFile()
{
    std::ofstream outputFile;
    outputFile.open(this->filePath, std::ios::out);

    for (auto elem : this->entities)
        outputFile << elem;

    outputFile.close();
}

template<typename TElem>
inline void FileRepository<TElem>::readFromFile()
{
    std::ifstream inputFile;
    inputFile.open(this->filePath, std::ios::in);

    TElem currentEntity;
    while (inputFile >> currentEntity)
        this->entities.push_back(currentEntity);

    inputFile.close();
}


#endif //QUIZZ_FILEREPO_H

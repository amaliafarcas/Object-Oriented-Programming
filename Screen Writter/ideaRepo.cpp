//
// Created by Ama on 7/2/2022.
//

#include "ideaRepo.h"
#include "fstream"
#include "algorithm"

IdeaRepo::IdeaRepo(std::string ideapath):ideaPath{ideapath} {
ReadData();
}

void IdeaRepo::AddIdea(const Idea &is) {
    ideas.push_back(is);
    WriteData();
}

void IdeaRepo::RemoveIdea(Idea is) {
    auto find = std::find(this->ideas.begin(), this->ideas.end(), is);
    if (find != this->ideas.end())
    {
        ideas.erase(find);
        WriteData();
    }
}

std::vector<Idea> IdeaRepo::GetIdeas() {
    return ideas;
}

void IdeaRepo::ReadData() {
    std::ifstream inputFile;
    inputFile.open(ideaPath, std::ios::in);
    Idea next;
    while (inputFile >> next)
    {
        ideas.push_back(next);
    }
    inputFile.close();
}

void IdeaRepo::WriteData() {
    std::ofstream outputFile;
    outputFile.open(ideaPath, std::ios::out);
    for (const Idea& d : ideas)
        outputFile << d;
    outputFile.close();
}

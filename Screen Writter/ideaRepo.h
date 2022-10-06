//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_IDEAREPO_H
#define SCREENWRITTER_IDEAREPO_H

#pragma once
//#include "repository.h"
#include "idea.h"
#include "screenWriter.h"
#include "vector"

class IdeaRepo {

public:
    IdeaRepo(std::string ideapath);
    ~IdeaRepo()=default;
    void AddIdea(const Idea& is);
    void RemoveIdea(Idea is);

    std::vector<Idea> GetIdeas();
    //std::vector<User> GetWriters();
protected:
    std::string writerPath;
    std::string ideaPath;
    //bool initialize;
private:
    void ReadData();
    void WriteData();
    std::vector<Idea> ideas;
    //std::vector<ScreenWriter> writers;
};



#endif //SCREENWRITTER_IDEAREPO_H

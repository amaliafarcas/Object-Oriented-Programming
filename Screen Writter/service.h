//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_SERVICE_H
#define SCREENWRITTER_SERVICE_H
#pragma once
#include "ideaRepo.h"
#include "iostream"
#include "Observer.h"
class Service : public Subject{
private:
    IdeaRepo* repo;
public:
    Service(IdeaRepo* repo) : repo{repo} {}
    void addIdea(std::string name, std::string status, std::string creator, int act);
    std::vector<Idea> GetAll();
    ~Service() = default;
};


#endif //SCREENWRITTER_SERVICE_H

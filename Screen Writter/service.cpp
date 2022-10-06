//
// Created by Ama on 7/2/2022.
//

#include "service.h"

void Service::addIdea(std::string name, std::string status, std::string creator, int act) {
    repo->AddIdea(Idea(name, status, creator, act));
    this->notify();
}

std::vector<Idea> Service::GetAll() {
    return repo->GetIdeas();
}

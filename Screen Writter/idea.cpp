//
// Created by Ama on 7/2/2022.
//

#include "idea.h"

Idea::Idea() : name{""}, status{""}, creator{""}, act{0}{
}

Idea::Idea(std::string name, std::string status, std::string creator, int act) :
name{name }, status{status}, creator{creator}, act{act}{
}

Idea::~Idea() {
}

std::string Idea::getName() {
    return name;
}

std::string Idea::getStatus() {
    return status;
}

std::string Idea::getCreator() {
    return creator;
}

int Idea::getAct() {
    return act;
}

std::ostream &operator<<(std::ostream &os, const Idea &idea) {
    return os<<idea.name<<" "<<idea.status<<" "<<idea.creator<<" "<<idea.act<<"\n";
}

std::istream &operator>>(std::istream &is, Idea &idea) {
    return is>>idea.name>>idea.status>>idea.creator>>idea.act;
}

bool Idea::operator==(const Idea &other) const {
    return other.name==name;
}

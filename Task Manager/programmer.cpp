//
// Created by Ama on 6/30/2022.
//

#include "programmer.h"


Programmer::Programmer() :
        name{""}, id{0}{
}

Programmer::Programmer(std::string name, int id) :
        name{name}, id{id}
{
}

Programmer::~Programmer() {
}

std::istream &operator>>(std::istream &is, Programmer &p) {
    is>>p.name>>p.id;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Programmer &p) {
    os<<p.name<<" "<<p.id;
    return os;
}

int Programmer::getId() {
    return this->id;
}

std::string Programmer::getName() {
    return this->name;
}

bool Programmer::operator==(const Programmer &other) const {
    return this->id == other.id;
}
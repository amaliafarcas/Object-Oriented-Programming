//
// Created by Ama on 6/30/2022.
//

#include "task.h"


Task::Task() :
        description{""}, status{""}, idprog{0000}
{
}

Task::Task(std::string descritpion, std::string status, int idprog) :
        description{descritpion}, status{status}, idprog{idprog}
{
}

Task::~Task() {
}

int Task::getIdProg() {
    return this->idprog;
}

std::string Task::getDescription() {
    return this->description;
}

std::string Task::getStatus() {
    return this->status;
}

std::istream &operator>>(std::istream &is, Task &p) {
    is>>p.description>>p.status>>p.idprog;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Task &p) {
    os<<p.description<<" "<<p.status<<" "<<p.idprog<<"\n";
    return os;
}

bool Task::operator==(const Task &other) const {
    return this->idprog == other.idprog;
}

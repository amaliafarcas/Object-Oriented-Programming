//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_TASK_H
#define TASKMANAGER___COPY_TASK_H
#pragma once
#include "iostream"

class Task {
public:
    Task();
    Task(std::string descritpion, std::string status, int id);
    ~Task();

    int getIdProg();
    std::string getDescription();
    std::string getStatus();

    friend std::istream& operator>>(std::istream& is, Task& p);
    friend std::ostream& operator<<(std::ostream& os, const Task& p);
    bool operator==(const Task& other) const;

private:
    std::string description;
    std::string status;
    int idprog;
};


#endif //TASKMANAGER___COPY_TASK_H

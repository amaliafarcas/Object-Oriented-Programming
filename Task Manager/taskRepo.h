//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_TASKREPO_H
#define TASKMANAGER___COPY_TASKREPO_H
#pragma once
#include "task.h"
#include "programmer.h"
#include <vector>

class TaskRepo {

public:
    TaskRepo(std::string taskpath);
    ~TaskRepo()=default;
    void AddTask(const Task& ts);
    void DeleteTask(Task ts);
    //void UpdateTask(Task old, Task newts);

    //bool IsInitializable() const;

    std::vector<Task> GetTasks();
    std::vector<Programmer> GetProgrammers();
protected:
    std::string taskPath;
    //bool initialize;
private:
    void ReadData();
    void WriteData();
    void loadProgrammers();

    std::vector<Task> tasks;
    std::vector<Programmer> programmers;
};


#endif //TASKMANAGER___COPY_TASKREPO_H

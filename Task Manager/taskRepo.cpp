//
// Created by Ama on 6/30/2022.
//

#include "taskRepo.h"
#include "fstream"
#include "algorithm"


TaskRepo::TaskRepo(std::string taskpath): taskPath{taskpath} {
    loadProgrammers();
    ReadData();
}

void TaskRepo::AddTask(const Task &ts) {
    tasks.push_back(ts);
    WriteData();
}

void TaskRepo::DeleteTask(Task ts) {
    std::cout<<"del: "<<ts.getDescription();
    auto find = std::find(this->tasks.begin(), this->tasks.end(), ts);
    if (find != this->tasks.end())
    {
        tasks.erase(find);
        WriteData();
    }
}

/*void TaskRepo::UpdateTask(Task old, Task newts) {
    *//*auto find = std::find(this->tasks.begin(), this->tasks.end(), old);
    if (find != this->tasks.end())
    {
        tasks.erase(find);
        tasks.push_back(newts);
        WriteData();
    }*//*
    DeleteTask(old);
    AddTask(newts);
}*/

std::vector<Task> TaskRepo::GetTasks() {
    return tasks;
}

void TaskRepo::ReadData() {
    std::ifstream inputFile;
    inputFile.open(taskPath, std::ios::in);
    Task next;
    while (inputFile >> next)
    {
        tasks.push_back(next);
    }
    inputFile.close();
}

void TaskRepo::WriteData() {
    std::ofstream outputFile;
    outputFile.open(taskPath, std::ios::out);
    for (const Task& d : tasks)
        outputFile << d;
    outputFile.close();
}

void TaskRepo::loadProgrammers() {
    std::ifstream f("programmers");
    Programmer p{};
    while (f >> p) {
        programmers.push_back(p);
    }
    f.close();
}

std::vector<Programmer> TaskRepo::GetProgrammers() {
    return programmers;
}


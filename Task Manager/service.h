//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_SERVICE_H
#define TASKMANAGER___COPY_SERVICE_H
#pragma once

#include "taskRepo.h"
#include "observer.h"
#include <map>

class Service : public Subject
{
public:
    Service(TaskRepo* repo);
    ~Service();

    void addTask(std::string description);
    void deleteTask(std::string description);

    Task findTaskbyDescr(std::string description);
    Task takeTask(std::string description, int idprog);
    Task endTask(std::string description);

    bool isOpen(std::string descr);
    bool isInProgress(int idprog, std::string descr);
    bool isClosed(std::string descr);

    std::vector<Task> getAllTasks();
    std::vector<Task> getSortedTasks();

private:
    TaskRepo* repo;
};



#endif //TASKMANAGER___COPY_SERVICE_H

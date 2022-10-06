//
// Created by Ama on 6/30/2022.
//

#include "service.h"

Service::Service(TaskRepo *repo):repo{repo}, Subject(){
}

Service::~Service() {
}

Task Service::findTaskbyDescr(std::string description)
{
    Task elem;
    //std::cout<<description;
    for (auto t : getAllTasks())
        if (t.getDescription()==description)
        {
            elem = t;
            break;
        }
    return elem;
}

void Service::addTask(std::string description) {
    Task newTask = findTaskbyDescr(description);
    if(newTask.getDescription()!=description) {
        newTask = Task(description, "open", 0000);
        this->repo->AddTask(newTask);
        this->notify();
    }
}

void Service::deleteTask(std::string description) {
    Task elem = findTaskbyDescr(description);
    std::cout<<elem.getDescription();
    this->repo->DeleteTask(elem);
    this->notify();
}

Task Service::takeTask(std::string description,  int idprog) {
    Task task, newts;
    task= findTaskbyDescr(description);
    newts=Task(description, "progress", idprog);
    //this->repo->UpdateTask(task, newts);
    this->repo->DeleteTask(task);
    this->repo->AddTask(newts);
    this->notify();
    return newts;
}

Task Service::endTask(std::string description) {
    Task task, newts;
    task= findTaskbyDescr(description);
    newts=Task(description, "closed", task.getIdProg());
    //this->repo->UpdateTask(task, newts);
    this->repo->DeleteTask(task);
    this->repo->AddTask(newts);
    this->notify();
    return newts;
}

bool Service::isOpen(std::string descr) {
    Task elem = findTaskbyDescr(descr);
    if (elem.getStatus()=="open")
        return true;
    return false;
}

bool Service::isInProgress(int idprog, std::string descr) {
    Task elem = findTaskbyDescr(descr);
    std::cout<<elem.getDescription()<<elem.getStatus()<<elem.getIdProg()<<std::endl;
    if (elem.getStatus()=="progress" && elem.getIdProg()==idprog)
        return true;
    return false;
}

bool Service::isClosed(std::string descr) {
    Task elem = findTaskbyDescr(descr);
    if (elem.getStatus()=="closed")
        return true;
    return false;
}

std::vector<Task> Service::getAllTasks() {
    return repo->GetTasks();
}

std::vector<Task> Service::getSortedTasks(){
    std::vector<Task> v = getAllTasks();
    std::sort(v.begin(), v.end(), [](Task& q1, Task& q2) {return q1.getStatus() >= q2.getStatus();});

    return v;
}

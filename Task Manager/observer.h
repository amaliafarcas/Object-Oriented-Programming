//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_OBSERVER_H
#define TASKMANAGER___COPY_OBSERVER_H

#pragma once
#include <vector>
#include <sstream>
#include <algorithm>

class Observer
{
public:
    virtual void update() = 0;
    ~Observer() = default;

private:

};

class Subject
{
public:
    void addObserver(Observer* observer) {
        this->observers.push_back(observer);
    }

    void deleteObserver(Observer* observer) {
        auto it = std::find(this->observers.begin(), this->observers.end(), observer);
        if(it != this->observers.end())
            this->observers.erase(it);
    }

    void notify() {
        for (auto observer : this->observers)
            observer->update();
    }

private:
    std::vector<Observer*> observers;
};

#endif //TASKMANAGER___COPY_OBSERVER_H

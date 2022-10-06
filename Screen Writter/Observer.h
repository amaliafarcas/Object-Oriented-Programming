//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_OBSERVER_H
#define SCREENWRITTER_OBSERVER_H
#pragma once
#include "iostream"
#include <algorithm>
#include <sstream>
#include <vector>

class Observer
{
public:
    virtual void update() = 0;
    ~Observer() = default;
};

class Subject
{
public:
    void AddObserver(Observer* observer){
        this->observers.push_back(observer);
    }
    void DeleteObserver(Observer* observer){
        auto it = std::find(this->observers.begin(), this->observers.end(), observer);
        if(it != this->observers.end())
            this->observers.erase(it);
    }
    void notify(){
        //std::cout<<std::endl;
        for (auto observer : this->observers)
       /* {
            try
            {
                //std::cout<<"obs ";*/
                observer->update();
            /*}
            catch (std::bad_alloc & exception)
            {
                std::cout<<"bad alloc";
                std::cerr << "bad alloc detected: "<< exception.what();
            }*/

        //}
        //std::cout<<"notif";
    }
private:
    std::vector<Observer*> observers;
};

#endif //SCREENWRITTER_OBSERVER_H

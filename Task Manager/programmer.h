//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_PROGRAMMER_H
#define TASKMANAGER___COPY_PROGRAMMER_H
#pragma once
#include <iostream>

class Programmer {
public:
    Programmer();
    Programmer(std::string name, int id);
    ~Programmer();

    std::string getName();
    int getId();

    friend std::istream& operator>>(std::istream& is, Programmer& p);
    friend std::ostream& operator<<(std::ostream& os, const Programmer& p);
    bool operator==(const Programmer& other) const;


private:
    std::string name;
    int id;
};


#endif //TASKMANAGER___COPY_PROGRAMMER_H

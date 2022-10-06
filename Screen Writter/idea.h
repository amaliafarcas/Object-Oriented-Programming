//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_IDEA_H
#define SCREENWRITTER_IDEA_H
#pragma once
#include <iostream>

class Idea {
private:
    std::string name;
    std::string status;
    std::string creator;
    int act;
public:
    Idea();
    Idea(std::string name, std::string status, std::string creator, int act);
    ~Idea();

    std::string getName();
    std::string getStatus();
    std::string getCreator() ;
    int getAct() ;

    friend std::ostream& operator<<(std::ostream& os, const Idea& idea);
    friend std::istream& operator>>(std::istream& is, Idea& idea);
    bool operator==(const Idea &other) const;
};


#endif //SCREENWRITTER_IDEA_H

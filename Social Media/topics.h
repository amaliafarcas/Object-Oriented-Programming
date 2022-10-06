//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_TOPICS_H
#define EXAMREST_TOPICS_H
#pragma once
#include "iostream"
#include "vector"


class Topics {
private:
    std::string topic;
    std::string users;
public:
    Topics()=default;
    Topics(std::string topic, std::string users);
    ~Topics()=default;

    friend std::istream& operator>>(std::istream& is, Topics& p);
    friend std::ostream& operator<<(std::ostream& os, const Topics& p);
    bool operator==(const Topics& other) const;

    std::string getTopic();
    std::string getUsers();
};


#endif //EXAMREST_TOPICS_H

//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_POSTS_H
#define EXAMREST_POSTS_H
#pragma once
#include "iostream"

class Posts {
private:
    int id;
    std::string text;
    std::string date;
    std::string time;
    std::string username;
public:
    Posts()=default;
    Posts(int id, std::string text, std::string date, std::string time, std::string username);
    ~Posts()=default;

    friend std::istream& operator>>(std::istream& is, Posts& p);
    friend std::ostream& operator<<(std::ostream& os, const Posts& p);
    bool operator==(const Posts& other) const;

    int getId();
    std::string getText();
    std::string getDate();
    std::string getTime();
    std::string getUsername();
};


#endif //EXAMREST_POSTS_H

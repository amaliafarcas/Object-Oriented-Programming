//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_USERS_H
#define EXAMREST_USERS_H
#include "iostream"
#include "fstream"


class Users {
private:
    std::string name;
public:
    Users()=default;
    Users(std::string name);
    ~Users()=default;

    friend std::istream& operator>>(std::istream& is, Users& p);
    friend std::ostream& operator<<(std::ostream& os, const Users& p);
    bool operator==(const Users& other) const;

    std::string getName();
};


#endif //EXAMREST_USERS_H

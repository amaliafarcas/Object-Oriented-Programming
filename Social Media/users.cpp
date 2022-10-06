//
// Created by Ama on 7/6/2022.
//

#include "users.h"

Users::Users(std::string name) : name{name}{
}

std::string Users::getName() {
    return name;
}

std::istream &operator>>(std::istream &is, Users &p) {
    return is>>p.name;
}

std::ostream &operator<<(std::ostream &os, const Users &p) {
    return os<<p.name<<"\n";
}

bool Users::operator==(const Users &other) const {
    return other.name==name;
}



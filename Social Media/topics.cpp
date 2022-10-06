//
// Created by Ama on 7/6/2022.
//

#include "topics.h"

Topics::Topics(std::string topic, std::string users) : topic{topic}, users{users}{
}

std::istream &operator>>(std::istream &is, Topics &p) {
    return is>>p.topic>>p.users;
}

std::ostream &operator<<(std::ostream &os, const Topics &p) {
    return os<<p.topic<<" "<<p.users<<"\n";
}

bool Topics::operator==(const Topics &other) const {
    return false;
}

std::string Topics::getTopic() {
    return topic;
}

std::string Topics::getUsers() {
    return users;
}


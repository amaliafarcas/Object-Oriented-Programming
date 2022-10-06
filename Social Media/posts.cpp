//
// Created by Ama on 7/6/2022.
//

#include "posts.h"

Posts::Posts(int id, std::string text, std::string date, std::string time, std::string username):
id{id}, text{text}, date{date}, time{time}, username{username}{
}

std::istream &operator>>(std::istream &is, Posts &p) {
    return is>>p.id>>p.text>>p.date>>p.time>>p.username;
}

std::ostream &operator<<(std::ostream &os, const Posts &p) {
    return os<<p.id<<" "<<p.text<<" "<<p.date<<" "<<p.time<<" "<<p.username<<"\n";
}

bool Posts::operator==(const Posts &other) const {
    return other.id ==id;
}

int Posts::getId() {
    return id;
}

std::string Posts::getText() {
    return text;
}

std::string Posts::getDate() {
    return date;
}

std::string Posts::getTime() {
    return time;
}

std::string Posts::getUsername() {
    return username;
}

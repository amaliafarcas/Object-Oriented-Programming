//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_SERVICE_H
#define EXAMREST_SERVICE_H

#pragma once

#include "repo.h"
#include "observer.h"
#include "users.h"
#include "topics.h"
#include "posts.h"

class Service : public Subject
{
public:
    Service(Repo* repo);
    ~Service();

    void addTopic(std::string topic, std::string users);
    void addPost(int id, std::string text, std::string date, std::string time, std::string username);

    Posts UpdatePost(int id, std::string text);

    std::vector<Posts> getAllPosts();
    std::vector<Posts> getSortedPosts();

    std::vector<Topics> getAllTopics();
    std::vector<std::string> getTopicsUser(std::string name);

    std::vector<Posts> getPostsUser(std::string name);

    std::vector<Posts> getFeed(std::string name);

    std::vector<std::string> getUsersTopic(std::string topic);

private:
    Repo* repo;

    Topics findTopic(std::string topic, std::string users);

};

#endif //EXAMREST_SERVICE_H

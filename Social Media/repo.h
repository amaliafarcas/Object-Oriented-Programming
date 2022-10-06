//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_REPO_H
#define EXAMREST_REPO_H
#pragma once

#include <vector>
#include "users.h"
#include "topics.h"
#include "posts.h"


class Repo {

public:
    Repo(std::string postsPath, std::string topicsPath);
    ~Repo()=default;
    void AddPost(const Posts& ts);
    void AddTopic(const Topics& ts);

    std::vector<Posts> GetPosts();
    std::vector<Topics> GetTopics();
    std::vector<Users> GetUsers();

    void RemovePost(Posts ts);

protected:
    std::string postsPath;
    std::string topicsPath;
private:
    void ReadTopics();
    void ReadPosts();

    void WriteTopics();
    void WritePosts();

    void loadUsers();

    std::vector<Posts> posts;
    std::vector<Topics> topics;
    std::vector<Users> users;

};

#endif //EXAMREST_REPO_H

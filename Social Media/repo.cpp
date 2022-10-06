//
// Created by Ama on 7/6/2022.
//

#include "repo.h"
#include "fstream"
#include "algorithm"

Repo::Repo(std::string postsPath, std::string topicsPath) : postsPath{postsPath}, topicsPath{topicsPath} {
    loadUsers();
    ReadTopics();
    ReadPosts();
}

void Repo::AddPost(const Posts &ts) {
    posts.push_back(ts);
    WritePosts();
}

void Repo::AddTopic(const Topics &ts) {
    topics.push_back(ts);
    WriteTopics();
}

std::vector<Posts> Repo::GetPosts() {
    return posts;
}

std::vector<Topics> Repo::GetTopics() {
    return topics;
}

void Repo::ReadTopics() {
    std::ifstream inputFile;
    inputFile.open(topicsPath, std::ios::in);
    Topics next;
    while (inputFile >> next)
    {
        topics.push_back(next);
    }
    inputFile.close();
}

void Repo::ReadPosts() {
    std::ifstream inputFile;
    inputFile.open(postsPath, std::ios::in);
    Posts next;
    while (inputFile >> next)
    {
        posts.push_back(next);
    }
    inputFile.close();
}

void Repo::WriteTopics() {
    std::ofstream outputFile;
    outputFile.open(topicsPath, std::ios::out);
    for (const Topics& d : topics)
        outputFile << d;
    outputFile.close();
}

void Repo::WritePosts() {
    std::ofstream outputFile;
    outputFile.open(postsPath, std::ios::out);
    for (const Posts& d : posts)
        outputFile << d;
    outputFile.close();
}

void Repo::loadUsers() {
    std::ifstream f("users");
    Users p{};
    while (f >> p) {
        users.push_back(p);
    }
    f.close();
}

std::vector<Users> Repo::GetUsers() {
    return users;
}

void Repo::RemovePost(Posts ts) {
    auto find = std::find(this->posts.begin(), this->posts.end(), ts);
    if (find != this->posts.end())
    {
        posts.erase(find);
        WritePosts();
    }
}


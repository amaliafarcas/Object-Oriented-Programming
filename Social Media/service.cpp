//
// Created by Ama on 7/6/2022.
//

#include "service.h"

Service::Service(Repo *repo) : repo {repo}{
}

Service::~Service() {
}

void Service::addTopic(std::string topic, std::string users) {
    Topics newT = findTopic(topic, users);
    if(newT.getTopic()!=topic && newT.getUsers()!=users) {
        newT = Topics(topic, users);
        this->repo->AddTopic(newT);
        this->notify();
    }
}

Topics Service::findTopic(std::string topic, std::string users)
{
    for (auto t : getAllTopics())
        if(t.getTopic()==topic && t.getUsers()==users)
            return t;
    Topics top;
    return top;
}

void Service::addPost(int id, std::string text, std::string date, std::string time, std::string username) {
    Posts newT = Posts(id, text, date, time, username);
    this->repo->AddPost(newT);
    this->notify();
}

std::vector<Posts> Service::getAllPosts() {
    return repo->GetPosts();
}

std::vector<Posts> Service::getSortedPosts() {
    std::vector<Posts> v = getAllPosts();
    std::sort(v.begin(), v.end(), [](Posts& q1, Posts& q2) {return q1.getTime() >= q2.getTime();});
    std::sort(v.begin(), v.end(), [](Posts& q1, Posts& q2) {return q1.getDate() >= q2.getDate();});

    return v;
}

std::vector<Topics> Service::getAllTopics() {
    return repo->GetTopics();
}

std::vector<std::string> Service::getTopicsUser(std::string name) {
    std::vector<std::string> str;
    for (auto t : getAllTopics())
        if(t.getUsers()==name)
            str.push_back(t.getTopic());
    return str;
}

std::vector<std::string> Service::getUsersTopic(std::string topic) {
    std::vector<std::string> str;
    for (auto t : getAllTopics())
        if(t.getTopic()==topic)
            str.push_back(t.getUsers());
    return str;
}

std::vector<Posts> Service::getPostsUser(std::string name) {
    std::vector<Posts> str;
    for (auto t : getAllPosts())
        if(t.getUsername()==name)
            str.push_back(t);
    return str;
}

std::vector<Posts> Service::getFeed(std::string name)
{
    std::vector<Posts> feed;
    std::string n = "@" + name;
    for (auto t : getAllPosts()) {
        if (t.getText() == n)
            feed.push_back(t);
        for (auto top : getTopicsUser(name))
        {
            std::string l = "#" + top;
            if(t.getText() == l)
                feed.push_back(t);
        }
    }
    return feed;
}

Posts Service::UpdatePost(int id, std::string text) {
    Posts post, newp;
    for (auto is : getAllPosts())
        if (is.getId() == id)
        {
            post = is;
            newp = Posts(id, text, post.getDate(), post.getTime(), post.getUsername());

            break;
        }
    this->repo->RemovePost(post);
    this->repo->AddPost(newp);
    this->notify();
    return newp;
}


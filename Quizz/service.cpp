//
// Created by Ama on 6/10/2022.
//

#include "service.h"
#include <algorithm>

Service::Service(FileRepository<Question>* questions, FileRepository<Participant>* participants) :
        questions{ questions }, participants{ participants }
{
}

Service::~Service()
{
}

void Service::addQuestion(int id, std::string text, std::string correctAnswer, int score)
{
    score = rand() % 100;
    Question newQuestion{ id, text, correctAnswer, score };
    this->questions->addElement(newQuestion);
    this->notify();
}

Participant Service::updateParticipant(std::string name, int score)
{
    Participant p{name, score};
    this->participants->update(p);
    this->notify();
    return p;
}

void Service::addAnswer(std::string name, int QuestionId)
{
    this->answeredQuestion.insert(std::pair<std::string, int>(name, QuestionId));
    this->notify();
}

bool Service::isAnswered(std::string name, int QuestionId)
{
    for (auto element : this->answeredQuestion)
        if (element.first == name && element.second == QuestionId)
            return true;
    return false;
}

std::vector<Question> Service::getAllQuestions()
{
    std::vector<Question> v = this->questions->getAll();
    std::sort(v.begin(), v.end(), [](Question& q1, Question& q2) {return q1.getId() < q2.getId();});

    return v;
}

std::vector<Question> Service::getAllSortedByScore()
{
    std::vector<Question> v = this->questions->getAll();
    std::sort(v.begin(), v.end(), [](Question& q1, Question& q2) {return q1.getScore() < q2.getScore();});

    return v;
}

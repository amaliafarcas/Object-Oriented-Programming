//
// Created by Ama on 6/10/2022.
//

#ifndef QUIZZ_SERVICE_H
#define QUIZZ_SERVICE_H


#pragma once

#include "FileRepo.h"
#include "Observer.h"
#include <map>

class Service : public Subject
{
public:
    Service(FileRepository<Question>* questions, FileRepository<Participant>* participants);
    ~Service();

    void addQuestion(int id, std::string text, std::string correctAnswer, int score);
    Participant updateParticipant(std::string name, int score);

    void addAnswer(std::string name, int QuestionId);
    bool isAnswered(std::string name, int QuestionId);

    std::vector<Question> getAllQuestions();
    std::vector<Question> getAllSortedByScore();

private:
    FileRepository<Question>* questions;
    FileRepository<Participant>* participants;
    std::multimap<std::string, int> answeredQuestion;
};


#endif //QUIZZ_SERVICE_H

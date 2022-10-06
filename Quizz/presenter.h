//
// Created by Ama on 6/10/2022.
//

#ifndef QUIZZ_PRESENTER_H
#define QUIZZ_PRESENTER_H

#pragma once

#include<iostream>

class Question
{
public:
    Question();
    Question(int id, std::string text, std::string correctAnsw, int score);
    ~Question();

    friend std::istream& operator>>(std::istream& is, Question& q);
    friend std::ostream& operator<<(std::ostream& os, const Question& q);
    bool operator==(const Question& other) const;

    int getScore();
    std::string getText();
    std::string getAnswer();
    int getId();

private:
    int id;
    std::string text;
    std::string correctAnsw;
    int score;
};



#endif //QUIZZ_PRESENTER_H

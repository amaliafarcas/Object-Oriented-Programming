//
// Created by Ama on 6/10/2022.
//

#ifndef QUIZZ_PARTICIPANT_H
#define QUIZZ_PARTICIPANT_H

#pragma once

#include<iostream>

class Participant
{
public:
    Participant();
    Participant(std::string name, int score);
    ~Participant();

    friend std::istream& operator>>(std::istream& is, Participant& p);
    friend std::ostream& operator<<(std::ostream& os, const Participant& p);
    bool operator==(const Participant& other) const;

    int getScore();
    std::string getName();

    void setScore(int newScore);

private:
    std::string name;
    int score;
};

#endif //QUIZZ_PARTICIPANT_H

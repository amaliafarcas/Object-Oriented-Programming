//
// Created by Ama on 6/10/2022.
//

#include "Participant.h"

Participant::Participant() :
        score{ 0 }, name{ "" }
{
}

Participant::Participant(std::string name, int score) :
        name{ name }, score{ score }
{
}

Participant::~Participant()
{
}

bool Participant::operator==(const Participant& other) const
{
    return this->name == other.name;
}

int Participant::getScore()
{
    return this->score;
}

std::string Participant::getName()
{
    return this->name;
}

void Participant::setScore(int newScore)
{
    this->score = newScore;
}

std::istream& operator>>(std::istream& is, Participant& p)
{
    is >> p.name;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Participant& p)
{
    os << p.name << " " << p.score;
    return os;
}

//
// Created by Ama on 6/10/2022.
//

#include "presenter.h"

Question::Question() :
        id{ 0 }, text{ "" }, correctAnsw{ "" }, score{ 0 }
{
}

Question::Question(int id, std::string text, std::string correctAnsw, int score) :
        id{ id }, text{ text }, correctAnsw{ correctAnsw }, score{ score }
{
}

Question::~Question()
{
}

bool Question::operator==(const Question& other) const
{
    return this->id == other.id;
}

int Question::getScore()
{
    return this->score;
}

std::string Question::getText()
{
    return this->text;
}

std::string Question::getAnswer()
{
    return this->correctAnsw;
}

int Question::getId()
{
    return this->id;
}

std::istream& operator>>(std::istream& is, Question& q)
{
    is >> q.id >> q.text >> q.correctAnsw >> q.score;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Question& q)
{
    os << q.id << " " << q.text << " " << q.correctAnsw << " " << q.score << "\n";
    return os;
}

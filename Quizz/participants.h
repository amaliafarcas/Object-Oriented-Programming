//
// Created by Ama on 6/10/2022.
//

#ifndef QUIZZ_PARTICIPANTS_H
#define QUIZZ_PARTICIPANTS_H

#pragma once

#include <QWidget>
#include "ui_participants.h"
#include "service.h"
#include "Observer.h"

class participants : public QWidget, public Observer
{
Q_OBJECT

public:
    participants(Service* service, Participant p, QWidget *parent = Q_NULLPTR);
    ~participants();

    void connectSignalsandSlots();
    void populateList();
    void update() override;

    void answerQuestion();
    void setAnswerButton();
    int getSelectedIndex();

private:
    Ui::participants ui;
    Service* service;
    Participant p;
};


#endif //QUIZZ_PARTICIPANTS_H

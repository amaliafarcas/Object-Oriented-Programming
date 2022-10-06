//
// Created by Ama on 6/10/2022.
//

#ifndef QUIZZ_QUIZZ_H
#define QUIZZ_QUIZZ_H

#include <QWidget>
#include <QMainWindow>
#include "service.h"
#include "Observer.h"
#include "ui_quizz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class quizz; }
QT_END_NAMESPACE

class quizz : public QMainWindow, public Observer{
Q_OBJECT

public:
    quizz(Service* service, QMainWindow *parent = Q_NULLPTR);
    ~quizz();

    void populateList();
    void connectSignalsAndSlots();
    void update() override;

    void addQuestion();

private:
    Ui::quizz ui;
    Service* service;
};


#endif //QUIZZ_QUIZZ_H

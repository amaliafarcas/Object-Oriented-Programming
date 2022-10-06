//
// Created by Ama on 6/10/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_quizz.h" resolved

#include "quizz.h"
#include "ui_quizz.h"

quizz::quizz(Service* service, QMainWindow *parent)
        : service{service}, QMainWindow(parent)
{
    ui.setupUi(this);
    this->populateList();
    this->connectSignalsAndSlots();
    this->ui.listWidget->setSortingEnabled(true);
}

quizz::~quizz()
{
}

void quizz::populateList()
{
    this->ui.listWidget->clear();

    std::vector<Question> allQuestions = this->service->getAllQuestions();
    for (auto question : allQuestions)
    {
        QString q = QString::fromStdString(std::to_string(question.getId()) + " " + question.getText() + " " + question.getAnswer() +
                                           " " + std::to_string(question.getScore()));

        this->ui.listWidget->addItem(q);
    }

}

void quizz::connectSignalsAndSlots()
{
    QObject::connect(ui.AddQButton, &QPushButton::clicked, this, &quizz::addQuestion);
}

void quizz::update()
{
    this->populateList();
}

void quizz::addQuestion()
{
    std::string text = ui.QlineEdit_2->text().toStdString();
    std::string correctAnsw = ui.ANSlineEdit_3->text().toStdString();
    int id = std::stoi(ui.IDlineEdit->text().toStdString());

    this->service->addQuestion(id, text, correctAnsw, 0);
}

//
// Created by Ama on 6/10/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_participants.h" resolved

#include "participants.h"
#include "ui_participants.h"

participants::participants(Service* service, Participant p, QWidget *parent)
        :service{ service }, p{p}, QWidget(parent)
{
    ui.setupUi(this);
    this->populateList();
    this->connectSignalsandSlots();

    this->ui.SCORElineEdit->setText(QString::number(this->p.getScore()));
    this->ui.SCORElineEdit->setEnabled(false);
}

participants::~participants()
{
}

void participants::connectSignalsandSlots()
{
    QObject::connect(this->ui.SUBMITButton, &QPushButton::clicked, this, &participants::answerQuestion);
    QObject::connect(this->ui.listWidget, &QListWidget::itemSelectionChanged, this, &participants::setAnswerButton);
}

void participants::populateList()
{
    this->ui.listWidget->clear();

    std::vector<Question> data = this->service->getAllSortedByScore();

    for (auto question : data)
    {
        QString q = QString::fromStdString(std::to_string(question.getId()) + " " + question.getText() +
                                           " " + std::to_string(question.getScore()));

        this->ui.listWidget->addItem(q);
    }
}

void participants::update()
{
    this->populateList();
}

void participants::answerQuestion()
{
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex != -1)
    {
        this->service->addAnswer(this->p.getName(), this->service->getAllSortedByScore()[selectedIndex].getId());
        this->ui.SUBMITButton->setEnabled(false);

        std::string answer = this->ui.RANSlineEdit->text().toStdString();
        if (answer == this->service->getAllSortedByScore()[selectedIndex].getAnswer())
        {
            this->service->updateParticipant(p.getName(), p.getScore() + this->service->getAllSortedByScore()[selectedIndex].getScore());

            this->p.setScore(this->p.getScore() + this->service->getAllSortedByScore()[selectedIndex].getScore());
            this->ui.SCORElineEdit->setText(QString::number(this->p.getScore()));
        }
    }
}

void participants::setAnswerButton()
{
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex != -1)
    {
        if (this->service->isAnswered(p.getName(), this->service->getAllQuestions()[selectedIndex].getId()))
            this->ui.SUBMITButton->setEnabled(false);
        else
            this->ui.SUBMITButton->setEnabled(true);
    }
}

int participants::getSelectedIndex()
{
    QModelIndexList selectedIndices = this->ui.listWidget->selectionModel()->selectedIndexes();
    if (selectedIndices.size() == 0)
    {
        return -1;
    }
    int selectedIndex = selectedIndices.at(0).row();
    return selectedIndex;
}

//
// Created by Ama on 6/30/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_programmerWindow.h" resolved

#include "programmerwindow.h"
#include <QMessageBox>

programmerWindow::programmerWindow(Service* service, Programmer p,QMainWindow *parent) :
        service{service}, p{p}, QMainWindow(parent) {
    ui.setupUi(this);
    this->populateList();
    this->connectSignalsandSlots();
}

programmerWindow::~programmerWindow() {
    //delete ui;
}

void programmerWindow::update() {
    this->populateList();
}

void programmerWindow::connectSignalsandSlots() {
    QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &programmerWindow::addTask);
    QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &programmerWindow::deleteTask);

    QObject::connect(this->ui.startButton, &QPushButton::clicked, this, &programmerWindow::startTask);
    QObject::connect(this->ui.doneButton, &QPushButton::clicked, this, &programmerWindow::doneTask);

    QObject::connect(this->ui.listWidget, &QListWidget::itemSelectionChanged, this, &programmerWindow::setStartButton);
    QObject::connect(this->ui.listWidget, &QListWidget::itemSelectionChanged, this, &programmerWindow::setDoneButton);

}

void programmerWindow::populateList() {
    this->ui.listWidget->clear();

    std::vector<Task> data = this->service->getSortedTasks();
    for (auto task : data)
    {
        QString q = QString::fromStdString(task.getDescription() + " " + task.getStatus() +
                                           " " + std::to_string(task.getIdProg()));

        this->ui.listWidget->addItem(q);
    }
}

int programmerWindow::getSelectedIndex() {
    QModelIndexList selectedIndices = this->ui.listWidget->selectionModel()->selectedIndexes();
    if (selectedIndices.size() == 0)
    {
        return -1;
    }
    int selectedIndex = selectedIndices.at(0).row();
    return selectedIndex;
}

void programmerWindow::addTask() {
    std::string descr = this->ui.lineEdit->text().toStdString();
    for (auto is:service->getAllTasks())
        if(is.getDescription()==descr)
        {
            QMessageBox msg;
            msg.setText("Invalid! Task already added");
            msg.exec();
            return;
        }
    this->service->addTask(descr);
    //std::cout<<descr;
    this->update();
}

void programmerWindow::deleteTask() {
    int selectedIndex = this->getSelectedIndex();
    std::cout<<selectedIndex;
    if (selectedIndex != -1)
    {
        std::cout<<this->service->getSortedTasks()[selectedIndex].getDescription();
        this->service->deleteTask(this->service->getSortedTasks()[selectedIndex].getDescription());
        this->update();
    }
}

void programmerWindow::startTask() {
    int selectedIndex = this->getSelectedIndex();
    std::cout<<selectedIndex;
    this->service->takeTask(this->service->getSortedTasks()[selectedIndex].getDescription(), p.getId());
    this->update();
}

void programmerWindow::doneTask() {
    int selectedIndex = this->getSelectedIndex();
    std::cout<<selectedIndex;
    this->service->endTask(this->service->getSortedTasks()[selectedIndex].getDescription());
    this->update();
}

void programmerWindow::setStartButton() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex != -1)
    {
        if (this->service->isOpen(this->service->getSortedTasks()[selectedIndex].getDescription()))
            this->ui.startButton->setEnabled(true);
        else
            this->ui.startButton->setEnabled(false);
    }
}

void programmerWindow::setDoneButton() {
    int selectedIndex = this->getSelectedIndex();
    if (selectedIndex != -1)
    {
        std::cout<<p.getName();
        if (this->service->isInProgress(p.getId(), this->service->getSortedTasks()[selectedIndex].getDescription()))
            this->ui.doneButton->setEnabled(true);
        else
            this->ui.doneButton->setEnabled(false);
    }
}


//
// Created by Ama on 6/30/2022.
//

#ifndef TASKMANAGER___COPY_PROGRAMMERWINDOW_H
#define TASKMANAGER___COPY_PROGRAMMERWINDOW_H
#pragma once
#include <QWidget>
#include <QMainWindow>
#include "ui_programmerWindow.h"
#include "observer.h"
#include "programmer.h"
#include "service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class programmerWindow; }
QT_END_NAMESPACE

class programmerWindow : public QMainWindow, public Observer{
Q_OBJECT

public:
    programmerWindow(Service* service, Programmer p, QMainWindow *parent = nullptr);
    ~programmerWindow();
    void update() override;

    void connectSignalsandSlots();
    void populateList();
    void setStartButton();
    void setDoneButton();
    int getSelectedIndex();

    void addTask();
    void deleteTask();
    void startTask();
    void doneTask();

private:
    Programmer p;
    Service* service;
    Ui::programmerWindow ui;
};


#endif //TASKMANAGER___COPY_PROGRAMMERWINDOW_H

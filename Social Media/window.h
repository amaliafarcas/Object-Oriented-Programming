//
// Created by Ama on 7/6/2022.
//

#ifndef EXAMREST_WINDOW_H
#define EXAMREST_WINDOW_H
#pragma once
#include <QWidget>
#include "QMainWindow"
#include "ui_Window.h"
#include "observer.h"
#include "service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit Window(Service* service, Users user ,QMainWindow *parent = nullptr);
    void update() override;

    void connectSignalsandSlots();
    void populateFeedList();
    void populatePostsList();
    void populateTopicsList();

    int getSelectedIndex();

    void addPost();
    void addTopic();
    void UpdatePost();

    ~Window() override;

private:
    Service* service;
    Users user;
    Ui::Window ui;

    //void getUsersTopic(std::string basicString);
};


#endif //EXAMREST_WINDOW_H

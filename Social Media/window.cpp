//
// Created by Ama on 7/6/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window.h" resolved

#include "window.h"
#include "QMessageBox"


Window::Window(Service* service, Users user, QMainWindow *parent) :
        service{service}, user{user}, QMainWindow(parent) {
    ui.setupUi(this);

    populateFeedList();
    populatePostsList();
    populateTopicsList();

    this->connectSignalsandSlots();
}

Window::~Window() {
   // delete ui;
}

void Window::update() {
    populateFeedList();
    populatePostsList();
    populateTopicsList();
}

void Window::connectSignalsandSlots() {
    QObject::connect(this->ui.subscribeButton, &QPushButton::clicked, this, &Window::addTopic);
    QObject::connect(this->ui.PostButton, &QPushButton::clicked, this, &Window::addPost);
    QObject::connect(this->ui.UpdateButton, &QPushButton::clicked, this, &Window::UpdatePost);

}

void Window::populateFeedList() {
    this->ui.feedWidget->clear();

    std::vector<Posts> v = this->service->getFeed(user.getName());
    //std::vector<Posts> v = getAllPosts();
    std::sort(v.begin(), v.end(), [](Posts& q1, Posts& q2) {return q1.getTime() >= q2.getTime();});
    //std::sort(v.begin(), v.end(), [](Posts& q1, Posts& q2) {return q1.getDate() >= q2.getDate();});

    int i=-1;
    std::string n = "@" + user.getName();
    for (auto pos : v)
    {
        i++;
        QString q = QString::fromStdString(std::to_string(pos.getId()) + " " + pos.getText() +
                                           " " + pos.getDate() + " " + pos.getTime());
       /* if ( n == pos.getText())
            this->ui.feedWidget->item(i)->setForeground(Qt::darkBlue);*/
        this->ui.feedWidget->addItem(q);
    }
}

void Window::populatePostsList() {
    this->ui.postsWidget->clear();

    std::vector<Posts> v = this->service->getPostsUser(user.getName());
    std::sort(v.begin(), v.end(), [](Posts& q1, Posts& q2) {return q1.getTime() >= q2.getTime();});

    for (auto pos : v)
    {
        QString q = QString::fromStdString(std::to_string(pos.getId()) + " " + pos.getText() +
                                           " " + pos.getDate() + " " + pos.getTime());

        this->ui.postsWidget->addItem(q);
    }
}

void Window::populateTopicsList() {
    this->ui.topicsWidget->clear();

    std::vector<std::string> data = this->service->getTopicsUser(user.getName());
    for (auto pos : data)
    {
        QString q = QString::fromStdString(pos);
        for (auto t : service->getUsersTopic(pos))
            q += QString::fromStdString(" " + t);
        this->ui.topicsWidget->addItem(q);
    }
}

int Window::getSelectedIndex() {
/*    QModelIndexList selectedIndices = this->ui.listWidget->selectionModel()->selectedIndexes();
    if (selectedIndices.size() == 0)
    {
        return -1;
    }
    int selectedIndex = selectedIndices.at(0).row();
    return selectedIndex;*/
return 0;
}

void Window::addPost() {

    std::string descr = this->ui.textLineEdit->text().toStdString();
    if(descr.size()==0)
    {
        QMessageBox msg;
        msg.setText("Invalid! Empty text");
        msg.exec();
        return;
    }
        if(descr.size()<3)
        {
            QMessageBox msg;
            msg.setText("Invalid! Text too short");
            msg.exec();
            return;
        }
    this->service->addPost(rand()%1000+1, descr, "05.07.2022", "15:25", user.getName());
    //std::cout<<descr;
    this->update();
}

void Window::addTopic() {
    std::string descr = this->ui.topicsLineEdit->text().toStdString();

    for (auto is:service->getTopicsUser(user.getName()))
        if(is==descr)
        {
            QMessageBox msg;
            msg.setText("Invalid! Already subscribed");
            msg.exec();
            return;
        }
    if(descr.size()==0)
    {
        QMessageBox msg;
        msg.setText("Invalid! Empty text");
        msg.exec();
        return;
    }
    if(descr.size()<3)
    {
        QMessageBox msg;
        msg.setText("Invalid! Text too short");
        msg.exec();
        return;
    }

    this->service->addTopic(descr, user.getName());
    this->update();
}

void Window::UpdatePost() {
    int id = this->ui.idLineEdit->text().toInt();
    int k=0;
    for (auto t: service->getAllPosts())
        if(t.getId()==id)
            k=1;
    if(k==0)
    {
        QMessageBox msg;
        msg.setText("Invalid! NO post with such id");
        msg.exec();
        return;
    }
    std::string descr = this->ui.newTextLineEdit->text().toStdString();
    if(descr.size()==0)
    {
        QMessageBox msg;
        msg.setText("Invalid! Empty text");
        msg.exec();
        return;
    }
    if(descr.size()<3)
    {
        QMessageBox msg;
        msg.setText("Invalid! Text too short");
        msg.exec();
        return;
    }
    this->service->UpdatePost(id, descr);
    this->update();
}




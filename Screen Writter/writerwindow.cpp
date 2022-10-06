//
// Created by Ama on 7/5/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WriterWindow.h" resolved

#include <QAbstractButton>
#include "writerwindow.h"
#include "ui_WriterWindow.h"


WriterWindow::WriterWindow(IdeaTableModel* model, Service* service, ScreenWriter writer, QMainWindow *parent) :
        model{model}, service{service}, writer{writer}, QMainWindow(parent) {
    ui.setupUi(this);
    ui.tableView->setModel(model);
    connectSignalsandSlots();
}

WriterWindow::~WriterWindow() {
    //delete ui;
}

void WriterWindow::connectSignalsandSlots() {
    QObject::connect(ui.AddButton, &QPushButton::clicked, this, &WriterWindow::AddIdea);

}

void WriterWindow::update() {
    this->model->update();
}

void WriterWindow::AddIdea() {
    std::string description = ui.DlineEdit->text().toStdString();
    std::string act = ui.AlineEdit->text().toStdString();
    int Act = stoi(act);

    std::string status = "proposed";
    std::string creator = writer.getName();

    this->service->addIdea(description, status, creator, Act);

}

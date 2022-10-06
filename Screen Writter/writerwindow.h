//
// Created by Ama on 7/5/2022.
//

#ifndef SCREENWRITTER_WRITERWINDOW_H
#define SCREENWRITTER_WRITERWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "screenWriter.h"
#include "service.h"
#include "Observer.h"
#include "IdeaTableModel.h"
#include "ui_WriterWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class WriterWindow; }
QT_END_NAMESPACE

class WriterWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit WriterWindow(IdeaTableModel* model, Service* service, ScreenWriter writer, QMainWindow *parent = nullptr);

    void connectSignalsandSlots();
    void update() override;
    ~WriterWindow() override;

    int getSelectedIndex();

    void AddIdea();

private:
    ScreenWriter writer;
    Service* service;
    IdeaTableModel* model;
    Ui::WriterWindow ui;
};


#endif //SCREENWRITTER_WRITERWINDOW_H

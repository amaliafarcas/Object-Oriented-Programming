//
// Created by Ama on 7/2/2022.
//

#ifndef SCREENWRITTER_IDEATABLEMODEL_H
#define SCREENWRITTER_IDEATABLEMODEL_H

#pragma once
#include <qabstractitemmodel.h>
#include "ideaRepo.h"
#include "idea.h"
#include <string>
#include "Observer.h"

class IdeaTableModel : public QAbstractTableModel, public Observer
{
private:
    IdeaRepo* repository;

public:
    IdeaTableModel(IdeaRepo* repository) : repository{ repository } {};

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void update();
};
#endif //SCREENWRITTER_IDEATABLEMODEL_H

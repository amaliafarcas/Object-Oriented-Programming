//
// Created by Ama on 7/2/2022.
//

#include "IdeaTableModel.h"
#include "algorithm"

int IdeaTableModel::rowCount(const QModelIndex& parent) const
{
    return this->repository->GetIdeas().size();
}

int IdeaTableModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant IdeaTableModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    std::vector<Idea> ideas = this->repository->GetIdeas();
    std::sort(ideas.begin(), ideas.end(), [](Idea& a, Idea& b) {return (a.getAct() < b.getAct()); });
    Idea currentEntity = ideas[row];
    int column = index.column();
    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(currentEntity.getName());
            case 1:
                return QString::fromStdString(currentEntity.getStatus());
            case 2:
            {
                return QString::fromStdString(currentEntity.getCreator());
            }
            case 3:
                return QString::number(currentEntity.getAct());
            default:
                break;
        }

    }
    return QVariant();
}

QVariant IdeaTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Name");
                case 1:
                    return QString("Status");
                case 2:
                    return QString("Creator");
                case 3:
                    return QString("Act");
                default:
                    break;
            }
        }
    }
    return QVariant();
}

void IdeaTableModel::update()
{
    QModelIndex topLeft = this->index(1, 1);
    QModelIndex bottomRight = this->index(this->rowCount(), this->columnCount());
    emit layoutChanged();
    emit dataChanged(topLeft, bottomRight);
}
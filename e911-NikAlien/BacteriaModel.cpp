//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "BacteriaModel.h"


int BacteriaModel::rowCount(const QModelIndex &parent) const {
    return serv.getBacteria().size();
}

int BacteriaModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant BacteriaModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    Bacterium b = serv.getBacteria()[row];

    if(role == Qt::DisplayRole)
    {
        switch (col) {
            case 0:
                return QString(b.getName().c_str());
            case 1:
                return QString(b.getSpecies().c_str());
            case 2:
                return QString(std::to_string(b.getSize()).c_str());
        }
    }
    return QVariant();
}

Qt::ItemFlags BacteriaModel::flags(const QModelIndex &index) const {
    if(index.column() == 0 || index.column() == 1 || index.column() == 2)
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}

bool BacteriaModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Bacterium& b = serv.getBacteria()[index.row()];
    int col = index.column();
    if(role == Qt::EditRole)
    {
        switch (col) {
            case 0:
                b.setName(value.toString().toStdString());
            case 1:
                b.setSpecies(value.toString().toStdString());
                break;
            case 2:
                b.setSize(value.toInt());
                break;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}


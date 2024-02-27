#pragma once
#include "Service.h"
#include <QAbstractTableModel>

class BacteriaModel : public QAbstractTableModel{
    Q_OBJECT
private:
    Service& serv;

public:
    explicit BacteriaModel(Service& s) : serv(s) {};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

};


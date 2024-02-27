#pragma once
#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QListWidget>
#include "QLineEdit"
#include "Service.h"

class AdminGUI : public QWidget{
    Q_OBJECT

public:
    AdminGUI(FileAdoptList* f, QWidget* parent = 0);
    void initGUI();

private:
    void adminSignSlot();
    void populateList();
    void listItemChanged();

    void addDogRecord();
    void deleteDogRecord();
    void updateDogRecord();

    Service* servAdmin;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updButton;
    QPushButton* exit;
    QListWidget* dogList;
    QLineEdit* name;
    QLineEdit* breed;
    QLineEdit* age;
    QLineEdit* photo;


signals:
    void goBack();
};

#pragma once
#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QListWidget>
#include <QComboBox>
#include "Service.h"
#include "SlideShow.h"

class UserGUI : public QWidget{
    Q_OBJECT

public:
    UserGUI(FileAdoptList* f, QWidget* parent = 0);
    void initGUI();

private:
    Service* servUser;
    int index;
    std::vector<Dog> dogFilterList;

    QPushButton* search;
    QPushButton* file;
    QPushButton* exit;
    QListWidget* dogList;
    QComboBox* filterBreed;
    QComboBox* filterAge;
    SlideShow* showSlide;

    void userSignSlot();
    void populateList();
    void displayFile();
    void slideShowFilter();
    void slideDisplay();

signals:
    void goBack();

};


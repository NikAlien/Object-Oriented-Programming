#pragma once
#include <QWidget>
#include <QListWidget>
#include <QRadioButton>
#include <QtWidgets/QPushButton>
#include <QGroupBox>
#include "Service.h"
#include "AdminGUI.h"
#include "UserGUI.h"

class MainGUI : public QWidget{
    Q_OBJECT

public:
    MainGUI(FileAdoptList* f, QWidget* parent = 0);
    void initGUI();

private:
    QPushButton* admin;
    QPushButton* user;
    QPushButton* exit;
    FileAdoptList* file;
    AdminGUI* adminGui;
    UserGUI* userGui;

    void mainSignSlot();
    void goToAdmin();
    void goToUser();

};

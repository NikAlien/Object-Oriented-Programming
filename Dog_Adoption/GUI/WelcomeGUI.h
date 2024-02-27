#pragma once
#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QtWidgets/QPushButton>
#include <QStackedWidget>
#include "MainGUI.h"
#include "AdminGUI.h"

class WelcomeGUI : public QWidget{
    Q_OBJECT

public:
    WelcomeGUI(QWidget* parent = 0);
    void initGUI();

private:
    QGroupBox* radioList;
    QRadioButton* csv;
    QRadioButton* html;
    QPushButton* exit;
    QPushButton* next;
    MainGUI* main;

    void welcomeSignSlot();
    void startApp();
};

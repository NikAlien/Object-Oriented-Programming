#pragma once
#include <QWidget>
#include <QLabel>
#include <QtWidgets/QPushButton>
#include "Service.h"

class SlideShow : public QWidget {
    Q_OBJECT

public:
    SlideShow(QWidget* parent = 0);
    void initGUI();
    void displayDog(const Dog* d, int index, int total);

private:
    QLabel* label;
    QLabel* dogLabel;
    QPushButton* exit;
    QPushButton* action;
    QPushButton* next;
    QPushButton* prev;

    void slideSignSlot();

signals:
    void goBack();
    void nextSlide();
    void prevSlide();
    void change();

};

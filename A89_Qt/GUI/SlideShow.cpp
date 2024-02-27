//
// Created by Carp Nicoleta on 04.06.2023.
//

#include <QGridLayout>
#include <QLabel>
#include <QImage>
#include "Dog.h"
#include "SlideShow.h"

SlideShow::SlideShow(QWidget *parent) : QWidget(parent) {
    this->initGUI();
    this->slideSignSlot();
}

void SlideShow::initGUI() {
    auto* gridLayout = new QGridLayout(this);
    auto* hLay = new QHBoxLayout();
    this->setWindowTitle("Slide Show");

    //Take image from my computer (need to find out how to download from online sources)
    label = new QLabel();

    dogLabel = new QLabel();
    QFont font("Skia", 20);
    dogLabel->setFont(font);
    gridLayout->addWidget(label, 0, 0, 5, 1);
    gridLayout->addWidget(dogLabel, 1, 1, Qt::AlignCenter);
    action = new QPushButton();
    gridLayout->addWidget(action, 2, 1);

    prev = new QPushButton("<-");
    hLay->addWidget(prev);
    next = new QPushButton("->");
    hLay->addWidget(next);
    gridLayout->addLayout(hLay, 3, 1);
    exit = new QPushButton("Exit");
    gridLayout->addWidget(exit, 4, 1);
}

void SlideShow::slideSignSlot() {
    QObject::connect(exit, &QPushButton::clicked, this, &SlideShow::goBack);
    QObject::connect(next, &QPushButton::clicked, this, &SlideShow::nextSlide);
    QObject::connect(prev, &QPushButton::clicked, this, &SlideShow::prevSlide);
    QObject::connect(action, &QPushButton::clicked, this, &SlideShow::change);
}

void SlideShow::displayDog(const Dog* d, int index, int total) {
    std::string format;
    format.append(d->getName());
    format.append("\n");
    format.append(d->getBreed());
    format.append(", ");
    format.append(std::to_string(d->getAge()));
    format.append(" y/o \n\npage - ");
    format.append(std::to_string(index));
    format.append("/");
    format.append(std::to_string(total));
    format.append("\n");
    dogLabel->setText(format.c_str());

    if(d->getFlag() == "false")
        action->setText("Adopt");
    else
        action->setText("Delete");

    std::string formPhoto = "photos/";
    formPhoto.append(d->getBreed());
    formPhoto.append(".jpeg");
    QImage* rawImage = new QImage(formPhoto.c_str(), "jpeg");
    QImage imageOfPhoto = rawImage->scaled(400, 400);
    QPixmap img = QPixmap::fromImage(imageOfPhoto);
    label->setPixmap(img);
    label->setMaximumSize(img.size());
}



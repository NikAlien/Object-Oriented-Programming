//
// Created by Carp Nicoleta on 02.06.2023.
//

#include <QVBoxLayout>
#include <QLabel>
#include "MainGUI.h"
#include "HTMLAdoptList.h"

MainGUI::MainGUI(FileAdoptList* f, QWidget *parent) : file(f), QWidget(parent) {
//    adminGui = new AdminGUI(f);
//    userGui = new UserGUI(f);
    this->initGUI();
    this->mainSignSlot();
}

void MainGUI::initGUI() {

    auto* layout = new QVBoxLayout(this);
    auto* label = new QLabel("MAIN MENU");
    QFont font("Skia", 20);
    font.setBold(true);
    label->setFont(font);
    QPixmap image("photos/img_dog.png");
    image.setDevicePixelRatio(4);
    auto *imageLabel = new QLabel();
    imageLabel->setPixmap(image);


    auto* hLayout = new QHBoxLayout();
    admin = new QPushButton("Admin");
    user = new QPushButton("User");
    hLayout->addWidget(admin);
    hLayout->addWidget(user);

    exit = new QPushButton("Exit");
    layout->addWidget(label, 0 ,Qt::AlignCenter);
    layout->addWidget(imageLabel, 0, Qt::AlignCenter);
    layout->addLayout(hLayout);
    layout->addWidget(exit);
    this->setFixedSize(layout->sizeHint());
}

void MainGUI::mainSignSlot() {
    QObject::connect(admin, &QPushButton::clicked, this, &MainGUI::goToAdmin);
    QObject::connect(user, &QPushButton::clicked, this, &MainGUI::goToUser);
    QObject::connect(exit, &QPushButton::clicked, this, [&](){this->close();});
}

void MainGUI::goToAdmin() {
    this->hide();
    adminGui = new AdminGUI(file);
    adminGui->show();
    QObject::connect(adminGui, &AdminGUI::goBack, this, [&](){adminGui->close();
        this->show();});
}

void MainGUI::goToUser() {
    this->hide();
    userGui = new UserGUI(file);
    userGui->show();
    QObject::connect(userGui, &UserGUI::goBack, this, [&](){userGui->close();
        this->show();});
}

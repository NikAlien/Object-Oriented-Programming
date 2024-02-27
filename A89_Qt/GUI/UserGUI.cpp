//
// Created by Carp Nicoleta on 03.06.2023.
//

#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QThread>
#include "UserGUI.h"
#include "Service.h"
#include "RepoException.h"

UserGUI::UserGUI(FileAdoptList* f, QWidget *parent) : QWidget(parent) {
    DogValidator d;
    this->servUser = new Service(f, d);
    showSlide = new SlideShow();
    this->initGUI();
    this->populateList();
    this->userSignSlot();
}

void UserGUI::initGUI() {
    auto* gridLayout = new QGridLayout(this);
    this->setWindowTitle("User");

    filterBreed = new QComboBox();
    std::vector<std::string> breeds = {"All", "husky", "chihuahua", "labrador", "bulldog", "shiba inu", "saluki",
                                       "corgi", "laika", "golden retriever", "pomeranian"};
    for(int i = 0; i < breeds.size(); i++)
        filterBreed->insertItem(i, breeds[i].c_str());

    filterAge = new QComboBox();
    for(int i = 0; i < 21; i++)
        filterAge->insertItem(i, std::to_string(i).c_str());

    gridLayout->addWidget(filterBreed, 1, 1);
    gridLayout->addWidget(filterAge, 2, 1);
    search = new QPushButton("Search");
    gridLayout->addWidget(search, 3, 1);
    file = new QPushButton("File");
    gridLayout->addWidget(file, 4, 1);
    exit = new QPushButton("Exit");
    gridLayout->addWidget(exit, 5, 1);

    dogList = new QListWidget();
    auto* header = new QLabel("ADOPTED DOGS:");
    QFont font("Skia", 20);
    font.setBold(true);
    header->setFont(font);

    gridLayout->addWidget(header, 0, 0);
    dogList->setMinimumSize(300, 100);
    gridLayout->addWidget(dogList, 1, 0, 6, 1);
    this->setFixedSize(gridLayout->sizeHint());
}

void UserGUI::userSignSlot() {
    QObject::connect(exit, &QPushButton::clicked, this, &UserGUI::goBack);
    QObject::connect(file, &QPushButton::clicked, this, &UserGUI::displayFile);
    QObject::connect(search, &QPushButton::clicked, this, &UserGUI::slideShowFilter);
}

void UserGUI::populateList() {
    dogList->clear();
    std::vector<Dog> list = *(this->servUser->getDogList());

    std::string format;
    for(const auto & i : list)
    {
        if(i.getFlag() == "true") {
            format.clear();
            format.append(i.getName());
            format.append(" - ");
            format.append(i.getBreed());
            format.append(", ");
            format.append(std::to_string(i.getAge()));
            format.append(" y/o\n");
            new QListWidgetItem(format.c_str(), dogList);
        }
    }
}

void UserGUI::displayFile() {
    try {
        this->servUser->openAdoptList();
    }
    catch(FileException& e)
    {
        QMessageBox msgBox;
        msgBox.setText(e.getErrors().c_str());
        msgBox.exec();
    }
}

void UserGUI::slideShowFilter() {
    std::string breed, age;

    breed = filterBreed->currentText().toStdString();
    age = filterAge->currentText().toStdString();
    if(breed == "All")
    {
        dogFilterList.clear();
        index = 0;
        dogFilterList = this->servUser->createListUser("", "-1");
        if(dogFilterList.empty()) {
            QMessageBox msgBox;
            msgBox.setText("!!! No dogs were found !!!");
            msgBox.exec();
        }
        else {
            this->hide();
            this->slideDisplay();
        }
    }
    else
    {
        dogFilterList.clear();
        index = 0;
        dogFilterList = this->servUser->createListUser(breed, age);
        if(dogFilterList.empty()) {
            QMessageBox msgBox;
            msgBox.setText("!!! No dogs were found !!!");
            msgBox.exec();
        }
        else {
            this->hide();
            this->slideDisplay();
        }
    }
}

void UserGUI::slideDisplay() {
    showSlide->show();
    showSlide->displayDog(&dogFilterList[index], index + 1, dogFilterList.size());
    QObject::connect(showSlide, &SlideShow::goBack, this, [&]() {
        showSlide->hide();
        this->show();
    });
    QObject::connect(showSlide, &SlideShow::nextSlide, this, [&]() {
        if (index == dogFilterList.size() - 1)
            index = 0;
        else
            index++;
        showSlide->displayDog(&dogFilterList[index], index + 1, dogFilterList.size());
    });
    QObject::connect(showSlide, &SlideShow::prevSlide, this, [&]() {
        if (index == 0)
            index = (int) dogFilterList.size() - 1;
        else
            index--;
        showSlide->displayDog(&dogFilterList[index], index + 1, dogFilterList.size());
    });
    QObject::connect(showSlide, &SlideShow::change, this, [&]() {
        servUser->setAdopted(dogFilterList[index].getName());
        if(dogFilterList[index].getFlag() == "false")
            dogFilterList[index].setFlag("true");
        else
            dogFilterList[index].setFlag("false");
        showSlide->displayDog(&dogFilterList[index], index + 1, dogFilterList.size());
        this->populateList();
    });
}


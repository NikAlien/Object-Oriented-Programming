//
// Created by Carp Nicoleta on 03.06.2023.
//

#include <QGridLayout>
#include <QLabel>
#include "AdminGUI.h"
#include "RepoException.h"
#include <vector>
#include <QMessageBox>
#include "string"

AdminGUI::AdminGUI(FileAdoptList* f, QWidget* parent) : QWidget(parent){
    DogValidator d;
    this->servAdmin = new Service(f, d);
    this->initGUI();
    this->populateList();
    this->adminSignSlot();
}

void AdminGUI::initGUI() {

    auto* gridLayout = new QGridLayout(this);
    this->setWindowTitle("Administrator");
    addButton = new QPushButton("Add");
    gridLayout->addWidget(addButton, 4, 4);
    deleteButton = new QPushButton("Delete");
    gridLayout->addWidget(deleteButton, 2, 4);
    updButton = new QPushButton("Update");
    gridLayout->addWidget(updButton, 3, 4);
    exit = new QPushButton("Exit");
    gridLayout->addWidget(exit, 0, 4);

    name = new QLineEdit;
    name->setPlaceholderText("Name");
    breed = new QLineEdit;
    breed->setPlaceholderText("Breed");
    age = new QLineEdit;
    age->setPlaceholderText("Age");
    photo = new QLineEdit;
    photo->setPlaceholderText("Photo");
    gridLayout->addWidget(name, 4, 0);
    gridLayout->addWidget(breed, 4, 1);
    gridLayout->addWidget(age, 4, 2);
    gridLayout->addWidget(photo, 4, 3);

    dogList = new QListWidget();
    auto* header = new QLabel("THE DOGS:");
    QFont font("Skia", 20);
    font.setBold(true);
    header->setFont(font);

    gridLayout->addWidget(header, 0, 0, 1, 4);
    dogList->setMinimumSize(500, 200);
    gridLayout->addWidget(dogList, 1, 0, 3, 4);
    this->setFixedSize(gridLayout->sizeHint());
}

void AdminGUI::adminSignSlot() {
    QObject::connect(exit, &QPushButton::clicked, this, &AdminGUI::goBack);
    QObject::connect(dogList, &QListWidget::itemSelectionChanged,this, &AdminGUI::listItemChanged);
    QObject::connect(addButton, &QPushButton::clicked, this, &AdminGUI::addDogRecord);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteDogRecord);
    QObject::connect(updButton, &QPushButton::clicked, this, &AdminGUI::updateDogRecord);
}

void AdminGUI::populateList() {
    dogList->clear();
    std::vector<Dog> list = *(servAdmin->getDogList());

    std::string format;
    for(int i = 0; i < list.size(); i++)
    {
        format.clear();
        format.append(list[i].getName());
        format.append(" - ");
        format.append(list[i].getBreed());
        format.append(", ");
        format.append(std::to_string(list[i].getAge()));
        format.append(" y/o\n    ");
        format.append(list[i].getPhotograph());
        format.append("\n");
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(format.c_str());
        dogList->addItem(item);
    }
}

void AdminGUI::addDogRecord() {
    std::string b, n, a, p;

    b = breed->text().toStdString();
    n = name->text().toStdString();
    a = age->text().toStdString();
    p = photo->text().toStdString();
    Service::makeNameValid(n);
    Service::makeLinkValid(p);

    if(b.size() == 0 || n.size() == 0 || a.size() == 0 || p.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("One of the cases is empty, please fill up all requirements!");
        msgBox.exec();
    }
    else{
        try {
            servAdmin->addDogToList(b, n, a, p);
            this->populateList();
            breed->clear();
            name->clear();
            age->clear();
            photo->clear();
        }
        catch (DogException& e)
        {
            QMessageBox msgBox;
            std::string format = "<p align='center'>";
            for (auto error : e.getErrors()) {
                format.append(error);
                format.append("<br>");
            }
            format.append("</p>");
            msgBox.setText(format.c_str());
            msgBox.exec();
        }
        catch (FileException& e)
        {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
        catch (RepoException& e)
        {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
    }
}

void AdminGUI::listItemChanged() {
    int index = dogList->currentRow();
    if (index < 0)
        return;


    std::vector<Dog> list = *(servAdmin->getDogList());
    Dog d = list[index];
    name->setText(QString::fromStdString(d.getName()));
    breed->setText(QString::fromStdString(d.getBreed()));
    photo->setText(QString::fromStdString(d.getPhotograph()));
    age->setText(QString::fromStdString(std::to_string(d.getAge())));
}

void AdminGUI::deleteDogRecord() {
    std::string n;
    n = name->text().toStdString();
    Service::makeNameValid(n);

    if(n.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("The name case is empty, please fill it out!");
        msgBox.exec();
    }
    else {
        try {
            this->servAdmin->removeDogFromList(n);
            this->populateList();
            breed->clear();
            name->clear();
            age->clear();
            photo->clear();
        }
        catch (FileException &e) {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
        catch (RepoException &e) {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
    }
}

void AdminGUI::updateDogRecord() {
    std::string n, a, p;

    n = name->text().toStdString();
    a = age->text().toStdString();
    p = photo->text().toStdString();
    Service::makeNameValid(n);

    if(n.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("The name case is empty, please fill it out!");
        msgBox.exec();
    }
    else if(a.size() == 0 && p.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("The age and photo cases are both empty, please fill it out!");
        msgBox.exec();
    }
    else{
        try {
            if(a.size() != 0)
                this->servAdmin->updateDogAge(n, a);
            if(p.size() != 0) {
                Service::makeLinkValid(p);
                this->servAdmin->updateDogPhoto(n, p);
            }
            this->populateList();
            breed->clear();
            name->clear();
            age->clear();
            photo->clear();
        }
        catch (DogException& e)
        {
            QMessageBox msgBox;
            std::string format = "<p align='center'>";
            for (auto error : e.getErrors()) {
                format.append(error);
                format.append("<br>");
            }
            format.append("</p>");
            msgBox.setText(format.c_str());
            msgBox.exec();
        }
        catch (FileException& e)
        {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
        catch (RepoException& e)
        {
            QMessageBox msgBox;
            msgBox.setText(e.getErrors().c_str());
            msgBox.exec();
        }
    }
}


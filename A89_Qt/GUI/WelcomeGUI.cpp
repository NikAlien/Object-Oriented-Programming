//
// Created by Carp Nicoleta on 03.06.2023.
//

#include <QVBoxLayout>
#include <QLabel>
#include "WelcomeGUI.h"
#include "FileAdoptList.h"
#include "HTMLAdoptList.h"
#include "CSVAdoptList.h"
#include "DogValidator.h"
#include "Service.h"

WelcomeGUI::WelcomeGUI(QWidget *parent) {
    this->initGUI();
    this->welcomeSignSlot();
}

void WelcomeGUI::initGUI() {
    auto* layout = new QVBoxLayout(this);
    auto* label1 = new QLabel("-- WELCOME --");
    QFont font("Skia", 20);
    font.setBold(true);
    label1->setFont(font);

    auto* label2 = new QLabel("Adopt A Dog!");
    QFont font2("Skia", 15);
    font2.setBold(true);
    label2->setFont(font2);

    auto* vLayout = new QVBoxLayout();
    radioList = new QGroupBox();
    csv = new QRadioButton(tr("CSV File"));
    html = new QRadioButton(tr("HTML File"));
    csv->setChecked(true);
    vLayout->addWidget(csv);
    vLayout->addWidget(html);
    radioList->setLayout(vLayout);

    auto* hLayout = new QHBoxLayout();
    exit = new QPushButton("Exit");
    next = new QPushButton("Next");
    hLayout->addWidget(exit);
    hLayout->addWidget(next);

    layout->addWidget(label1, 0, Qt::AlignCenter);
    layout->addWidget(label2, 0, Qt::AlignCenter);
    layout->addWidget(radioList);
    layout->addLayout(hLayout);
    this->setFixedSize(layout->sizeHint());
}

void WelcomeGUI::welcomeSignSlot() {

    QObject::connect(exit, &QPushButton::clicked, this, [&](){ this->close();});
    QObject::connect(next, &QPushButton::clicked, this, &WelcomeGUI::startApp);
}

void WelcomeGUI::startApp() {

    FileAdoptList* point = nullptr;
    if(csv->isChecked())
        point = new CSVAdoptList("AdoptionList.csv", "Dogs.txt");
    else
        point = new HTMLAdoptList("AdoptionList.html", "Dogs.txt");
    main = new MainGUI(point);
    this->hide();
    main->show();
}

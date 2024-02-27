#include <QLabel>
#include "gui.h"
#include "./ui_gui.h"
#include "domain.h"

GUI::GUI(Service* s, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GUI), serv(s)
{
    ui->setupUi(this);
    this->displayList();
    this->signSlot();
}

GUI::~GUI()
{
    delete ui;
}

void GUI::displayList() {
    ui->docList->clear();
    std::vector<Document> list = serv->getDocList();

    for(int i = 0; i < list.size(); i++)
    {
        ui->docList->addItem(list[i].toString().c_str());
    }
}

void GUI::signSlot() {

    QObject::connect(ui->searchEdit, &QLineEdit::textChanged, this, &GUI::filter);
    QObject::connect(ui->showBest, &QPushButton::clicked, this, &GUI::matching);

}

void GUI::filter() {
    std::string search = ui->searchEdit->text().toStdString();
    if(search.size() == 0)
    {
        this->displayList();
    } else
    {
        ui->docList->clear();
        std::vector<Document> list = serv->filterDocList(search);

        for(int i = 0; i < list.size(); i++)
        {
            ui->docList->addItem(list[i].toString().c_str());
        }
    }
}

void GUI::matching() {
    std::string search = ui->searchEdit->text().toStdString();
    Document d = serv->bestMatching(search);
    std::string doc;

    if(d.getName().size() == 0)
        doc.append("No best matching exists");
    else
    {
        doc.append("The Best Matching is:\n    ");
        doc.append(d.toString());
    }

    QLabel* label = new QLabel(doc.c_str());
    label->show();
}


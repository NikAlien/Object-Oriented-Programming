#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "gui.h"
#include "./ui_gui.h"

GUI::GUI(Service& serv,BacteriaModel& b, Biologist& bio, QWidget *parent)
    : serv(serv), model(b), biol(bio), QMainWindow(parent), ui(new Ui::GUI)
{
    ui->setupUi(this);
//    populateList();
    signSlot();
    this->setWindowTitle(biol.getName().c_str());
    ui->comboBox->addItem("All");
    for(int i = 0; i < biol.getSpecies().size(); i++)
        ui->comboBox->addItem(biol.getSpecies()[i].c_str());
}

GUI::~GUI()
{
    delete ui;
}

void GUI::filter() {
    std::string filt = ui->comboBox->currentText().toStdString();
    if(filt == "All")
        this->populateList();
    else {
        QSortFilterProxyModel *proxy = new QSortFilterProxyModel();
        proxy->setSourceModel(&model);
        proxy->setFilterRegularExpression(QRegularExpression(filt.c_str()));
        proxy->setFilterKeyColumn(1);
        ui->tableView->setModel(proxy);
    }

}

void GUI::signSlot() {
    QObject::connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &GUI::filter);
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &GUI::add);
}

void GUI::populateList() {
    auto* proxy = new QSortFilterProxyModel();
    proxy->setSourceModel(&model);
    std::string expression;
    for(auto s : this->biol.getSpecies())
    {
        expression.append(s);
        expression.append("|");
    }
    expression.pop_back();
    proxy->setFilterRegularExpression(QRegularExpression(expression.c_str()));
    proxy->setFilterKeyColumn(1);
    ui->tableView->setModel(proxy);
}

void GUI::add() {
    std::string name = ui->name->text().toStdString();
    std::string species = ui->species->text().toStdString();
    int size = ui->size->text().toInt();
    std::string dis = ui->disea->text().toStdString();

    ui->name->clear();
    ui->disea->clear();
    ui->size->clear();
    ui->species->clear();
    try
    {
        serv.addBacteria(name, species, size, dis);
    }
    catch (std::runtime_error& ru)
    {
        QMessageBox error;
        error.setText(ru.what());
        error.exec();
    }

}



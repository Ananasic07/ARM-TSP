#include "information.h"
#include "ui_information.h"

Information::Information(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    this ->db = db;
    model = new QSqlTableModel(this, *db);

    model->setTable("information");
    model->select();
    // установка "шаблона" в виджет
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnHidden(0, true);
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
}


void Information::on_pushButton_2_clicked()
{
     model->removeRow(row);
}


void Information::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void Information::on_pushButton_3_clicked()
{
    model->sort(2,Qt::AscendingOrder);
}


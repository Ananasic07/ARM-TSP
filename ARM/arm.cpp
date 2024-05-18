#include "arm.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Nastya/Desktop/ARM/ARM.db");
    if (!db.open())
    {
        ui->statusbar->showMessage("error: " + db.lastError().databaseText());
    }
    else
    {
        ui->statusbar->showMessage("ok");
    }

    model = new QSqlTableModel(this, db);
    model->setTable("patients"); //выбор таблицы из базы данных
    model->lastError();
    this->createUI();
    ui->tableView->setModel(model); //добавляем информацию в таблицу
    ui->tableView->setColumnHidden(0, true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
}


void MainWindow::on_pushButton_3_clicked()
{
    model->removeRow(row);
}

void MainWindow::on_pushButton_4_clicked()
{
    model->sort(2,Qt::AscendingOrder);
}


void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице */
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    // Устанавливаем названия колонок в таблице с сортировкой данных
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(1,Qt::AscendingOrder);


}

void MainWindow::createUI()
{
    ui->tableView->setModel(model); // Устанавливаем модель на созданную таблицу


    ui->tableView->setColumnHidden(0, true); // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    model->select(); // Делаем выборку данных из таблицы
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void MainWindow::on_pushButton_clicked()
{
    Window = new Information(&db);
    Window -> show();
}


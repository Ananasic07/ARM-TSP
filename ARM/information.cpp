#include "information.h"
#include "ui_information.h"

Information::Information(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this); // Настройка пользовательского интерфейса Information
    this ->db = db; // Присваивание указателя на базу данных
    model = new QSqlTableModel(this, *db); // Создание нового объекта модели таблицы базы данных

    model->setTable("information"); // Установка таблицы "information" для модели
    model->select(); // Выборка данных из таблицы
    // установка "шаблона" в виджет
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents(); // Автоматическая подгонка размера колонок
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // Растяжение последней колонки на всю оставшуюся ширину
    ui->tableView->setColumnHidden(0, true); // Скрытие первой колонки (ID)
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    model->insertRow(model->rowCount()); // Вставка новой строки в конец модели
}


void Information::on_pushButton_2_clicked()
{
     model->removeRow(row); // Удаление строки с индексом row из модели
}


void Information::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row(); // Получение индекса строки, на которую было нажатие
}


void Information::on_pushButton_3_clicked()
{
    model->sort(2,Qt::AscendingOrder); // Сортировка модели по третьему столбцу (индекс 2) в возрастающем порядке
}


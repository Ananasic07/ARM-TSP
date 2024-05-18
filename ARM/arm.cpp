#include "arm.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Настройка пользовательского интерфейса MainWindow
    db = QSqlDatabase::addDatabase("QSQLITE"); // Добавление драйвера базы данных SQLite
    db.setDatabaseName("C:/Users/Nastya/Desktop/ARM/ARM.db"); // Установка имени файла базы данных
     // Если не удалось открыть базу данных
    if (!db.open())
    {
         // Показать сообщение об ошибке
        ui->statusbar->showMessage("error: " + db.lastError().databaseText());
    }
    else
    {
         // Показать сообщение об успешном открытии базы данных
        ui->statusbar->showMessage("ok");
    }

    model = new QSqlTableModel(this, db); // Создание нового объекта модели таблицы базы данных
    model->setTable("patients"); //выбор таблицы из базы данных
    model->lastError(); // Получение последней ошибки модели (если есть)
    this->createUI(); // Вызов функции createUI для создания пользовательского интерфейса
    ui->tableView->setModel(model); //добавляем информацию в таблицу
    ui->tableView->setColumnHidden(0, true); // Скрытие первой колонки (ID)

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount()); // Вставка новой строки в конец модели
}


void MainWindow::on_pushButton_3_clicked()
{
    model->removeRow(row); // Удаление строки с индексом row из модели
}

void MainWindow::on_pushButton_4_clicked()
{
    model->sort(2,Qt::AscendingOrder); // Сортировка модели по третьему столбцу (индекс 2) в возрастающем порядке

}


void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице */
    model = new QSqlTableModel(this); // Создание нового объекта модели таблицы базы данных
    model->setTable(tableName); // Установка имени таблицы для модели
    // Устанавливаем названия колонок в таблице с сортировкой данных
    // Устанавливаем названия колонок в таблице с сортировкой данных
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        // Установка заголовка для колонки i
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
     // Растяжение последней колонки на всю оставшуюся ширину
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    model->select(); // Делаем выборку данных из таблицы
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row(); // Получение индекса строки, на которую было нажатие
}


void MainWindow::on_pushButton_clicked()
{
     // Создание нового окна Information с передачей указателя на базу данных
    Window = new Information(&db);
     // Показать окно Information
    Window -> show();
}


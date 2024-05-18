#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase> // для работы с базами данных
#include <QSqlQuery> // для выполнения SQL-запросов
#include <QSqlError> // для обработки ошибок SQL
#include <QDebug> // для вывода отладочной информации
#include <QSqlTableModel> // для представления таблицы базы данных
#include <QSqlQueryModel> // для представления результатов SQL-запроса
#include <QSortFilterProxyModel> // для сортировки и фильтрации данных
#include <QDate> //для работы с датами
#include "information.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked(); // Слот для обработки нажатия кнопки добавить запись

    void on_pushButton_3_clicked(); // Слот для обработки нажатия кнопки удалить запись

    void on_pushButton_4_clicked(); // Слот для обработки нажатия кнопки обновить

    void on_tableView_clicked(const QModelIndex &index);// Слот для обработки нажатия на ячейку таблицы

    void on_pushButton_clicked(); // Слот для обработки нажатия кнопки информация о пациентах

private:
    Ui::MainWindow *ui;
    QSqlDatabase db; // Объект базы данных
    QSqlTableModel *model; // Указатель на модель таблицы базы данных
    QSqlQuery *query; // Указатель на объект SQL-запроса
    int row; // номер активной строки
    void setupModel(const QString &tableName, const QStringList &headers); // Функция для настройки модели
    void createUI(); // Функция для создания пользовательского интерфейса
    Information *Window;


};
#endif // MAINWINDOW_H

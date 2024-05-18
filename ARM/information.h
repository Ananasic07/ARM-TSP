#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog> //для создания диалоговых окон
#include <QSqlDatabase> //для работы с базами данных
#include <QSqlQuery> //для выполнения SQL-запросов
#include <QSqlQueryModel> //для представления результатов SQL-запроса
#include <QSqlTableModel> //для представления таблицы базы данных


namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QSqlDatabase *db, QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_pushButton_clicked(); // Слот для обработки нажатия кнопки добавить пациента

    void on_pushButton_2_clicked(); // Слот для обработки нажатия кнопки удалить пациента

    void on_tableView_clicked(const QModelIndex &index);// Слот для обработки нажатия на ячейку таблицы

    void on_pushButton_3_clicked(); // Слот для обработки нажатия кнопки обновить

private:
    Ui::Information *ui;
    QSqlDatabase *db; // Указатель на объект базы данных
    QSqlTableModel *model; // Указатель на модель таблицы базы данных
    int row; // Номер активной строки
};

#endif // INFORMATION_H

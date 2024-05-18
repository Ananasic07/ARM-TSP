#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>


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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::Information *ui;
    QSqlDatabase *db;
    QSqlTableModel *model;
    int row;
};

#endif // INFORMATION_H

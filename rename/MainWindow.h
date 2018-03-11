/***********************************************************************
*
*文件名 ： MainWindow.h
*摘要 ：
*
*
*创建人: ErMao
*创建时间 ：2018/3/10
*
*
*历史版本
*
*序号   修改日期        版本号            修改人             摘要
*01     2018/3/10       V1.0.0         ErMao          创建
**********************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ChooseDir_pushButton_clicked();

    void on_Start_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

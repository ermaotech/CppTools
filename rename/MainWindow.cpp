/***********************************************************************
*
*文件名 ： MainWindow.cpp
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
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "FileOperation.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChooseDir_pushButton_clicked()
{
    QString ChooseDir = QFileDialog::getExistingDirectory(this);
    ui->Files_lineEdit->setText(ChooseDir);
}

void MainWindow::on_Start_pushButton_clicked()
{
    QString dir = ui->Files_lineEdit->text();
    QString suffix = ui->Suffix_lineEdit->text();
    if (dir.isEmpty() || suffix.isEmpty()) {
        QMessageBox mb(QMessageBox::Warning, tr("警告"), "目录或后缀不能为空");
        mb.exec();
    }else {
        FileOperation fo(dir.toStdString(), suffix.toStdString());
        fo.RenameFile();
        if (fo.error_code() == -1) {
            QMessageBox mb(QMessageBox::Warning, tr("警告"), fo.err_msg().c_str());
            mb.exec();
        }
        else {
            QString str = "共有"+QString::number(fo.Count()) +"个文件名后缀被修改";
            QMessageBox mb(QMessageBox::Information, tr("提示"), str);
            mb.exec();
        }
    }
}

/***********************************************************************
*
*文件名 ： main.cpp
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
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("C:\\Users\\hamab\\Downloads\\memo.png")); // アプリアイコンの設定
    w.show();
    return a.exec();
}

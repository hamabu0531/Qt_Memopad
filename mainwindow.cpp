#include "mainwindow.h"
#include "./ui_mainwindow.h"

// コンストラクタ
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QActionの管理
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionSelect_All, &QAction::triggered, this, &MainWindow::Select_All);
    connect(ui->actionDeselect, &QAction::triggered, this, &MainWindow::DeSelect);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::Copy);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::Cut);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::Paste);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::SaveFile);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::LoadFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textdata->toPlainText();
    QMessageBox::information(this, "Text", text);
}

void MainWindow::Select_All()
{
    ui->textdata->selectAll();
}

void MainWindow::DeSelect()
{
    QTextCursor cursor = ui->textdata->textCursor();
    cursor.clearSelection();
    ui->textdata->setTextCursor(cursor);
}

void MainWindow::Cut()
{
    ui->textdata->cut();
}

void MainWindow::Copy()
{
    ui->textdata->copy();
}

void MainWindow::Paste()
{
    ui->textdata->paste();
}

void MainWindow::LoadFile()
{
    QMessageBox::information(this, "Load", "loadされました");
}

void MainWindow::SaveFile()
{
    QMessageBox::information(this, "Save", "saveされました");
}

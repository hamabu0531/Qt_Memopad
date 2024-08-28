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
    // QMessageBox::information(this, "Load", "loadされました");
    QString fileName = QFileDialog::getOpenFileName(this, "Load File", "", "Text Files (*.txt);;All Files (*)");
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "エラー", "ファイルの読み込みに失敗しました");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textdata->setPlainText(text);
    file.close();
    QMessageBox::information(this, "ロード完了", "読み込みに成功しました");
}

void MainWindow::SaveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "エラー", "ファイルのセーブに失敗しました");
        return;
    }
    QTextStream out(&file);
    out << ui->textdata->toPlainText();
    file.close();
    QMessageBox::information(this, "セーブ完了", "セーブに成功しました");
}

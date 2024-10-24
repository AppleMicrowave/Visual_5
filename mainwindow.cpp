
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "textmanager.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionSearch_triggered()
{
    // Получить строку от пользователя
    QString userInput = QInputDialog::getText(nullptr, "Input string", "Enter search string:");
    TextManager::search(userInput, ui->textEdit);

}


void MainWindow::on_actionReplace_triggered()
{
    QString userInputFind = QInputDialog::getText(nullptr, "Input string", "Enter search string:");
    QString userInputReplace = QInputDialog::getText(nullptr, "Input string", "Enter replace string:");
    TextManager::replace(userInputFind, userInputReplace, ui->textEdit);

}


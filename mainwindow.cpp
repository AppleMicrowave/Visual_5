
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



QString copyText;

void MainWindow::on_actionSearch_triggered()
{
    QString userInput = QInputDialog::getText(nullptr, "Input string", "Enter search string:");
    TextManager::search( ui->textEdit, userInput);
}


void MainWindow::on_actionReplace_triggered()
{
    QString userInputFind = QInputDialog::getText(nullptr, "Input string", "Enter search string:");
    QString userInputReplace = QInputDialog::getText(nullptr, "Input string", "Enter replace string:");
    TextManager::replace(ui->textEdit, userInputFind, userInputReplace);
}


void MainWindow::on_actionClear_triggered()
{
    TextManager::clear(ui->textEdit);
}


void MainWindow::on_actionCopy_triggered()
{
    copyText = TextManager::copy(ui->textEdit);
}


void MainWindow::on_actionPaste_triggered()
{

    TextManager::paste(ui->textEdit, copyText);
}


void MainWindow::on_actionDecorate_triggered()
{
    TextManager::decorate(ui->textEdit);
}


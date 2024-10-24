#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "textmanager.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTextEdit>

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
    // userInput = QInputDialog::getText(this, tr("Вопрос"), tr("Введите значение"));
    QString userInput = QInputDialog::getText(nullptr, "Ввод строки", "Введите строку для поиска:");
    TextManager::search(userInput, ui->textEdit);


    //  if (!userInput.isEmpty()) {
    //     QTextCursor cursor = ui->textEdit->textCursor();
    //     cursor.movePosition(QTextCursor::Start);
    //    QTextCursor foundCursor = ui->textEdit->document()->find(userInput, cursor);
    //     if (!foundCursor.isNull()) {
    //     ui->textEdit->setTextCursor(foundCursor);
    //         QMessageBox::information(nullptr, "Результат", "Первое вхождение строки найдено.");
    //    } else {
    //         QMessageBox::information(nullptr, "Результат", "Строка не найдена.");
    // }
    // }

}


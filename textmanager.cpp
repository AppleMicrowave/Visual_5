#include <QTextEdit>
#include <QString>
#include <QMessageBox>

#include "textmanager.h"
#include "./ui_mainwindow.h"



void TextManager::search(const QString& searchText, QTextEdit* textEdit) {
     if (!searchText.isEmpty()) {
        QTextCursor cursor = textEdit->textCursor();
        cursor.movePosition(QTextCursor::Start);
       QTextCursor foundCursor = textEdit->document()->find(searchText, cursor);
        if (!foundCursor.isNull()) {
        textEdit->setTextCursor(foundCursor);
            QMessageBox::information(nullptr, "Result", "First occurrence of string found.");
       } else {
            QMessageBox::information(nullptr, "Result", "String not found.");
        }
       }
       else {
           QMessageBox::information(nullptr, "Result", "Search string empty");
       }
}


void TextManager::replace(const QString& findText, const QString& replaceText, QTextEdit* textEdit) {
    QTextCursor cursor = textEdit->textCursor();
    cursor.setPosition(0); // Начинаем поиск с начала документа
    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = textEdit->document()->find(findText, cursor);
        if (!cursor.isNull()) {
            // Выделяем найденный текст
            cursor.select(QTextCursor::WordUnderCursor);
            // Заменяем выделенный текст
            textEdit->setTextCursor(cursor);
            textEdit->insertPlainText(replaceText);
        }
    }
}

void TextManager::clear(QTextEdit* textEdit){
    textEdit->setText("");
}

#include <QTextEdit>
#include <QString>
#include <QMessageBox>
#include <QFile>

#include "textmanager.h"
#include "./ui_mainwindow.h"



void TextManager::search(QTextEdit* textEdit, const QString& searchText) {
    if (!searchText.isEmpty()) {
        QTextCursor cursor = textEdit->textCursor();
        cursor.movePosition(QTextCursor::Start);
        QTextCursor foundCursor = textEdit->document()->find(searchText, cursor);
        if (!foundCursor.isNull()) {
            textEdit->setTextCursor(foundCursor);
            QMessageBox::information(nullptr, "Result", "First occurrence of string found.");
            }
        else {
            QMessageBox::information(nullptr, "Result", "String not found.");
            }
       }
       else {
           QMessageBox::information(nullptr, "Result", "Search string empty");
       }
}


void TextManager::replace(QTextEdit* textEdit, const QString& findText, const QString& replaceText) {
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


QString TextManager::copy(QTextEdit* textEdit){
    // Получаем текущий курсор QTextEdit
    QTextCursor cursor = textEdit->textCursor();

    // Проверяем, выделен ли текст
    if (cursor.hasSelection()) {
        // 3. Если текст выделен, возвращаем выделенный текст
        return cursor.selectedText();
    }
    else {
        // 4. Если текст не выделен, возвращаем пустую строку
        return QString();
    }
}

void TextManager::paste(QTextEdit* textEdit, const QString& textToPaste){
    // 1. Получаем текущий курсор QTextEdit
    QTextCursor cursor = textEdit->textCursor();

    if (!textToPaste.isEmpty()){
        // 2. Вставляем текст в позицию курсора
        cursor.insertText(textToPaste);
    }
}




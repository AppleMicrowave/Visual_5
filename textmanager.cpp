#include <QTextEdit>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QFontDialog>
#include <QColorDialog>
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


void TextManager::decorate(QTextEdit* textEdit){
    // Получаем текущий текстовый редактор

    // Получаем текущий шрифт выделенного текста
    QFont currentFont = textEdit->currentFont();

    // Вызываем диалог выбора шрифта
    bool ok;
    QFont font = QFontDialog::getFont(&ok, currentFont);
    if (ok) {
        // Если пользователь нажал "ОК", вызываем диалог выбора цвета
        QColor currentColor = textEdit->textColor();
        QColor color = QColorDialog::getColor(currentColor);
        if (color.isValid()) {
            // Если пользователь выбрал цвет, применяем выбранный шрифт и цвет к выделенному тексту
            QTextCursor cursor = textEdit->textCursor();
            QTextCharFormat format = cursor.charFormat();
            format.setFont(font);
            format.setForeground(color);
            cursor.mergeCharFormat(format);
        }
    }
}

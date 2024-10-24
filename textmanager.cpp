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
            QMessageBox::information(nullptr, "Результат", "Первое вхождение строки найдено.");
       } else {
            QMessageBox::information(nullptr, "Результат", "Строка не найдена.");
    }
    }
}

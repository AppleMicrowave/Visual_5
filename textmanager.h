#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H


#include <QWidget>
#include <qtextedit.h>



class TextManager {
public:
    // Метод для поиска текста в QTextEdit
    static void search(QTextEdit* textEdit, const QString& searchText);

    // Метод замены
    static void replace(QTextEdit* textEdit,const QString& findText, const QString& replaceText);

    // Метод очистки
    static void clear(QTextEdit* textEdit);

    // Метод возврата


    // Метод копирования
    static QString copy(QTextEdit* textEdit);

    // Метод вставки
    static void paste(QTextEdit* textEdit, const QString& textToPaste);


};

#endif // TEXTMANAGER_H

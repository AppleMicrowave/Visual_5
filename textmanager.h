#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H


#include <QWidget>
#include <qtextedit.h>



class TextManager {
public:
    // Метод для поиска текста в QTextEdit
    static void search(const QString& searchText, QTextEdit* textEdit);

    // Метод замены
    static void replace(const QString& findText, const QString& replaceText, QTextEdit* textEdit);

    // Метод очистки
    static void clear(QTextEdit* textEdit);

    // Метод возврата


};

#endif // TEXTMANAGER_H

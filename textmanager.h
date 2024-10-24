#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H


#include <QWidget>
#include <qtextedit.h>



class TextManager {
public:

    // Метод для поиска текста в QTextEdit
    static void search(const QString& searchText, QTextEdit* textEdit);
    static void replace(const QString& findText, const QString& replaceText ,QTextEdit* textEdit);

};
#endif // TEXTMANAGER_H

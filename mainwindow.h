#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSearch_triggered();

    void on_actionReplace_triggered();

    void on_actionClear_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionDecorate_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

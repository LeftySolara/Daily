#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eventmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_Qt_triggered();

    void on_pushButtonCreate_clicked();

private:
    Ui::MainWindow *ui;
    EventModel *event_model;
};

#endif // MAINWINDOW_H

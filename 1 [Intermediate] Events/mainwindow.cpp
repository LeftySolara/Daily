#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialogaddevent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    event_model = new EventModel();

    ui->listView = new QListView();
    ui->listView->setModel(event_model);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete event_model;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_pushButtonCreate_clicked()
{
    DialogAddEvent *dialog = new DialogAddEvent();
    int result = dialog->exec();

    if (result == QDialog::Accepted) {
        event_model->add_event(dialog->name(), dialog->description(), dialog->dateTime());
        ui->listView->update();
    }

    delete dialog;
}

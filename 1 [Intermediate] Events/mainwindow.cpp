#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialogaddevent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    event_model = new EventModel();
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
        int row = event_model->rowCount();

        event_model->insertRows(row, 1);
        QModelIndex index = event_model->index(row);

        event_model->setData(index, dialog->name(), Event::NameRole);
        event_model->setData(index, dialog->description(), Event::DescriptionRole);
        event_model->setData(index, dialog->dateTime(), Event::DateTimeRole);

        ui->labelNameData->setText(dialog->name());
        ui->labelDescriptionData->setText(dialog->description());
        ui->labelDateTimeData->setText(dialog->dateTime().toString("ddd d MMM, H:mm A"));
    }

    delete dialog;
}

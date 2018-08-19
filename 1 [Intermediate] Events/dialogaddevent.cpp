#include "dialogaddevent.h"
#include "ui_dialogaddevent.h"

DialogAddEvent::DialogAddEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEvent)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDate(QDateTime::currentDateTime().date());
}

DialogAddEvent::~DialogAddEvent()
{
    delete ui;
}

void DialogAddEvent::on_buttonBox_accepted()
{
    this->close();
}

void DialogAddEvent::on_buttonBox_rejected()
{
    this->close();
}

QString DialogAddEvent::name()
{
    return ui->lineEditName->text();
}

QString DialogAddEvent::description()
{
    return ui->lineEditDescription->text();
}

QDateTime DialogAddEvent::dateTime()
{
    return ui->dateTimeEdit->dateTime();
}

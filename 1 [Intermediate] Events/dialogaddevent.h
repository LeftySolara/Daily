#ifndef DIALOGADDEVENT_H
#define DIALOGADDEVENT_H

#include <QDialog>

namespace Ui {
class DialogAddEvent;
}

class DialogAddEvent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddEvent(QWidget *parent = nullptr);
    ~DialogAddEvent();

    QString name();
    QString description();
    QDateTime dateTime();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogAddEvent *ui;
};

#endif // DIALOGADDEVENT_H

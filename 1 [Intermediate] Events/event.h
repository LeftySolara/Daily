#ifndef EVENT_H
#define EVENT_H

#include <QStandardItem>
#include <QString>
#include <QDateTime>

class Event : public QStandardItem
{
public:
    Event() {}

    virtual int type() const;
    virtual QVariant data(int role = NameRole) const;
    virtual void setdata(const QVariant &value, int role = NameRole);

    /* Role values below 0x0100 are reserved by Qt, so we start with UserRole */
    typedef enum {
        None = Qt::UserRole,
        NameRole,
        DescriptionRole,
        DateTimeRole
    } EventRole;

private:
    QString name;
    QString description;
    QDateTime date_time;
};

#endif // EVENT_H

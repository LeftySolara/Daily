#include "event.h"

/* Return the type of this item. This distinguishes Event from
 * other types derived from QStandardItem
 */
int Event::type() const
{
    return QStandardItem::UserType + 1;
}

QVariant Event::data(int role) const
{
    if (role == NameRole)
        return QVariant(this->name);
    else if (role == DescriptionRole)
        return QVariant(this->description);
    else if (role == DateTimeRole)
        return QVariant(this->date_time);
    else
        return QVariant();
}

void Event::setdata(const QVariant &value, int role)
{
    if (role == NameRole)
        this->name = value.toString();
    else if (role == DescriptionRole)
        this->description = value.toString();
    else if (role == DateTimeRole)
        this->date_time = value.toDateTime();
}

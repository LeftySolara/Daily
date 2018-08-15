#include "eventmodel.h"
#include <QAbstractItemModel>

EventModel::EventModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

EventModel::~EventModel()
{
    /* After Qt 5.7, capacity of vector is kept after calling clear().
     * We swap with a default-constructed vector to free the memory. */
    events.clear();
    QVector<Event *>().swap(events);
    Q_ASSERT(events.capacity() == 0);
}

int EventModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return events.size();
}

QVariant EventModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    else {
        Event *event = events.at(index.row());
        return event->data(role);
    }
}

bool EventModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        Event *event = events.at(index.row());
        event->setdata(value, role);
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags EventModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

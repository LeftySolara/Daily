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
        if (event != nullptr)
            return event->data(role);
        else
            return QVariant();
    }
}

bool EventModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        Event *event = events.at(index.row());
        if (event == nullptr)
            event = new Event();

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

bool EventModel::insertRows(int row, int count, const QModelIndex &parent)
{
    int old_size = events.size();

    beginInsertRows(parent, row, row + count - 1);
    events.resize(old_size + count);
    //for (int i = row; i < row + count; ++i) {
    //    Event *event = new Event();
    //    events.insert(events.size(), event);
    //}
    endInsertRows();

    return events.capacity() > old_size;
}

bool EventModel::removeRows(int row, int count, const QModelIndex &parent)
{
    int old_size = events.size();

    beginRemoveRows(parent, row, row + count - 1);
    for (int i = row; i < row + count; ++i) {
        delete events.at(row);
        events.removeAt(row);
    }
    events.resize(events.length());
    endRemoveRows();

    return events.size() < old_size;
}

void EventModel::add_event(QString name, QString description, QDateTime date_time)
{
    int row = rowCount();

    insertRows(row, 1);
    QModelIndex idx = index(row);

    if (events.at(row) == nullptr)
        events[row] = new Event();

    setData(idx, name, Event::NameRole);
    setData(idx, description, Event::DescriptionRole);
    setData(idx, date_time, Event::DateTimeRole);
}

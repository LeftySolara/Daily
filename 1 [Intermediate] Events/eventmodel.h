#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "event.h"

class EventModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit EventModel(QObject *parent = nullptr);
    ~EventModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    QVector<Event *> events;
};

#endif // EVENTMODEL_H

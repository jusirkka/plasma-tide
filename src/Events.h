#ifndef EVENTS_H
#define EVENTS_H

#include <QAbstractListModel>
#include <QtXml/QDomDocument>

#include "TideEvent.h"

namespace Tide {

class StationProvider;

class Events: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(double today READ today NOTIFY todayChanged)
    Q_PROPERTY(double delta READ delta NOTIFY deltaChanged)

public:

    enum EventRoles {
        EventIconRole = Qt::UserRole + 1,
        EventDescRole,
        EventTimestampRole
    };


public:

    // create new provider model
    Events(StationProvider* parent);

    //! Reimplemented from QAbstractItemModel
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

    //! Reimplemented from QAbstractItemModel
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    //! Reimplemented from QAbstractItemModel
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void forward();
    Q_INVOKABLE void rewind();
    Q_INVOKABLE void init(const QString& key, const QString& mark);

    ~Events();

    double today() {return m_Today;}
    double delta() {return m_Delta;}

signals:

    void todayChanged(double v);
    void deltaChanged(double v);

private:

    void computeEvents(int);

private:

    QString m_Station;
    QList<TideEvent> m_Events;
    StationProvider* m_Parent;
    double m_Today;
    double m_Delta;
    Amplitude m_Mark;
};

}
#endif

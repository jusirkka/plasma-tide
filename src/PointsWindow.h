#ifndef POINTSWINDOW_H
#define POINTSWINDOW_H

#include <QStackedWidget>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

#include "Timestamp.h"
#include "Address.h"

namespace Tide {

class Station;

class GraphFrame: public QwtPlot {
public:
    GraphFrame(const QString& name);

protected:

    QwtPlotCurve m_Orig, m_Gen;

};

class TimeDomain: public GraphFrame {
public:

    TimeDomain(const QString& station, const QVector<Timestamp>& stamps, const QVector<double>& orig, const QVector<double>& gen);

};


class FrequencyDomain: public GraphFrame {
public:

    FrequencyDomain(const QString& station, const QVector<Timestamp>& stamps, const QVector<double>& orig, const QVector<double>& gen);

};

class PointsWindow : public QStackedWidget {
public:

    PointsWindow(const Address& address, const Station& station);
    PointsWindow(int station_id);

protected:

    void mousePressEvent(QMouseEvent* ev);
    void keyPressEvent(QKeyEvent* ev);

private:


};

}

#endif // POINTSWINDOW_H

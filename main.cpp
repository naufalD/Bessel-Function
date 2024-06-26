#include "bessel.h"

#include <QApplication>
#include <QwtPlot>
#include <QwtPlotCurve>
#include <QwtPlotGrid>
#include <QwtSymbol>
#include <QwtLegend>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    QwtPlot plot;
    plot.setTitle( "Bessel Functions" );
    plot.setCanvasBackground( Qt::white );
    plot.setAxisScale( QwtAxis::YLeft, -1, 1.5 );
    plot.insertLegend( new QwtLegend() );

    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( &plot );

    for (int order {6};order<=10;++order){
        std::string strup {"order up "};
        strup.append(std::to_string(order));
        QString qstrup = QString::fromStdString(strup);

        QwtPlotCurve* curveup = new QwtPlotCurve();
        curveup->setTitle( qstrup );
        //curve->setPen( Qt::black, 2 ),
        curveup->setPen(QColor(Qt::GlobalColor(Qt::red+order)), 1);
        curveup->setCurveAttribute(QwtPlotCurve::Fitted, true);
        curveup->setRenderHint( QwtPlotItem::RenderAntialiased, true );
        QPolygonF pointsup;

        for (double x {0.005}; x<=12;x=x+0.005){
            pointsup << QPointF(x, alg_up(x, order)+0.5);
        }

        curveup->setSamples( pointsup );
        curveup->attach( &plot );
    }

    for (int order {6};order<=10;++order){
        std::string str {"order down "};
        str.append(std::to_string(order));
        QString qstr = QString::fromStdString(str);



        QwtPlotCurve* curve = new QwtPlotCurve();
        curve->setTitle( qstr );
        //curve->setPen( Qt::black, 2 ),
        curve->setPen(QColor(Qt::GlobalColor(Qt::blue+order)), 1);
        curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
        curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
        QPolygonF points;

        for (double x {0.005}; x<=12;x=x+0.005){
            points << QPointF(x, alg_down(x, order)-0.5);
        }
        curve->setSamples( points );
        curve->attach( &plot );
    }


    plot.resize( 600, 400 );
    plot.show();

    //w.show();
    return a.exec();
}

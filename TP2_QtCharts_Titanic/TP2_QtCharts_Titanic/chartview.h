#ifndef ABSTRACT_CHART_VIEW_H
#define ABSTRACT_CHART_VIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include <QHorizontalStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QGridLayout>
#include "data.h"

/**
 * @brief The AbstractChartView class to handle strategy
 * @author Fabrice Jaillet
 * @sa  PieChartView, BarChartView, MultiChartView
 */
class AbstractChartView
{
public:
    AbstractChartView() {}
    virtual ~AbstractChartView() {}
    /**
     * @brief getChartView
     * @param dbf: the data to be diaplyed (read from file)
     * @return a QWidget, containing the ChartView
     */
    virtual QWidget* getChartView(const Data& dbf) const =0;
};

/**
 * @brief The PieChartView class
 * @sa  AbstractChartView
 */
class PieChartView : public AbstractChartView
{
public:
    PieChartView() :AbstractChartView() {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

/**
 * @brief The BarChartView class
 * @sa  AbstractChartView
 */
class BarChartView : public AbstractChartView
{
public:
    BarChartView() :AbstractChartView()  {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

/**
 * @brief The MultiChartView class
 * @sa  AbstractChartView
 */
class MultiChartView : public AbstractChartView
{
public:
    MultiChartView() :AbstractChartView()  {}
    virtual QWidget* getChartView(const Data& dbf) const override;
};

#endif // ABSTRACT_CHART_VIEW_H

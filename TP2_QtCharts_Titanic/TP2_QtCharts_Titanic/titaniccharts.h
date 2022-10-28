/**
 * @file
 * @brief An elaborate application to discover Qt Charts facilities.
 * @author F. Jaillet
 * @date 18/10/2022
 *
 * This application will display data on passengers of the Titanic
 * Changing view on selecting item in a menu or toolbar.
 *
*/
#ifndef TITANICCHARTS_H
#define TITANICCHARTS_H

#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <memory> // for unique_ptr
#include "chartview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TitanicChartsClass; }
QT_END_NAMESPACE

/**
 * @brief The Main Application class.
 * Construct the View, and handle strategies to display results
 * @author Fabrice Jaillet
 * \sa QMainWindow, PieChartView, BarChartView, MultiChartView

 */
class TitanicCharts : public QMainWindow
{
    Q_OBJECT

private:
    /**
     * @brief chartview handles the View Strategy
     * It typically has to be set by setChartView(),
     * before we can call getChartView() on it
     * @sa setChartView, getChartView
     */
    std::unique_ptr<AbstractChartView> chartview;
    Ui::TitanicChartsClass *ui; /**< user interface, as a pointer (static by default inVS2022 project) */
    Data dbf; /**< where passenger data are stored, from dbf file */

public:
    /**
     * @brief TitanicCharts
     * @param filename: name of the file that contains Titanixc data, at dbf format
     * @param parent: parent widget
     */
    explicit TitanicCharts(const QString& filename=QString(), QWidget *parent = nullptr);

    ~TitanicCharts();

    /**
     * @brief setChartView
     * @param cv
     * @sa chartview, unique_ptr, move
     */
    void setChartView(std::unique_ptr<AbstractChartView> &&cv) {
        chartview = std::move(cv); }

private slots:

    void showPieChart();
    void showBarChart();
    void showMultiBarChart();

};

#endif // TITANICCHARTS_H

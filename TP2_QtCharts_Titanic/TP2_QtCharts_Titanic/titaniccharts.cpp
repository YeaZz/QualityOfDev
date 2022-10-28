#include "titaniccharts.h"
#include "ui_titanic.h"
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

#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
QT_CHARTS_USE_NAMESPACE
QT_USE_NAMESPACE
#endif

TitanicCharts::TitanicCharts(const QString& filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TitanicChartsClass),
    dbf(filename)
{
    ui->setupUi(this);

    connect(ui->actionRatioHF, &QAction::triggered, this, &TitanicCharts::showPieChart);
    connect(ui->actionCategorie, &QAction::triggered, this, &TitanicCharts::showBarChart);
    connect(ui->actionAgeCategorie, &QAction::triggered, this, &TitanicCharts::showMultiBarChart);

    //trigger first chart
    ui->actionRatioHF->trigger();
}

TitanicCharts::~TitanicCharts()
{
    delete ui;
}

/**
 * @brief TitanicCharts::showPieChart
 * will show the Male/Female ratoi as Pie chart
 * starts to set the build strategy in chartview
 * and use chartview strategy to construct the appropriate chart
 *
 * @note the use of unique_ptr (and std::move)
 * to avoid memory leak. Deleted when out of scope
 *
 */
void TitanicCharts::showPieChart() {

    setChartView(std::make_unique<PieChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}

/**
 * @brief TitanicCharts::showBarChart
 * will show survivors by categories
 * @sa TitanicCharts::showPieChart
 */
void TitanicCharts::showBarChart() {

    setChartView(std::make_unique<BarChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}

/**
 * @brief TitanicCharts::showMultiBarChart
 * will show 4 Views with different statistics
 * @sa TitanicCharts::showPieChart
 */
void TitanicCharts::showMultiBarChart() {

    setChartView(std::make_unique<MultiChartView>());
    setCentralWidget( chartview->getChartView(dbf));
}


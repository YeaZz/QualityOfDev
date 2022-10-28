#include "chartview.h"

#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
QT_CHARTS_USE_NAMESPACE
QT_USE_NAMESPACE
#endif

/**
 * @brief PieChartView::getChartView
 * @param dbf: data to be displayed
 * @return a Pie chartView,
 *  containing statistics for Male/Female ratio
 */
QWidget* PieChartView::getChartView(const Data &dbf) const {

    //initialize an array of 2 values, and zeroing it
    // alternative is to use resize after the declaration
    // or even a static array do the job: int HF[2]={0,0};
    QVector<int> HF(2,0);

    //Counting Male/Female population
    QPieSeries *series = new QPieSeries();
    for (auto d:dbf.getList()) {
        ++HF[d.getSex()];
    }
    //adding data to series
    series->append("F",HF[0]);
    series->append("H",HF[1]);

    //Some decoration to the PieChart
    //    QPieSlice *slice = series->slices().at(0);
    //    slice->setExploded();
    //    slice->setLabelVisible();
    //    slice->setPen(QPen(Qt::darkGreen, 2));
    //    slice->setBrush(Qt::green);

    //connecting the series to the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Proportions H/F");
    chart->setAnimationOptions(QChart::SeriesAnimations); // a nice animation!!
    //    chart->legend()->hide();

    //finally creating the Pie Chart View
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //to be set at CentralWidget
    return chartView;
}

/**
 * @brief BarChartView::getChartView
 * @param dbf: data to be displayed
 * @return a Bar chartView,
 *  containing statistics on Survivors by Category
 */
QWidget* BarChartView::getChartView(const Data &dbf) const {

    //initialize an array of 2 QBarSet
    QVector<QBarSet*> set(2,nullptr);

    //initialize the 2 sets
    set[0] = new QBarSet("Péri");
    set[1] = new QBarSet("Survécu");

    //defining a fixed size QVector 2x4, and zeroing
    // the trick is to declare 2 cells QVector of QVectors,
    // and initialize it with a 4 cells QVector containing zeros
    // again a static bidimensional array will do the job as well
    // int survived[2][4]={ {0,0,0,0},{0,0,0,0} };
    QVector< QVector<int> > survived(2, QVector<int>(4,0));
    for (auto d:dbf.getList()) {
        ++survived[d.getSurvived()][d.getClasse()];
    }

    //filling the series
    //set[i] contains survivors (or not) for each category of passenger
    QBarSeries *series = new QBarSeries();
    for (int i=0; i<2; ++i) {
        for (int j=0; j<4; ++j) {
            set[i]->append(survived[i][j]);
        }
        series->append(set[i]);
    }

    //connecting series to the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Survivants/Catégorie");
    chart->setAnimationOptions(QChart::SeriesAnimations); // a nice animation!!
    //    chart->legend()->hide();

    //axis X, 2 bars/category: survivors or not
    QStringList categories;
    categories << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //axis Y, population values for each bar
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //adding a legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //finally creating the Bar Chart View
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    //to be set at CentralWidget
    return chartView;
}

/**
 * @brief MultiChartView::getChartView
 * @param dbf: data to be displayed
 * @return a Multi chartView,
 *  containing a Grid of 4 Viewers, with differnts statistics
 */
QWidget* MultiChartView::getChartView(const Data &dbf) const {

    //for the whole view, define a common Theme
    QChart::ChartTheme theme = QChart::ChartThemeBlueCerulean;
    QChart::AnimationOption animation = QChart::AllAnimations;

    /**************************************************************************/
    /* Survivor / Category                                                    */
    /**************************************************************************/
    QBarSet* set00= new QBarSet("Population");

    QVector<int> population00(4,0);
    for (auto d:dbf.getList()) {
        ++population00[d.getClasse()];
    }

    QHorizontalBarSeries *series00 = new QHorizontalBarSeries();
    for (int i=0; i<4; ++i) {
        set00->append(population00[i]);
    }
    series00->append(set00);

    QChart *chart00 = new QChart();
    chart00->addSeries(series00);
    chart00->setTitle("Population/Catégorie");
    chart00->setAnimationOptions(animation);
    chart00->setTheme(theme);
    //    chart->legend()->hide();

    QStringList categories00;
    categories00 << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisY00 = new QBarCategoryAxis();
    axisY00->append(categories00);
    chart00->addAxis(axisY00, Qt::AlignLeft);
    series00->attachAxis(axisY00);

    QValueAxis *axisX00 = new QValueAxis();
    axisX00->setLabelFormat("%d");
    chart00->addAxis(axisX00, Qt::AlignBottom);
    series00->attachAxis(axisX00);

    chart00->legend()->setVisible(true);
    chart00->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView00 = new QChartView(chart00);
    chartView00->setRenderHint(QPainter::Antialiasing);

    /**************************************************************************/
    /* Survivant / Category                                                   */
    /**************************************************************************/
    QVector<QBarSet*> set01(2,nullptr);

    set01[0] = new QBarSet("Péri");
    set01[1] = new QBarSet("Survécu");

    QVector< QVector<int>> survived01(2, QVector<int>(4,0));
    for (auto d:dbf.getList()) {
        ++survived01[d.getSurvived()][d.getClasse()];
    }

    QHorizontalStackedBarSeries *series01 = new QHorizontalStackedBarSeries();
    for (int i=1; i>=0; --i) {
        for (int j=0; j<4; ++j) {
            set01[i]->append(survived01[i][j]);
        }
        series01->append(set01[i]);
    }

    QChart *chart01 = new QChart();
    chart01->addSeries(series01);
    chart01->setTitle("Survivants/Catégorie");
    chart01->setAnimationOptions(animation);
    chart01->setTheme(theme);
    //    chart->legend()->hide();

    QStringList categories01;
    categories01 << "Équipage" << "Première" << "Deuxième" << "Troisième";
    QBarCategoryAxis *axisY01 = new QBarCategoryAxis();
    axisY01->setReverse();
    axisY01->append(categories01);
    chart01->addAxis(axisY01, Qt::AlignLeft);
    series01->attachAxis(axisY01);

    QValueAxis *axisX01 = new QValueAxis();
    axisX01->setLabelFormat("%d");
    chart01->addAxis(axisX01, Qt::AlignBottom);
    series01->attachAxis(axisX01);

    chart01->legend()->setVisible(true);
    chart01->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView01 = new QChartView(chart01);
    chartView01->setRenderHint(QPainter::Antialiasing);

    /**************************************************************************/
    /* Population / Age                                                       */
    /**************************************************************************/
    QBarSet* set10= new QBarSet("Population");

    QVector<int> population10(4,0);
    for (auto d:dbf.getList()) {
        ++population10[d.getAge()];
    }

    QHorizontalBarSeries *series10 = new QHorizontalBarSeries();
    for (int i=0; i<4; ++i) {
        set10->append(population10[i]);
    }
    series10->append(set10);

    QChart *chart10 = new QChart();
    chart10->addSeries(series10);
    chart10->setTitle("Population/Âge");
    chart10->setAnimationOptions(animation);
    chart10->setTheme(theme);
    //    chart->legend()->hide();

    QStringList categories10;
    categories10 << "Enfant" << "Adulte";
    QBarCategoryAxis *axisY10 = new QBarCategoryAxis();
    axisY10->append(categories10);
    chart10->addAxis(axisY10, Qt::AlignLeft);
    series10->attachAxis(axisY10);

    QValueAxis *axisX10 = new QValueAxis();
    axisX10->setLabelFormat("%d");
    chart10->addAxis(axisX10, Qt::AlignBottom);
    series10->attachAxis(axisX10);

    chart10->legend()->setVisible(true);
    chart10->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView10 = new QChartView(chart10);
    chartView10->setRenderHint(QPainter::Antialiasing);

    /**************************************************************************/
    /* Survivant / Age                                                        */
    /**************************************************************************/
    QVector<QBarSet*> set11(2,nullptr);

    set11[0] = new QBarSet("Péri");
    set11[1] = new QBarSet("Survécu");

    QVector< QVector<int> > survived11(2, QVector<int>(4,0));
    for (auto d:dbf.getList()) {
        ++survived11[d.getSurvived()][d.getAge()];
    }

    QHorizontalStackedBarSeries *series11 = new QHorizontalStackedBarSeries();
    for (int i=1; i>=0; --i) {
        for (int j=0; j<4; ++j) {
            set11[i]->append(survived11[i][j]);
        }
        series11->append(set11[i]);
    }

    QChart *chart11 = new QChart();
    chart11->addSeries(series11);
    chart11->setTitle("Survivants/Âge");
    chart11->setAnimationOptions(animation);
    chart11->setTheme(theme);
    //    chart->legend()->hide();

    QStringList categories11;
    categories11 << "Enfant" << "Adulte";;
    QBarCategoryAxis *axisY11 = new QBarCategoryAxis();
    axisY11->append(categories11);
    chart11->addAxis(axisY11, Qt::AlignLeft);
    series11->attachAxis(axisY11);

    QValueAxis *axisX11 = new QValueAxis();
    axisX11->setLabelFormat("%d");
    chart11->addAxis(axisX11, Qt::AlignBottom);
    series11->attachAxis(axisX11);

    chart11->legend()->setVisible(true);
    chart11->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView11 = new QChartView(chart11);
    chartView11->setRenderHint(QPainter::Antialiasing);

    /**************************************************************************/
    /* Grid Layout                                                            */
    /**************************************************************************/
    QGridLayout *gridlayout= new QGridLayout();
    gridlayout->addWidget(chartView00,0,0);
    gridlayout->addWidget(chartView01,0,1);
    gridlayout->addWidget(chartView10,1,0);
    gridlayout->addWidget(chartView11,1,1);

    //creating a widget as support for the layout
    QWidget *widget = new QWidget();
    widget->setLayout(gridlayout);

    //to be set at CentralWidget
    return widget;
}


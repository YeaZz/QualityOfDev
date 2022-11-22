#include "viewPieChart.h"

ViewPieChart::ViewPieChart(QGroupBox* groupBox, Promotion* promotion) : groupBox(groupBox), promotion(promotion), chartView(nullptr) {
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    update();
}

void ViewPieChart::update() {
    QHash<QString, int> map;
    QString departement;
    for (Student* student : promotion->getStudentsList()) {
        departement = student->getDepartement();
        map[departement] = map.value(departement, 0) + 1;
    }

    QPieSeries* series = new QPieSeries();
    for (QString key : map.keys())
        series->append(key, map.value(key));

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Repartition geographique");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    
    QChartView* newChartView = new QChartView(chart);
    newChartView->setRenderHint(QPainter::Antialiasing);

    if (chartView == nullptr)
        groupBox->layout()->addWidget(newChartView);
    else
        groupBox->layout()->replaceWidget(chartView, newChartView);
    chartView = newChartView;
}
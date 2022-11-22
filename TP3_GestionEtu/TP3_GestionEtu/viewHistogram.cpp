#include "viewHistogram.h"

ViewHistogram::ViewHistogram(QGroupBox* groupBox, Promotion* promotion) : groupBox(groupBox), promotion(promotion), chartView(nullptr) {
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    update();
}

void ViewHistogram::update() {
    QHash<QString, int> map;
    QString bac;
    for (Student* student : promotion->getStudentsList()) {
        bac = student->getBac();
        map[bac] = map.value(bac, 0) + 1;
    }

    QBarSeries* series = new QBarSeries();
    for (QString bac : map.keys()) {
        QBarSet* barSet = new QBarSet(bac);
        barSet->append(map.value(bac));
        series->append(barSet);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Series de bac");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* newChartView = new QChartView(chart);
    newChartView->setRenderHint(QPainter::Antialiasing);

    if (chartView == nullptr)
        groupBox->layout()->addWidget(newChartView);
    else
        groupBox->layout()->replaceWidget(chartView, newChartView);
    chartView = newChartView;
}
#pragma once
#include "observer.h"
#include "promotion.h"

#include <QWidget>
#include <QGroupBox>
#include <QPieSeries>
#include <QChartView>
#include <QVBoxLayout>

/**
 * @brief Class ViewPieChart inherited from Observer class.
 * @author Cavalcante Noa 
 * 
 */
class ViewPieChart : public Observer {
private:
	/**
	 * @brief QGroupBox*. QGroupBox*. QObject where the Histogram is.
	 * 
	 */
	QGroupBox* groupBox;

	/**
	 * @brief Promotion*. Promotion that is used to take data from.
	 * 
	 */
	Promotion* promotion;

	/**
	 * @brief QWidget*. QChartView that is created.
	 * 
	 */
	QWidget* chartView;
public:
	/**
	 * @brief Construct a new View Pie Chart object.
	 * 
	 * @param groupBox 
	 * @param promotion 
	 */
	ViewPieChart(QGroupBox* groupBox, Promotion* promotion);

	/**
	 * @brief Function to update the View Pie Chart.
	 * 
	 */
	virtual void update();
};


#pragma once
#include "observer.h"
#include "promotion.h"

#include <QBarSet>
#include <QGroupBox>
#include <QBarSeries>
#include <QChartView>
#include <QVBoxLayout>
#include <QBarCategoryAxis>

/**
 * @brief Class ViewHistogram inherited from Observer class.
 * @author Cavalcante Noa 
 * 
 */
class ViewHistogram : public Observer {
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
	 * @brief Construct a new View Histogram object.
	 * 
	 * @param groupBox 
	 * @param promotion 
	 */
	ViewHistogram(QGroupBox* groupBox, Promotion* promotion);

	/**
	 * @brief Function to update the view Histogram.
	 * 
	 */
	virtual void update();
};


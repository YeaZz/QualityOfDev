#pragma once
#include "observer.h"
#include "promotion.h"

#include <QListWidget>
#include <QListWidgetItem>

/**
 * @brief Class ViewList inherited from Observer class.
 * @author Cavalcante Noa 
 * 
 */
class ViewList : public Observer {
private:
	QListWidget* listWidget;
	Promotion* promotion;
public:
	/**
	 * @brief Construct a new View List object.
	 * 
	 * @param listWidget 
	 * @param promotion 
	 */
	ViewList(QListWidget* listWidget, Promotion* promotion);

	/**
	 * @brief Get the List Widget object.
	 * 
	 * @return QListWidget* 
	 */
	QListWidget* getListWidget() const;

	/**
	 * @brief Get the Promotion object.
	 * 
	 * @return Promotion* 
	 */
	Promotion* getPromotion() const;

	/**
	 * @brief Function to update the List Widget.
	 * 
	 */
	virtual void update();
};

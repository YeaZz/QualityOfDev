#pragma once
#include <QVector>

/**
 * @brief Class Observer. Observ an Observable class to update the view as the datas changes.
 * @author Cavalcante Noa 
 * 
 */
class Observer {
public:
	/**
	 * @brief Destroy the Observer object.
	 * 
	 */
	virtual ~Observer() {}

	/**
	 * @brief Pure virtual function that make the component update.
	 * 
	 */
	virtual void update() = 0;
};

/**
 * @brief Class Observable. Has observers which can be updated.
 * @author Cavalcante Noa 
 * 
 */
class Observable {
private:
	/**
	 * @brief QVector<Observer*>. List that contains observers.
	 * 
	 */
	QVector<Observer*> observersList;
public:
	/**
	 * @brief Function to add an observer.
	 * 
	 * @param observer 
	 */
	void addObserver(Observer* observer);

	/**
	 * @brief Function to remove an observer.
	 * 
	 * @param observer 
	 */
	void removeObserver(Observer* observer);

	/**
	 * @brief Function to call observers' update function.
	 * 
	 * @param observer 
	 */
	void notifyObserver();
};

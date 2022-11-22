#pragma once
#include "promotion.h"

#include <QVector>
#include <QString>
#include <QMessageBox>

/**
 * @brief Class AbstractController. Classes that inherit AbstractController can write data from a Promotion.
 * @author Cavalcante Noa 
 *
 */
class AbstractController {
protected:
	/**
	 * @brief Promotion that is managed.
	 * 
	 */
	Promotion* promotion;
public:
	/**
	 * @brief Construct a new Abstract Controller object.
	 * 
	 * @param promotion 
	 */
	AbstractController(Promotion* promotion);

	/**
	 * @brief Destroy the Abstract Controller object.
	 * 
	 */
	virtual ~AbstractController() {}
	/**
	 * @brief Pure virtual function to manage a Promotion.
	 * 
	 * @param datas List of QString.
	 */
	virtual void control(QStringList datas) = 0;
};

/**
 * @brief Class ControllerDeleteList inherited from AbstractController class. Used to delete users.
 * @author Cavalcante Noa 
 *
 */
class ControllerDeleteList : public AbstractController {
public:
	/**
	 * @brief Construct a new Controller Delete List object.
	 * 
	 * @param promotion 
	 */
	ControllerDeleteList(Promotion* promotion);

	/**
	 * @brief Function to delete given users if they exist.
	 * 
	 * @param datas Selected users' id in QString.
	 */
	virtual void control(QStringList datas);
};

/**
 * @brief Class ControllerAddForm inherited from AbstractController class. Used to add a user.
 * @author Cavalcante Noa 
 * 
 */
class ControllerAddForm : public AbstractController {
public:
	/**
	 * @brief Construct a new Controller Add Form object.
	 * 
	 * @param promotion 
	 */
	ControllerAddForm(Promotion* promotion);

	/**
	 * @brief Function to add a user with given arguments.
	 * 
	 * @param datas User's id, firstname, lastname, departement and bac in QString.
	 */
	virtual void control(QStringList datas);
};

/**
 * @brief Class ControllerDeleteForm inherited from AbstractController class. Used to delete users.
 * @author Cavalcante Noa 
 * 
 */
class ControllerDeleteForm : public AbstractController {
public:
	/**
	 * @brief Construct a new Controller Delete Form object.
	 * 
	 * @param promotion 
	 */
	ControllerDeleteForm(Promotion* promotion);

	/**
	 * @brief Function to delete given user if he exists.
	 * 
	 * @param datas User's id.
	 */
	virtual void control(QStringList datas);
};

/**
 * @brief Class ControllerUpdateStudentForm inherited from AbstractController class. Used to update user's data.
 * @author Cavalcante Noa 
 * 
 */
class ControllerUpdateStudentForm : public AbstractController {
public:
	/**
	 * @brief Construct a new Controller Update Student Form object.
	 * 
	 * @param promotion 
	 */
	ControllerUpdateStudentForm(Promotion* promotion);

	/**
	 * @brief Function to update a user's data.
	 * 
	 * @param datas User's id, firstname, lastname, departement and bac in QString.
	 */
	virtual void control(QStringList datas);
};

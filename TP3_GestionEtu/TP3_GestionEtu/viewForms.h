#pragma once
#include "observer.h"
#include "promotion.h"

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>


/**
 * @brief Class ViewFormsAddStudent inherited from Observer class.
 * @author Cavalcante Noa 
 * 
 */
class ViewFormsAddStudent : public Observer {
private:
	QPushButton* submitButton;
	QLineEdit* idField;
	QLineEdit* firstnameField;
	QLineEdit* lastnameField;
	QComboBox* bacBox;
	QComboBox* departementBox;
	Promotion* promotion;
public:
	/**
	 * @brief Construct a new View Forms Add Student object.
	 * 
	 */
	ViewFormsAddStudent(QPushButton*, QLineEdit*, QLineEdit*, QLineEdit*, QComboBox*, QComboBox*, Promotion*);

	/**
	 * @brief Get the Submit Button object.
	 * 
	 * @return QPushButton* 
	 */
	QPushButton* getSubmitButton() const;

	/**
	 * @brief Get the Id Field object.
	 * 
	 * @return QLineEdit* 
	 */
	QLineEdit* getIdField() const;

	/**
	 * @brief Get the Firstname Field object.
	 * 
	 * @return QLineEdit* 
	 */
	QLineEdit* getFirstnameField() const;

	/**
	 * @brief Get the Lastname Field object.
	 * 
	 * @return QLineEdit* 
	 */
	QLineEdit* getLastnameField() const;

	/**
	 * @brief Get the Bac Box object.
	 * 
	 * @return QComboBox* 
	 */
	QComboBox* getBacBox() const;

	/**
	 * @brief Get the Department Box object.
	 * 
	 * @return QComboBox* 
	 */
	QComboBox* getDepartmentBox() const;

	/**
	 * @brief Get the Promotion object.
	 * 
	 * @return Promotion* 
	 */
	Promotion* getPromotion() const;

	/**
	 * @brief Function to update form's input.
	 * 
	 */
	virtual void update();
};

/**
 * @brief Class ViewFormsDeleteStudent inherited from Observer class.
 * @author Cavalcante Noa 
 * 
 */
class ViewFormsDeleteStudent : public Observer {
private:
	QLineEdit* idField;
	Promotion* promotion;
public:
	/**
	 * @brief Construct a new View Forms Delete Student object.
	 * 
	 */
	ViewFormsDeleteStudent(QLineEdit*, Promotion*);

	/**
	 * @brief Get the Id Field object.
	 * 
	 * @return QLineEdit* 
	 */
	QLineEdit* getIdField() const;

	/**
	 * @brief Get the Promotion object.
	 * 
	 * @return Promotion* 
	 */
	Promotion* getPromotion() const;
 
	/**
	 * @brief Function to update form's input.
	 * 
	 */
	virtual void update();
};

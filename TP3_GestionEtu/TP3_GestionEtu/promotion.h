#pragma once
#include "observer.h"
#include "student.h"

#include <QFile>
#include <QDebug>
#include <QVector>
#include <QTextStream>

/**
 * @brief Class Promotion inherited from Observable class. Used to store and manage users.
 * @author Cavalcante Noa
 *
 */
class Promotion : public Observable {
private:
	/**
	 * @brief Student*. User that will be updated.
	 * 
	 */
	Student* selectedStudent;

	/**
	 * @brief QVector<Student*>. List that contains users.
	 * 
	 */
	QVector<Student*> studentsList;
public:
	/**
	 * @brief Construct a new Promotion object.
	 * 
	 * @param filename File name that will be loaded like "id;lastname;firstname;departement;bac".
	 */
	Promotion(const QString& filename);

	/**
	 * @brief Destroy the Promotion object.
	 * 
	 */
	~Promotion();

	/**
	 * @brief Function to add a Student.
	 * 
	 * @param student 
	 */
	void add(Student* student);

	/**
	 * @brief Function to remove a Student.
	 * 
	 * @param student 
	 */
	void remove(Student* student);

	/**
	 * @brief Function to remove a list of Student.
	 * 
	 * @param students 
	 */
	void remove(QVector<Student*> students);

	/**
	 * @brief Function to find a Student with its id.
	 * 
	 * @param id 
	 * @return Student* 
	 */
	Student* find(const QString& id) const;

	/**
	 * @brief Set the Selected Student object.
	 * 
	 * @param student 
	 */
	void setSelectedStudent(Student* student);

	/**
	 * @brief Get the Selected Student object.
	 * 
	 * @return Student* 
	 */
	Student* getSelectedStudent() const;

	/**
	 * @brief Get the Students List object.
	 * 
	 * @return QVector<Student*> 
	 */
	QVector<Student*> getStudentsList() const;
};

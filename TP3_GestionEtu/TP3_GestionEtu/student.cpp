#include "student.h"

Student::Student(const QString& id, const QString& lastname, const QString& firstname, const QString& departement, const QString& bac)
	: id(id), lastname(lastname.toUpper()), firstname(firstname.toUpper()), departement(departement), bac(bac) {
}

QString Student::getId() const {
	return this->id;
}

void Student::setLastname(const QString& lastname) {
	this->lastname = lastname;
}

QString Student::getLastname() const {
	return this->lastname;
}

void Student::setFirstname(const QString& firstname) {
	this->firstname = firstname;
}

QString Student::getFirstname() const {
	return this->firstname;
}

void Student::setDepartement(const QString& departement) {
	this->departement = departement;
}

QString Student::getDepartement() const {
	return this->departement;
}

void Student::setBac(const QString& bac) {
	this->bac = bac;
}

QString Student::getBac() const {
	return this->bac;
}
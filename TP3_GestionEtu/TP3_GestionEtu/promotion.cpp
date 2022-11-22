#include "promotion.h"

Promotion::Promotion(const QString& filename) : selectedStudent(nullptr) {
	QFile myfile(filename);
	if (myfile.open(QIODevice::ReadOnly | QFile::Text)) {
		QTextStream in(&myfile);
		QStringList datas;
		while (!in.atEnd()) {
			datas = in.readLine().split(';');
			datas[3] = (datas[3].length() > 1 ? datas[3] : "0" + datas[3]);
			add(new Student(datas[0], datas[1], datas[2], datas[3], datas[4]));
		}
		myfile.close();
	} else
		qDebug() << "Unable to open file" << filename << ": error" << myfile.error() << "," << myfile.errorString();
}

Promotion::~Promotion() {
	for (int i = 0; i < studentsList.size(); i++)
		delete studentsList.at(i);
}

void Promotion::add(Student* student) {
	studentsList.append(student);
	notifyObserver();
}

void Promotion::remove(QVector<Student*> students) {
	for (Student* student : students) {
		studentsList.removeOne(student);
		delete student;
	}
	notifyObserver();
}

void Promotion::remove(Student* student) {
	studentsList.removeOne(student);
	delete student;
	notifyObserver();
}

Student* Promotion::find(const QString& id) const {
	for (Student* student : studentsList) {
		if (student->getId() == id)
		    return student;
	}
	return nullptr;
}

void Promotion::setSelectedStudent(Student* selectedStudent) {
	this->selectedStudent = selectedStudent;
	notifyObserver();
}

Student* Promotion::getSelectedStudent() const {
	return selectedStudent;
}

QVector<Student*> Promotion::getStudentsList() const {
	return studentsList;
}
#include "controllers.h"

AbstractController::AbstractController(Promotion* promotion) {
    this->promotion = promotion;
}

/**
 * @brief Construct a new Controller Delete List
 * 
 * @param promotion 
 */
ControllerDeleteList::ControllerDeleteList(Promotion* promotion) : AbstractController(promotion) {}

void ControllerDeleteList::control(QStringList ids) {
    if (ids.isEmpty()) return;
    QVector<Student*> students;
	for (QString id : ids) {
		Student* student = promotion->find(id);
        if (student != nullptr)
            students.append(student);
	}
    promotion->remove(students);
}

ControllerAddForm::ControllerAddForm(Promotion* promotion) : AbstractController(promotion) {}

void ControllerAddForm::control(QStringList datas) {
    if (datas.size() != 5) return;
    Student* student = promotion->find(datas[0]);
    if (student != nullptr) {
        QMessageBox::warning(nullptr, "Add Student", "The student already exist."); return;
    }
    if (datas[0] == "") {
        QMessageBox::warning(nullptr, "Add Student", "The ID is empty."); return;
    } else if (datas[1] == "") {
        QMessageBox::warning(nullptr, "Add Student", "The firstname is empty."); return;
    } else if (datas[2] == "") {
        QMessageBox::warning(nullptr, "Add Student", "The lastname is empty."); return;
    } else if (datas[4] == "") {
        QMessageBox::warning(nullptr, "Add Student", "The bac is empty."); return;
    } else if (datas[3] == "") {
        QMessageBox::warning(nullptr, "Add Student", "The department is empty."); return;
    }
    promotion->add(new Student(datas[0], datas[2], datas[1], datas[3], datas[4]));
}

ControllerDeleteForm::ControllerDeleteForm(Promotion* promotion) : AbstractController(promotion) {}

void ControllerDeleteForm::control(QStringList datas) {
    if (datas.size() != 1) return;
    if (datas[0] == "") return;
    Student* student = promotion->find(datas[0]);
    if (student != nullptr)
        promotion->remove(student);
    else
        QMessageBox::warning(nullptr, "Delete Student", "The ID is unknown.");
}

ControllerUpdateStudentForm::ControllerUpdateStudentForm(Promotion* promotion) : AbstractController(promotion) {}

void ControllerUpdateStudentForm::control(QStringList datas) {
    if (datas.size() <= 0) return;
    Student* student = promotion->find(datas[0]);
    if (student == nullptr) return;
    if (promotion->getSelectedStudent() == nullptr) {
        if (datas.size() != 1) return;
        promotion->setSelectedStudent(student);
    } else {
        if (datas.size() != 5) return;
        else if (datas[1] == "") {
            QMessageBox::warning(nullptr, "Update Student", "The firstname is empty."); return;
        }
        else if (datas[2] == "") {
            QMessageBox::warning(nullptr, "Update Student", "The lastname is empty."); return;
        }
        else if (datas[4] == "") {
            QMessageBox::warning(nullptr, "Update Student", "The bac is empty."); return;
        }
        else if (datas[3] == "") {
            QMessageBox::warning(nullptr, "Update Student", "The department is empty."); return;
        }
        student->setFirstname(datas[1]);
        student->setLastname(datas[2]);
        student->setDepartement(datas[3]);
        student->setBac(datas[4]);
        promotion->setSelectedStudent(nullptr);
    }
}
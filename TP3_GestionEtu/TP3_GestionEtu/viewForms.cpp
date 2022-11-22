#include "viewForms.h"

ViewFormsAddStudent::ViewFormsAddStudent(QPushButton* submitButton, QLineEdit* idField, QLineEdit* firstnameField, QLineEdit* lastnameField, QComboBox* bacBox, QComboBox* departementBox, Promotion* promotion)
	: submitButton(submitButton), idField(idField), firstnameField(firstnameField), lastnameField(lastnameField), bacBox(bacBox), departementBox(departementBox), promotion(promotion) {
	QStringList bacs = { "S", "ES", "STI", "L" };
	for (QString bac : bacs)
		bacBox->addItem(bac);
	for (int i = 1; i <= 95; i++)
		departementBox->addItem((i < 10 ? QString("0") : QString("")) + QString::number(i));
	departementBox->addItems({ "971", "972", "973", "974", "976" });
	update();
}

QPushButton* ViewFormsAddStudent::getSubmitButton() const {
	return submitButton;
}

QLineEdit* ViewFormsAddStudent::getIdField() const {
	return idField;
}

QLineEdit* ViewFormsAddStudent::getFirstnameField() const {
	return firstnameField;
}

QLineEdit* ViewFormsAddStudent::getLastnameField() const {
	return lastnameField;
}

QComboBox* ViewFormsAddStudent::getBacBox() const {
	return bacBox;
}

QComboBox* ViewFormsAddStudent::getDepartmentBox() const {
	return departementBox;
}

Promotion* ViewFormsAddStudent::getPromotion() const {
	return promotion;
}

void ViewFormsAddStudent::update() {
	if (promotion->getSelectedStudent() == nullptr) {
		idField->setText("");
		firstnameField->setText("");
		lastnameField->setText("");
		bacBox->setCurrentIndex(-1);
		departementBox->setCurrentIndex(-1);
		submitButton->setText("Ajout");
		idField->setDisabled(false);
	} else {
		Student* student = promotion->getSelectedStudent();
		if (student == nullptr) return;
		idField->setText(student->getId());
		firstnameField->setText(student->getFirstname());
		lastnameField->setText(student->getLastname());
		bacBox->setCurrentIndex(bacBox->findText(student->getBac()));
		departementBox->setCurrentIndex(departementBox->findText(student->getDepartement()));
		submitButton->setText("Enregistrer");
		idField->setDisabled(true);
	}
}

ViewFormsDeleteStudent::ViewFormsDeleteStudent(QLineEdit* idField, Promotion* promotion) : idField(idField), promotion(promotion) {
	update();
}

QLineEdit* ViewFormsDeleteStudent::getIdField() const {
	return idField;
}

Promotion* ViewFormsDeleteStudent::getPromotion() const {
	return promotion;
}

void ViewFormsDeleteStudent::update() {
	idField->setText("");
}

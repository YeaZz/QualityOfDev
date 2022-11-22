#include "viewList.h"

ViewList::ViewList(QListWidget* listWidget, Promotion* promotion) : listWidget(listWidget), promotion(promotion) {
	listWidget->setSelectionMode(QListView::ExtendedSelection);
	update();
}

QListWidget* ViewList::getListWidget() const {
	return listWidget;
}

Promotion* ViewList::getPromotion() const {
	return promotion;
}

void ViewList::update() {
	listWidget->clear();
	for (auto student : promotion->getStudentsList()) {
		QListWidgetItem* item = new QListWidgetItem();
		item->setText(student->getId() + " - " + student->getLastname() + " " + student->getFirstname() + " (" + student->getDepartement() + ")");
		item->setData(Qt::UserRole, student->getId());
		listWidget->addItem(item);
	}
}

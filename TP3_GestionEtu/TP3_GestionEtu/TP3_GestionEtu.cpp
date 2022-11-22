#include "controllers.h"
#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* promotion,  QWidget* parent) : promotion(promotion), QMainWindow(parent) {
    ui.setupUi(this);
    this->viewList = new ViewList(ui.listWidget, promotion);
    this->formAddStudent = new ViewFormsAddStudent(
        ui.pushButton_addStudent,
        ui.lineEdit_add_number, ui.lineEdit_add_firstname,
        ui.lineEdit_add_lastname,ui.lineEdit_add_BAC,
        ui.lineEdit_add_department, promotion);
    this->formDeleteStudent = new ViewFormsDeleteStudent(ui.lineEdit_remove_number, promotion);
    this->pieChartView = new ViewPieChart(ui.groupBox_department, promotion);
    this->histogramView = new ViewHistogram(ui.groupBox_bacs, promotion);

    promotion->addObserver(viewList);
    promotion->addObserver(formAddStudent);
    promotion->addObserver(formDeleteStudent);
    promotion->addObserver(pieChartView);
    promotion->addObserver(histogramView);

    connect(ui.pushButton_delete_list, &QPushButton::released, this, &TP3_GestionEtu::handleDeleteListButton);
    connect(ui.pushButton_addStudent, &QPushButton::released, this, &TP3_GestionEtu::handleAddStudentButton);
    connect(ui.pushButton_delete_number, &QPushButton::released, this, &TP3_GestionEtu::handleDeleteStudentButton);
    connect(ui.listWidget, &QListWidget::itemDoubleClicked, this, &TP3_GestionEtu::handleDoubleClickWidgetItem);
}

void TP3_GestionEtu::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Delete)
        handleDeleteListButton();
}

void TP3_GestionEtu::handleDeleteListButton() {
    ControllerDeleteList controller(promotion);
    QStringList ids;
    for (QListWidgetItem* item : viewList->getListWidget()->selectedItems()) {
        QString id = item->data(Qt::UserRole).toString();
        if (promotion->getSelectedStudent() != nullptr && promotion->getSelectedStudent()->getId() == id)
            continue;
        ids.append(id);
    }
    controller.control(ids);
}

void TP3_GestionEtu::handleAddStudentButton() {
    QStringList datas;
    datas.append(formAddStudent->getIdField()->text());
    datas.append(formAddStudent->getFirstnameField()->text().toUpper());
    datas.append(formAddStudent->getLastnameField()->text().toUpper());
    datas.append(formAddStudent->getDepartmentBox()->currentText());
    datas.append(formAddStudent->getBacBox()->currentText());
    if (promotion->getSelectedStudent() == nullptr) {
        ControllerAddForm controller(promotion);
        controller.control(datas);
    } else {
        ControllerUpdateStudentForm controller(promotion);
        controller.control(datas);
    }
}

void TP3_GestionEtu::handleDeleteStudentButton() {
    ControllerDeleteForm controller(promotion);
    QStringList datas;
    datas.append(formDeleteStudent->getIdField()->text());
    controller.control(datas);
}

void TP3_GestionEtu::handleDoubleClickWidgetItem() {
    if (promotion->getSelectedStudent() != nullptr) return;
    QString id = viewList->getListWidget()->currentItem()->data(Qt::UserRole).toString();
    ControllerUpdateStudentForm controller(promotion);
    QStringList datas;
    datas.append(id);
    controller.control(datas);
}
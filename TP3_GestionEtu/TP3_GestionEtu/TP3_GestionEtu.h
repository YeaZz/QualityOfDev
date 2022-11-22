#pragma once
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"
#include "ui_TP3_GestionEtu.h"

#include <QMainWindow>

/**
 * @brief Class TP3_GestionEtu inherited from QMainWindow.
 * @author Cavalcante Noa 
 * 
 */
class TP3_GestionEtu : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Construct a new tp3 gestionetu object.
     * 
     * @param promotion 
     * @param parent 
     */
    TP3_GestionEtu(Promotion* promotion, QWidget *parent = nullptr);
    
    /**
     * @brief Destroy the tp3 gestionetu object.
     * 
     */
    ~TP3_GestionEtu() {}

    /**
     * @brief Overriding QMainWindow's function to handle keyboard inputs. 
     * 
     * @param event 
     */
    void keyPressEvent(QKeyEvent* event) override;
private:
    Ui::TP3_GestionEtuClass ui;

    Promotion* promotion;
    ViewList* viewList;
    ViewFormsAddStudent* formAddStudent;
    ViewFormsDeleteStudent* formDeleteStudent;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
private slots:
    /**
     * @brief Function to handle the list delete button.
     * 
     */
    void handleDeleteListButton();

    /**
     * @brief Function to handle the form add/update button.
     * 
     */
    void handleAddStudentButton();

    /**
     * @brief Function to handle the form delete button.
     * 
     */
    void handleDeleteStudentButton();

    /**
     * @brief Function to handle the double click on users list.
     * 
     */
    void handleDoubleClickWidgetItem();
};

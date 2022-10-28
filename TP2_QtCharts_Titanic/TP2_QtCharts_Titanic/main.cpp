/**
* @file
* @brief Main file for the Titinaic project
* @author Fabrice Jaillet
* @date 18/10/2022
*/

#include "titaniccharts.h"
#include "data.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QDir>

/**
 * @brief main class of the project
 * @param argc
 * @param argv
 * @return a.exec()
*/
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    TitanicCharts w(QDir::currentPath() + "/titanic.dbf");
    w.resize(1200, 800);
    w.show();
    return a.exec();
}

#include "promotion.h"
#include "TP3_GestionEtu.h"

#include <Qdebug>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Promotion* promotion = new Promotion("../data/promoDUT.csv");

    TP3_GestionEtu w(promotion);
    w.show();

    return a.exec();
}

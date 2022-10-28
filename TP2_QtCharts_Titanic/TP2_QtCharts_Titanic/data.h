#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "passenger.h"

/**
 * @brief The Data class to manage IO from file
 * @author Fabrice Jaillet
 * @sa  Passenger
 */
class Data
{
private:
    QVector<Passenger> passengers; /**< the passenger list */
public:
    /**
     * @brief Data default constuctor
     */
    Data() {}

    /**
     * @brief Data common constructor. Fills passengers list
     * @param filename: name of the data file
     * @sa readList
     */
    Data(const QString& filename) {
        readList(filename);
    }

    /**
     * @brief readList: read data from file
     * @param filename: name of the data file
     */
    void readList(const QString& filename);

    /**
     * @brief getList
     * @return the passengers list
     */
    const QVector<Passenger>& getList() const {
        return passengers;
    }
};

#endif // DATA_H

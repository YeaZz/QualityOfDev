#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>

/**
 * @brief The passenger class used to store data about passengers on the Titanic
 * @author Fabrice Jaillet
 * @sa  Data
 */
class Passenger
{
private:
    QString iden; /**< passenger id */
    int classe, age, sex, survived; /**< passenger data */
public:
    /**
     * @brief Passenger default constructor
     * @param id: anonymous passenger descriptor
     * @param cl: the passenger class   0 = crew,   1 = first, 2 = second, 3 = third
     * @param ag: the passenger age     0 = child,  1 = adult
     * @param sx: the passenger sex     0 = female, 1 = male
     * @param sv: if passenger survived 0 = no,     1 = yes
     */
    Passenger(const QString &id= QString(), int cl=0, int ag=0, int sx=0, int sv=0);

    int getClasse() const {return classe;} /**< passenger class getter */
    int getAge() const {return age;} /**< passenger age getter */
    int getSex() const {return sex;} /**< passenger sex getter */
    int getSurvived() const {return survived;} /**< passenger survived state getter */
};

#endif // PASSENGER_H

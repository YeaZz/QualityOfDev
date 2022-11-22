#pragma once
#include <QString>

/**
 * @brief Class Student. Used to represent a user.
 * @author Cavalcante Noa 
 * 
 */
class Student {
private:
    QString id;
    QString lastname;
    QString firstname;
    QString departement;
    QString bac;
public: 
    /**
     * @brief Construct a new Student object.
     * 
     * @param id 
     * @param lastname 
     * @param firstname 
     * @param departement 
     * @param bac 
     */
    Student(const QString& id, const QString& lastname, const QString& firstname, const QString& departement, const QString& bac);

    /**
     * @brief Get the Id object.
     * 
     * @return QString 
     */
    QString getId() const;

    /**
     * @brief Set the Lastname object.
     * 
     */
    void setLastname(const QString&);

    /**
     * @brief Get the Lastname object.
     * 
     * @return QString 
     */
    QString getLastname() const;

    /**
     * @brief Set the Firstname object.
     * 
     */
    void setFirstname(const QString&);

    /**
     * @brief Get the Firstname object.
     * 
     * @return QString 
     */
    QString getFirstname() const;

    /**
     * @brief Set the Departement object.
     * 
     */
    void setDepartement(const QString&);

    /**
     * @brief Get the Departement object.
     * 
     * @return QString 
     */
    QString getDepartement() const;

    /**
     * @brief Set the Bac object.
     * 
     */
    void setBac(const QString&);

    /**
     * @brief Get the Bac object.
     * 
     * @return QString 
     */
    QString getBac() const;
};


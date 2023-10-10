#pragma once
#include <list>
#include "User.h"

using namespace std;

class Software {
    private:
    string name;
    string developer;
    string minAge;
    list<User*> userList;
    double price;

    public:

    /** Constructor de la clase Software.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param minAge Edad mínima requerida para el software.
     * @param price Precio del software.
     */
    Software(string,string,string,double);

    /** Obtiene el nombre del software.
     * 
     * 
     * @return El nombre del software.
     */
    string getName();

    /** Obtiene el desarrollador del software.
     * 
     * 
     * @return El desarrollador del software.
     */
    string getDeveloper();
 
    /** Obtiene la edad mínima requerida para el software.
     * 
     * 
     * @return Edad mínima requerida para el software.
     */
    string getMinAge();

    /** Obtiene el precio del software.
     * 
     * 
     * @return Precio del software.
     */
    double getPrice();

    /** Obtiene una representación de cadena de los usuarios del software.
     *  
     * 
     * @return Cadena con los nombres de los usuarios del software.
     */
    string getUsers();

    /**
     * Destructor virtual para la clase Software.
     */
    virtual ~Software() {}

    /** Método virtual para obtener una representación de cadena del software.
     * 
     * 
     * @return Representación de cadena del software.
     */
    virtual string toString() {}
};

Software::Software(string name,string developer,string minAge,double price) {
    this->name = name;
    this->developer = developer;
    this->minAge = minAge;
    this->price = price;
}
string Software::getName() {
    return name;
}
string Software::getDeveloper() {
    return developer;
}
string Software::getMinAge() {
    return minAge;
}
double Software::getPrice() {
    return price;
}
string Software::getUsers() {
    cout<<"    Usuarios del software:\n" << endl;
    for (User* user : userList) {
        cout << user->getName() << endl;
    }
}
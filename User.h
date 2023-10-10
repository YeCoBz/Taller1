#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User {
    private:
    string name;
    string password;
    int age;
    string mail;
    bool logAccess;
    
    public:

    /**
     * Constructor de la clase User.
     * 
     * @param name Nombre del usuario.
     * @param password Contraseña del usuario.
     * @param age Edad del usuario.
     * @param mail Correo electrónico del usuario.
     * @param logAccess Indica si el usuario tiene acceso al registro.
     */
    User(string,string,int,string,string);

    // Getters
    /**
     * Obtiene el nombre del usuario.
     * 
     * @return Nombre del usuario.
     */
    string getName();

    /**
     * Obtiene la contraseña del usuario.
     * 
     * @return Contraseña del usuario.
     */
    string getPassword();

    /**
     * Obtiene la edad del usuario.
     * 
     * @return Edad del usuario.
     */
    int getAge();

    /**
     * Obtiene el correo electrónico del usuario.
     * 
     * @return Correo electrónico del usuario.
     */
    string getMail();

    /**
     * Obtiene el estado de acceso al registro del usuario.
     * 
     * @return true si el usuario tiene acceso al registro, false en caso contrario.
     */
    bool getlogAccess();

    // Setters
    /**
     * Establece el nombre del usuario.
     * 
     * @param name Nuevo nombre del usuario.
     */
    void setName(string);

    /**
     * Establece la edad del usuario.
     * 
     * @param age Nueva edad del usuario.
     */
    void setAge(int);

    /**
     * Establece el correo electrónico del usuario.
     * 
     * @param mail Nuevo correo electrónico del usuario.
     */
    void setMail(string);

    /**
     * Obtiene una representación de cadena del usuario.
     * 
     * @return Cadena con información del usuario.
     */
    string toString();
};

User::User(string name,string password,int age,string mail,string _logAccess) {
    this->name = name;
    this->password = password;
    this->age = age;
    this->mail = mail;
    if (_logAccess == "true") {
        this->logAccess = true;
    } else { 
        this->logAccess = false;
    }
}
string User::getName() {
    return name;
}
string User::getPassword() {
    return password;
}
int User::getAge() {
    return age;
}
string User::getMail() { 
    return mail; 
}
bool User::getlogAccess() {
    return logAccess;
}
void User::setName(string name) { 
    this-> name = name;
}
void User::setAge(int age) {
    this->age = age;
}
void User::setMail(string mail) { 
    this->mail = mail; 
}
string User::toString() {
    return "Nombre: " + name + ", Contraseña: " + password + ", Edad: " + to_string(age) +
           ", Correo: " + mail + ", Acceso al registro: " + (logAccess ? "Sí" : "No");
}
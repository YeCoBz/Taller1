#pragma once

#include <iostream>
#include <list>
#include "Software.h"
#include "User.h"

using namespace std;

class Social : public Software{
    private:
    list<User*> friendList;
    public: 

    /**
     * Constructor de la clase Social.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param age Edad mínima requerida para el software.
     * @param price Precio del software.
     */
    Social(string, string, string, double);

    /**
     * Agrega un amigo a la lista de amigos asociados al software social.
     * 
     * @param user Puntero al objeto User que representa al amigo.
     */
    void addFriend(User*);
};

Social::Social(string name, string developer, string age, double price) : Software(name, developer, age, price) {
    friendList = list<User*>();
}
void Social::addFriend(User* user) {
    friendList.push_back(user);
}

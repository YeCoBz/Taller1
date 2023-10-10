#pragma once
#include "Software.h"

class Game: public Software {
    private:
    string gameGenre;
    public:

    /**
     * Constructor de la clase Game.
     * 
     * @param name Nombre del juego.
     * @param developer Desarrollador del juego.
     * @param minAge Edad mínima requerida para el juego.
     * @param price Precio del juego.
     * @param gameGenre Género del juego.
     */
    Game(string,string,string,double,string);

    /**
     * Método toString que devuelve una representación en cadena de la información del juego.
     * @return Cadena que representa la información del juego.
     */
    string toString();
};

Game::Game(string name,string developer,string minAge,double price,string gameGenre) : Software(name,developer,minAge,price) {
    this->gameGenre = gameGenre;
}
string Game::toString() {
    cout << "Nombre: " << this->getName() << endl;
    cout << "Desarrollados: " << this->getDeveloper() << endl;
    cout << "Edad minima: " << this->getMinAge() << endl;
    cout << "Precio: $" << this->getPrice() << endl;
    cout << "Genero del juego: " << gameGenre << endl;
}
#pragma once
#include "Software.h"

class Game: public Software {
    private:
    string gameGenre;
    public:
    Game(string,string,string,double,string);
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
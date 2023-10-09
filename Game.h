#pragma once
#include "Software.h"

class Game: public Software {
    private:
    string gameGenre;
    public:
    Game(string,string,string,double,string);
};

Game::Game(string name,string developer,string minAge,double price,string gameGenre) : Software(name,developer,minAge,price) {
    this->gameGenre = gameGenre;
}
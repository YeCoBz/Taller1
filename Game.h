#pragma once
#include "Software.h"

class Game: public Software {
    private:
    string gameGenre;
    public:
    Game(string,string,int,double,string);
};

Game::Game(string name,string developer,int minAge,double price,string gameGenre) : Software(name,developer,minAge,price) {
    this->gameGenre = gameGenre;
}
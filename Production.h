#pragma once
#include "Software.h"

class Production: public Software {
    private:
    string typeSolution;
    public:
    Production(string,string,int,double,string);
};

Production::Production(string name,string developer,int minAge,double price,string typeSolution) : Software(name,developer,minAge,price) {
    this->typeSolution = typeSolution;
}
#pragma once
#include "Software.h"

class Production: public Software {
    private:
    string typeSolution;
    public:

    /**
     * Constructor de la clase Production.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param minAge Edad mínima requerida para el software.
     * @param price Precio del software.
     * @param typeSolution Tipo de solución proporcionada por el software de producción.
     */
    Production(string,string,string,double,string);
};

Production::Production(string name,string developer,string minAge,double price,string typeSolution) : Software(name,developer,minAge,price) {
    this->typeSolution = typeSolution;
}
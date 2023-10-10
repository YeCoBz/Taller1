#pragma once
#include "Software.h"

class Security: public Software {
    private:
    string typeMalware;
    public:

    /**
     * Constructor de la clase Security.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param minAge Edad mínima requerida para el software.
     * @param price Precio del software.
     * @param typeMalware Tipo de malware que aborda el software de seguridad.
     */
    Security(string,string,string,double,string);
};

Security::Security(string name,string developer,string minAge,double price,string typeMalware) : Software(name,developer,minAge,price) {
    this->typeMalware = typeMalware;
}
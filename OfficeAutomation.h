#pragma once
#include "Software.h"

class OfficeAutomation : public Software {
    private:
    int numFiles;
    public:

    /**
     * Constructor de la clase OfficeAutomation.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param minAge Edad mínima requerida para el software.
     * @param price Precio del software.
     * @param numFiles Número de archivos manejados por el software de automatización de oficina.
     */
    OfficeAutomation(string,string,string,double,int);
};

OfficeAutomation::OfficeAutomation(string name,string developer,string minAge,double price,int numFiles) : Software(name,developer,minAge,price) {
    this->numFiles = numFiles;
}
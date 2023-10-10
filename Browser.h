#pragma once
#include <list>
#include "Software.h"

class Browser: public Software {
    private:
    list<string> pagesList;
    public:

    /**
     * Constructor de la clase Browser.
     * 
     * @param name Nombre del software.
     * @param developer Desarrollador del software.
     * @param minAge Edad mínima requerida para el software.
     * @param price Precio del software.
     */
    Browser(string,string,string,double);

    /**
     * Agrega una página a la lista de páginas del navegador.
     * 
     * @param page Página a agregar.
     */
    void addPages(string);
};

Browser::Browser(string name,string developer,string minAge,double price) : Software(name,developer,minAge,price) {}
void Browser::addPages(string page) { pagesList.push_back(page); }
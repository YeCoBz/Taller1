#pragma once
#include <list>
#include "Software.h"

class Browser: public Software {
    private:
    list<string> pagesList;
    public:
    Browser(string,string,int,double);
    void addPages(string);
};

Browser::Browser(string name,string developer,int minAge,double price) : Software(name,developer,minAge,price) {}
void Browser::addPages(string page) { pagesList.push_back(page); }
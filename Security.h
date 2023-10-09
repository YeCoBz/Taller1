#pragma once
#include "Software.h"

class Security: public Software {
    private:
    string typeMalware;
    public:
    Security(string,string,int,double,string);
};

Security::Security(string name,string developer,int minAge,double price,string typeMalware) : Software(name,developer,minAge,price) {
    this->typeMalware = typeMalware;
}
#pragma once
#include "Software.h"

class OfficeAutomation : public Software {
    private:
    int numFiles;
    public:
    OfficeAutomation(string,string,string,double,int);
};

OfficeAutomation::OfficeAutomation(string name,string developer,string minAge,double price,int numFiles) : Software(name,developer,minAge,price) {
    this->numFiles = numFiles;
}
#pragma once
#include "Software.h"

class OfficeAutomation : public Software {
    private:
    int numFiles;
    public:
    OfficeAutomation(string,string,int,double,int);
};

OfficeAutomation::OfficeAutomation(string name,string developer,int minAge,double price,int numFiles) : Software(name,developer,minAge,price) {
    this->numFiles = numFiles;
}
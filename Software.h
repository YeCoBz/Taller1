#pragma once
#include <list>
#include "User.h"

using namespace std;

class Software {
    private:
    string name;
    string developer;
    string minAge;
    list<User*> userList;
    double price;

    public:
    Software(string,string,string,double);
};

Software::Software(string name,string developer,string minAge,double price) {
    this->name = name;
    this->developer = developer;
    this->minAge = minAge;
    this->price = price;
}
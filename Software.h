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
    string getName();
    string getDeveloper();
    string getMinAge();
    double getPrice();
    string getUsers();
    virtual ~Software() {}
    virtual string toString() {}
};

Software::Software(string name,string developer,string minAge,double price) {
    this->name = name;
    this->developer = developer;
    this->minAge = minAge;
    this->price = price;
}
string Software::getName() {
    return name;
}
string Software::getDeveloper() {
    return developer;
}
string Software::getMinAge() {
    return minAge;
}
double Software::getPrice() {
    return price;
}
string Software::getUsers() {
    cout<<"    Usuarios del software:\n" << endl;
    for (User* user : userList) {
        cout << user->getName() << endl;
    }
}
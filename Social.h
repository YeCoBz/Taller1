#pragma once

#include <iostream>
#include <list>
#include "Software.h"
#include "User.h"

using namespace std;

class Social : public Software{
    private:
        list<User*> friendList;
    public:
        Social(string, string, string, double);
        void addFriend(User*);
};

Social::Social(string name, string developer, string age, double price) : Software(name, developer, age, price) {
    friendList = list<User*>();
}
void Social::addFriend(User* user) {
    friendList.push_back(user);
}

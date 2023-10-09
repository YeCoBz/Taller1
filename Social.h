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
        Social(string, string, int, double);
        void addFriend(User*);
};

Social::Social(string name, string developer, int age, double price) : Software(name, developer, age, price) {
    friendList = list<User*>();
}
void Social::addFriend(User* user) {
    friendList.push_back(user);
}

#pragma once
#include <iostream>

using namespace std;

class User {
    private:
    string name;
    string password;
    int age;
    string mail;
    bool logAccess;
    
    public:
    User(string,string,int,string,string);

    // Getters
    string getName();
    string getPassword();
    int getAge();
    string getMail();
    bool getlogAccess();

    //Setters
    void setName(string);
    void setAge(int);
    void setMail(string);
};

User::User(string name,string password,int age,string mail,string _logAccess) {
    this->name = name;
    this->password = password;
    this->age = age;
    this->mail = mail;
    if (_logAccess == "true") {
        this->logAccess = true;
    } else { 
        this->logAccess = false;
    }
}
string User::getName() {
    return name;
}
string User::getPassword() {
    return password;
}
int User::getAge() {
    return age;
}
string User::getMail() { 
    return mail; 
}
bool User::getlogAccess() {
    return logAccess;
}
void User::setName(string name) { 
    this-> name = name;
}
void User::setAge(int age) {
    this->age = age;
}
void User::setMail(string mail) { 
    this->mail = mail; 
}
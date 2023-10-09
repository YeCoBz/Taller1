#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

#include "User.h"
#include "Software.h"
#include "Game.h"
#include "OfficeAutomation.h"
#include "Production.h"
#include "Browser.h"
#include "Security.h"
#include "Social.h"

bool isUser(string m) {
    if (m!="1" || m!="2" || m!="3" || m!="4" || m!="5" || m!="6") {
        return true;
    }
    return false;
}

User* searchUserByName(list<User>& userList,string name) {

    for (User& user : userList) {
        
        if (user.getName() == name) {
            User *pUser = &user;
            return pUser;
        }
    }
    return NULL; 
}

void createObject(list<User>& userList,list<Software>& softList) {

    ifstream arch("README.md");
    string line;

    if (!arch.is_open()) {
        cout << "No se encontro el archivo" << endl;
        return;
     }

    while (getline(arch, line)) {
        istringstream stream(line);
        string token;
        vector<string> tokens;
        
        while (getline(stream, token, ';')) {
            tokens.push_back(token);
        }

        if (isUser(tokens[0])) {

            string nameUser = tokens[0];
            string password = tokens[1];
            int age = stoi(tokens[2]);
            string mail;
            string logAccess;

            if (tokens.size() == 3) {
                User user(nameUser,password,age,"","false");
            } else {
                mail = tokens[3];
                logAccess = tokens[4];
                User user(nameUser,password,age,mail,logAccess);
            }  
        } else {

            string nameSoft = tokens[1];
            string developer = tokens[2];
            int minAge = stoi(tokens[3]);
            double price = stod(tokens[4]);
            int cont = tokens.size();

            switch (stoi(tokens[0])) {

            case 1:
            {
                string gameGenre = tokens[5];
                Game game(nameSoft, developer, minAge, price, gameGenre);
                softList.push_back(game);
                break;
            }
            case 2:
            {
                int cant = stoi(tokens[5]);

                OfficeAutomation soft(nameSoft,developer,minAge,price,cant);
                softList.push_back(soft);
                break;
            }
            case 3:
            { 
                string typeProduction = tokens[5];

                Production production(nameSoft,developer,minAge,price,typeProduction);
                softList.push_back(production);
                break;
            }
            case 4:
            {

                Browser browser(nameSoft,developer,minAge,price);
                for (int i = 5; i < cont; i++)
                {
                    string page = tokens[i];
                    browser.addPages(page);
                }
            
                softList.push_back(browser);
                break;
            }
            case 5:
            {
                string typeMalware = tokens[5];
                Security security(nameSoft,developer,minAge,price,typeMalware);
                softList.push_back(security);
                break;
            }
            case 6:
            {
                string nameFriend;
                Social social(nameSoft,developer,minAge,price);
                
                for (int i = 5; i < cont; i++) {
                    nameFriend = tokens[i];
                    //User *u = searchUserByName(userList,nameFriend);
                    //social.addFriend(u);
                }
                
                softList.push_back(social);
                break;
            }
            default:
            {
                break;
            }
            
        }
        
        
        tokens.clear();
        
        }
        
    }

}

void menu(list<User>& userList,list<Software>& softList) {

}

int main()
{
    list<User> userList;
    list<Software> softList;

    createObject(userList,softList);
    menu(userList,softList);

    return 0;
}

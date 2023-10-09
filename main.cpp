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
bool searchUser(list<User>& userList, string mail, string password) {

    for (User& user : userList) {
        
        if (user.getMail() == mail && user.getPassword() == password) {
            cout<<" BIENVENIDO "<<user.getName()<<"!!!\n"<<endl;
            return true;
        }
    }
    return false;
}

User* searchUserByMail(list<User>& userList,string mail) {

    for (User& user : userList) {
        
        if (user.getMail() == mail) {
            User *pUser = &user;
            return pUser;
        }
    }
    return NULL;
}

bool isUser(string m) {
    if (m=="1"|| m=="2" || m=="3" || m=="4" || m=="5" || m=="6") {
        return false;
    }
    return true;
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

        cout << tokens[1] << endl;

        if (isUser(tokens[0])) {

            string nameUser = tokens[0];
            string password = tokens[1];
            int age = stoi(tokens[2]);
            string mail;
            string logAccess;

            if (tokens.size() == 3) {
                User user(nameUser,password,age,"","false");
                userList.push_back(user);
            } else {
                mail = tokens[3];
                logAccess = tokens[4];
                User user(nameUser,password,age,mail,logAccess);
                userList.push_back(user);
            }

            tokens.clear();
            
        } else {
            
            string nameSoft = tokens[1];
            string developer = tokens[2];
            string minAge = tokens[3];
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
                    User *u = searchUserByName(userList,nameFriend);
                    social.addFriend(u);
                }
                softList.push_back(social);
                break;
            }
            default:{break;}
            
            }
        tokens.clear(); 
        }  
    }
    arch.close();

}

void menuAdmin(list<User>& userList,list<Software>& softList) {

    int num;
    bool endCode = false;

    while (!endCode) {

        cout << "      MENU ADMINISTRADOR\n" << endl;
        cout << "1. Modificar los datos de usuarios." << endl;
        cout << "2. Modificar datos de softwares." << endl;
        cout << "3. Agregar pagina web a un navegador" << endl;
        cout << "4. Agregar un amigo a una red social" << endl;
        cout << "5. Cambiar de usuario" << endl;
        cout << "6. Terminar el programa\n" << endl;
        cout << "Ingrese la opcion que desea" << endl;
        cin >> num;
        cout << "\n" << endl;

        while (num > 5 || num < 1) {
            cout << "ERROR!!! POR FAVOR INGRESE UNA OPCION VALIDA\n" << endl;
            cout << "      MENU ADMINISTRADOR\n" << endl;
            cout << "1. Modificar los datos de usuarios." << endl;
            cout << "2. Modificar datos de softwares." << endl;
            cout << "3. Agregar pagina web a un navegador" << endl;
            cout << "4. Agregar un amigo a una red social" << endl;
            cout << "5. Cambiar de usuario" << endl;
            cout << "6. Terminar el programa\n" << endl;
            cout << "Ingrese la opcion que desea" << endl;
            cin >> num;
            cout << "\n" << endl;
        }

        if (num==5) {
            endCode = true;
            break;
        }

        switch (num)
        {
        case 1:
        {
            string mail;
            cout << "Ingrese el correo del usuario a modificar: " << endl;
            cin >> mail;
            cout << "\n" << endl;
            User *modifyUser = searchUserByMail(userList,mail);

            while (modifyUser == NULL) {
                cout << "ERROR!!! Este usuario no existe, por favor ingrese nuevamente el correo\n" << endl;
                cout << "Ingrese el correo del usuario a modificar: " << endl;
                cin >> mail;
                modifyUser = searchUserByMail(userList,mail);
                cout << "\n" << endl;
            }

            int modify;

            cout << "      DATO A MODIFICAR\n" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Correo" << endl;
            cout << "3. Edad" << endl;
            cout << "Ingrese la opcion que desea" << endl;
            cin >> modify;
            cout << "\n" << endl;

            while (modify > 3 || modify < 1) {
                cout << "ERROR!!! OPCION NO VALIDA\n" << endl;
                cout << "      DATO A MODIFICAR\n" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Correo" << endl;
                cout << "3. Edad" << endl;
                cout << "Ingrese la opcion que desea" << endl;
                cin >> modify;
                cout << "\n" << endl;
            }

            switch (modify)
            {
                case 1:
                {    
                    string newName;
                    cout << "Ingrese el nuevo nombre del usuario: " << endl;
                    cin >> newName;
                    modifyUser->setName(newName);
                    cout << "\n" << endl;
                    cout << "CAMBIO REALIZADO CON EXITO :)\n" << endl;
                    break;
                }
                case 2:
                {    
                    string newMail;
                    cout << "Ingrese el nuevo correo del usuario: " << endl;
                    cin >> newMail;
                    modifyUser->setMail(newMail);
                    cout << "\n" << endl;
                    cout << "CAMBIO REALIZADO CON EXITO :)\n" << endl;
                    break;
                }
                case 3:
                {   
                    string newAge;
                    cout << "Ingrese la nueva edad del usuario: " << endl;
                    cin >> newAge;
                    modifyUser->setAge(stoi(newAge));
                    cout << "\n" << endl;
                    cout << "CAMBIO REALIZADO CON EXITO :)\n" << endl;
                    break;
                }
                default:
                    break;
                }

            break;
        }
        case 2:
        {
            string softName;
            cout << "Ingrese " << endl;
            break;
        }
        case 3:
        {
            /* code */
            break;
        }
        case 4:
        {
            /* code */
            break;
        }
        default:
            break;
        }
    }

    if (num==6) {
        exit(0);
    } 
}
void menuUsuarioNormal(list<User>& userList,list<Software>& softList) {

}
void menuKid(list<User>& userList,list<Software>& softList) {

}

void menu(list<User>& userList,list<Software>& softList) {

    string mail;
    string password;
    cout << "Iniciar sesion: \n" << endl;
    cout <<"Correo electronico: "<< "(Si desea terminar el programa, ingrese fin)"<< endl;
    cin >> mail;
    if (mail=="fin") {
        exit(0);
    }
    cout << "contrasena: "<< "(Si desea terminar el programa, ingrese fin)" << endl;
    cin >> password;
    if (password=="fin") {
        exit(0);
    }
    cout << "\n" << endl;

    while(!searchUser(userList,mail,password)) {

        cout << "Correo o contrasena incorrecta\n" << endl;
        cout << "Iniciar sesion: " << "(Si desea terminar el programa, ingrese fin)"<< endl;
        cout << "Correo electronico: " << "(Si desea terminar el programa, ingrese fin)"<< endl;
        cin >> mail;
        if (mail=="fin") {
        exit(0);
        }   
        cout << "contrasena: " << endl;
        cin >> password;
        if (password=="fin") {
        exit(0);
        }
        cout << "\n" << endl;
    }

    User *user = searchUserByMail(userList,mail);

    switch (user->getlogAccess())
    {
    case true:
    {
        menuAdmin(userList,softList);
        break;
    }
    case false:
    {
        if (user->getMail() != "") {
            menuUsuarioNormal(userList,softList);
        } else {
            menuKid(userList,softList);
        }
        break;
    }
    default:
        break;
    }
}

int main()
{
    list<User> userList;
    list<Software> softList;

    createObject(userList,softList);
    menu(userList,softList);

    return 0;
}

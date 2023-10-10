#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
#include "User.h"
#include "Software.h"
#include "Game.h"
#include "OfficeAutomation.h"
#include "Production.h"
#include "Browser.h"
#include "Security.h"
#include "Social.h"

// Verifica si todos los usuarios quieren eliminar un software.
bool allUserAcept(list<User>& userList) {
    int cont = 0;
    for (User& user : userList) {
        cont++;
    }

    int answer;
    int contAnswer = 0;
    for (User& user : userList) {
        cout << user.getName() << "Desea eliminar el software? (1=si/2=no)" << endl;
        cin >> answer;
        if (answer == 1) { contAnswer++; }
    }

    if (cont == contAnswer) {
        return true;
    } else {
        return false;
    }
    
}
// Elimina un software de la lista.
void eliminarSoftware(list<Software>& listaSoftware,string nombreSoftware) {
    auto it = find_if(listaSoftware.begin(), listaSoftware.end(), [nombreSoftware](Software s) {
        return s.getName() == nombreSoftware;});

    if (it != listaSoftware.end()) {
        listaSoftware.erase(it);
        cout << "Software eliminado: " << nombreSoftware << endl;
    } else {
        cout << "Software no encontrado: " << nombreSoftware << endl;
    }
}
// Busca un software por nombre en la lista.
bool searchSoftByName(list<Software>& softList,string nameSoftware) {

    for (Software& soft : softList) {
        if (soft.getName() == nameSoftware) {
            return true;
        }
    }
    return false;
}
// Busca un usuario por correo y contraseña en la lista.
bool searchUser(list<User>& userList, string mail, string password) {

    for (User& user : userList) {
        
        if (user.getMail() == mail && user.getPassword() == password) {
            cout<<" BIENVENIDO "<<user.getName()<<"!!!\n"<<endl;
            return true;
        }
    }
    return false;
}
// Retorna un puntero al software encontrado por nombre.
Software* returnSoftByName(list<Software>& softList, string name){

    for (Software& software : softList) {
        
        if (software.getName() == name) {
            Software *pSoft = &software;
            return pSoft;
        }
    }
    return NULL;
}
// Muestra información específica del tipo de software.
void typeSoftware(Software* soft,User* user) {

    if (dynamic_cast<Game*>(soft)) {
        cout << "    "<< soft->getName() << endl;
        cout << "1. Informacion completa del juego." << endl;
        cout << "1" << endl;
    } else if (dynamic_cast<OfficeAutomation*>(soft)) {
        cout << "    "<< soft->getName() << endl;
        
        
    } else if (dynamic_cast<Production*>(soft)) {
        cout << "Processing Production" << endl;
        // Hacer algo específico para Productio
    } else if (dynamic_cast<Browser*>(soft)) {
        cout << "Processing Browser" << endl;
        // Hacer algo específico para Browser
    } else if (dynamic_cast<Social*>(soft)) {
        cout << "Processing Social" << endl;
        // Hacer algo específico para Social
    } else {
        cout << "Unknown software type" << endl;
    }
}
// Busca un usuario por correo en la lista.
User* searchUserByMail(list<User>& userList,string mail) {

    for (User& user : userList) {
        
        if (user.getMail() == mail) {
            User *pUser = &user;
            return pUser;
        }
    }
    return NULL;
}
// Verifica si la entrada corresponde a un usuario.
bool isUser(string m) {
    if (m=="1"|| m=="2" || m=="3" || m=="4" || m=="5" || m=="6") {
        return false;
    }
    return true;
}
// Busca un usuario por nombre en la lista y lo retorna.
User* searchUserByName(list<User>& userList,string name) {

    for (User& user : userList) {
        
        if (user.getName() == name) {
            User *pUser = &user;
            return pUser;
        }
    }
    return NULL; 
}
// Lee datos desde un archivo README y crea objetos User y Software en las listas correspondientes.
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
// Menús para administradores, usuarios normales y niños respectivamente, con opciones específicas para cada tipo.
void menuAdmin(list<User>& userList,list<Software>& softList,User *user) {

    int num;
    bool endCode = false;

    while (!endCode) {

        cout << "      MENU ADMINISTRADOR\n" << endl;
        cout << "1. Modificar los datos de usuarios." << endl;
        cout << "2. Modificar datos de softwares." << endl;
        cout << "3. Agregar un software nuevo a la biblioteca." << endl;
        cout << "4. Eliminar un software" << endl;
        cout << "5. Terminar el programa.\n" << endl;
        cout << "Ingrese la opcion que desea: " << endl;
        cin >> num;
        cout << "\n" << endl;

        while (num > 5 || num < 1) {
            cout << "ERROR!!! POR FAVOR INGRESE UNA OPCION VALIDA\n" << endl;
            cout << "      MENU ADMINISTRADOR\n" << endl;
            cout << "1. Modificar los datos de usuarios." << endl;
            cout << "2. Modificar datos de softwares." << endl;
            cout << "3. Agregar un software nuevo a la biblioteca." << endl;
            cout << "4. Eliminar un software" << endl;
            cout << "5. Terminar el programa.\n" << endl;
            cout << "Ingrese la opcion que desea: " << endl;
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
            cout << "\nIngrese el nombre del software:" << endl;
            cin >> softName;
            while (!searchSoftByName(softList,softName)) {
                cout << "ERROR!!! SOFTWARE NO ENCONTRADO, INGRESE NUEVAMENTE EL NOMBRE" << endl;
                cout << "\nIngrese el nombre del software:" << endl;
                cin >> softName;
            }
            Software *soft = returnSoftByName(softList,softName);
            typeSoftware(soft,user);
            break;
        }
        case 3:
        {
            string newSoft;
            cout << "¿Qué tipo de software desea agregar?\n" << endl;
            cout << "1. Juego" << endl;
            cout << "2. Ofimatica" << endl;
            cout << "3. Produccion" << endl;
            cout << "4. Browser" << endl;
            cout << "5. Security" << endl;
            cout << "6. Social\n" << endl;
            cout << "Ingresar opcion: \n" << endl;
            cin >> newSoft;

            while (isUser(newSoft)){
                cout << "ERROR!!! OPCION NO VALIDA\n" << endl;
                cout << "1. Juego" << endl;
                cout << "2. Ofimatica" << endl;
                cout << "3. Produccion" << endl;
                cout << "4. Browser" << endl;
                cout << "5. Security" << endl;
                cout << "6. Social\n" << endl;
                cout << "Ingresar opcion: \n" << endl;
                cin >> newSoft;
            }

            string name;
            string developer;
            string minAge;
            double price;

            switch (stoi(newSoft)) {
            {
            case 1:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Genero del juego: " << endl;
                string gameGenre;
                cin >> gameGenre;
                Game game(name,developer,minAge,price,gameGenre);
                softList.push_back(game);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 2:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                int numArch;
                cin >> numArch;
                OfficeAutomation of(name,developer,minAge,price,numArch);
                softList.push_back(of);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 3:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                string typeSolution;
                cin >> typeSolution;
                Production production(name,developer,minAge,price,typeSolution);
                softList.push_back(production);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 4:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                Browser browser(name,developer,minAge,price);
                softList.push_back(browser);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 5:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                string typeMalware;
                cin >> typeMalware;
                Security security(name,developer,minAge,price,typeMalware);
                softList.push_back(security);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 6:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                Social social(name,developer,minAge,price);
                softList.push_back(social);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 4:
        {
            string softName;
            cout << "\nIngrese el nombre del software:" << endl;
            cin >> softName;
            while (!searchSoftByName(softList,softName)) {
                cout << "ERROR!!! SOFTWARE NO ENCONTRADO, INGRESE NUEVAMENTE EL NOMBRE" << endl;
                cout << "\nIngrese el nombre del software:" << endl;
                cin >> softName;
            }
            eliminarSoftware(softList,softName);
            break;
        }
        default:
            break;
        }
    }

    if (num==5) {
        exit(0);
    } 
}
void menuUsuarioNormal(list<User>& userList,list<Software>& softList,User* user) {

    int num;
    bool endCode = false;

    while (!endCode) {

        cout << "      MENU USUARIO\n" << endl;
        cout << "1. Modificar mis datos." << endl;
        cout << "2. Agregar un software nuevo a la biblioteca." << endl;
        cout << "3. Eliminar un software" << endl;
        cout << "4. Terminar el programa.\n" << endl;
        cout << "Ingrese la opcion que desea: " << endl;
        cin >> num;
        cout << "\n" << endl;

        while (num > 5 || num < 1) {
            cout << "ERROR!!! POR FAVOR INGRESE UNA OPCION VALIDA\n" << endl;
            cout << "      MENU USUARIO\n" << endl;
            cout << "1. Modificar mis datos." << endl;
            cout << "2. Agregar un software nuevo a la biblioteca." << endl;
            cout << "3. Eliminar un software" << endl;
            cout << "4. Terminar el programa.\n" << endl;
            cout << "Ingrese la opcion que desea: " << endl;
            cin >> num;
            cout << "\n" << endl;
        }

        if (num==4) {
            endCode = true;
            break;
        }

        switch (num)
        {
        case 1:
        {
            
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
                    user->setName(newName);
                    cout << "\n" << endl;
                    cout << "CAMBIO REALIZADO CON EXITO :)\n" << endl;
                    break;
                }
                case 2:
                {    
                    string newMail;
                    cout << "Ingrese el nuevo correo del usuario: " << endl;
                    cin >> newMail;
                    user->setMail(newMail);
                    cout << "\n" << endl;
                    cout << "CAMBIO REALIZADO CON EXITO :)\n" << endl;
                    break;
                }
                case 3:
                {   
                    string newAge;
                    cout << "Ingrese la nueva edad del usuario: " << endl;
                    cin >> newAge;
                    user->setAge(stoi(newAge));
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
            string newSoft;
            cout << "¿Qué tipo de software desea agregar?\n" << endl;
            cout << "1. Juego" << endl;
            cout << "2. Ofimatica" << endl;
            cout << "3. Produccion" << endl;
            cout << "4. Browser" << endl;
            cout << "5. Security" << endl;
            cout << "6. Social\n" << endl;
            cout << "Ingresar opcion: \n" << endl;
            cin >> newSoft;

            while (isUser(newSoft)){
                cout << "ERROR!!! OPCION NO VALIDA\n" << endl;
                cout << "1. Juego" << endl;
                cout << "2. Ofimatica" << endl;
                cout << "3. Produccion" << endl;
                cout << "4. Browser" << endl;
                cout << "5. Security" << endl;
                cout << "6. Social\n" << endl;
                cout << "Ingresar opcion: \n" << endl;
                cin >> newSoft;
            }

            string name;
            string developer;
            string minAge;
            double price;

            switch (stoi(newSoft)) {
            {
            case 1:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Genero del juego: " << endl;
                string gameGenre;
                cin >> gameGenre;
                Game game(name,developer,minAge,price,gameGenre);
                softList.push_back(game);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 2:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                int numArch;
                cin >> numArch;
                OfficeAutomation of(name,developer,minAge,price,numArch);
                softList.push_back(of);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 3:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                string typeSolution;
                cin >> typeSolution;
                Production production(name,developer,minAge,price,typeSolution);
                softList.push_back(production);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 4:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                Browser browser(name,developer,minAge,price);
                softList.push_back(browser);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 5:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                cout << "Numero de archivos: " << endl;
                string typeMalware;
                cin >> typeMalware;
                Security security(name,developer,minAge,price,typeMalware);
                softList.push_back(security);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            {
            case 6:
                cout << "Nombre del software: " << endl;
                cin >> name;
                cout << "Nombre del desarollador: " << endl;
                cin >> developer;
                cout << "Edad minima del software (>18 o <18): " << endl;
                cin >> minAge;
                cout << "Precio del software: " << endl;
                cin >> price;
                Social social(name,developer,minAge,price);
                softList.push_back(social);
                cout << "\nSoftware guardado\n" << endl;
                break;
            }
            default:
                break;
            }
            break;
        }
        case 3:
        {
            string softName;
            cout << "\nIngrese el nombre del software:" << endl;
            cin >> softName;
            while (!searchSoftByName(softList,softName)) {
                cout << "ERROR!!! SOFTWARE NO ENCONTRADO, INGRESE NUEVAMENTE EL NOMBRE" << endl;
                cout << "\nIngrese el nombre del software:" << endl;
                cin >> softName;
            }

            if (allUserAcept(userList)) {
                eliminarSoftware(softList,softName);
            } else {
                cout << "No todos quieren eliminar el software" << endl;
            }
            
            break;
        }
        default: {
            break;
        }
        break;
        }    

    }

    if (num==5) {
        exit(0);
    } 
}
void menuKid(list<User>& userList,list<Software>& softList,User* user) {
    
    int num;
    bool endCode = false;

    while (!endCode) {

        cout << "      MENU KID\n" << endl;
        cout << "1. Mostrar mis datos." << endl;
        cout << "2. Terminar el programa.\n" << endl;
        cout << "Ingrese la opcion que desea: " << endl;
        cin >> num;
        cout << "\n" << endl;

        while (num > 5 || num < 1) {
            cout << "ERROR!!! POR FAVOR INGRESE UNA OPCION VALIDA\n" << endl;
            cout << "      MENU KID\n" << endl;
            cout << "1. Mostrar mis datos." << endl;
            cout << "2. Terminar el programa.\n" << endl;
            cout << "Ingrese la opcion que desea: " << endl;
            cin >> num;
            cout << "\n" << endl;
        }

        if (num==2) {
            endCode = true;
            break;
        } else {
            cout<< user->toString() << endl;
        }
    }

}
// Menú principal para iniciar sesión y dirigir al usuario al menú correspondiente.
void menu(list<User>& userList,list<Software>& softList) {

    string mail;
    string password;
    cout << "Iniciar sesion: \n" << endl;
    cout <<"Nombre: "<< "(Si desea terminar el programa, ingrese fin)"<< endl;
    cin >> mail;
    if (mail=="fin") {
        exit(0);
    }
    cout << "\ncontrasena: "<< "(Si desea terminar el programa, ingrese fin)" << endl;
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
        cout << "\ncontrasena: " << endl;
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
        menuAdmin(userList,softList,user);
        break;
    }
    case false:
    {
        if (user->getMail() != "") {
            menuUsuarioNormal(userList,softList,user);
        } else {
            menuKid(userList,softList,user);
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

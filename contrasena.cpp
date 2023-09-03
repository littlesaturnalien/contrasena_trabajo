#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#define MAX 20
using namespace std;

int length(char password[]);
void areUSure(char password[]);
void enterYourPassword(char password[]);

int main(){
    char password[MAX];
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;  
    printf("Crea tu nueva contrase%ca: \n", 164);//ñ en ASCII
    cin.getline(password, MAX);

    for (char c : password) {  
        if (isupper(c)) {  
            hasUpper = true;  
        }  
        if (islower(c)) {  
            hasLower = true;  
        }  
        if (isdigit(c)) {  
            hasDigit = true;  
        }
        if((int(c) >= 32 && int(c) <= 47) || //Código ASCII para caracteres especiales
            (int(c) >= 58 && int(c) <= 64) ||
            (int(c) >= 91 && int(c) <= 96) ||
            (int(c) >= 123 && int(c) <= 126)){
                hasSpecial = true;
            }
    } 

    if (length(password) >= 8 && hasUpper && hasLower && hasDigit && hasSpecial){
        printf("La contrase%ca es segura.\n", 164); //ñ en ASCII
        cout << endl;
        system("pause");
        system("cls");
        areUSure(password);
    } else{
        printf("La contrase%ca es insegura. Garantiza que no haya menos de 8 caracteres, y contenga\n", 164);
        printf("letras may%csculas, min%csculas, n%cmeros y caracteres especiales. \n", 163, 163, 163); //ú en código ASCII
        cout << endl;
        system("pause");
        system("cls");
        main();
    }
    return 0;
}


int length(char password[]){
    int length = strlen(password);
	return length;
}

void areUSure(char password[]){
    int opc;
    printf("  %cEST%CS DE ACUERDO CON TU NUEVA CONTRASE%cA?\n", 168, 181, 165); //¿, Á, Ñ en código ASCII
    cout << endl;
    printf("      1. S%c.\n", 161);
    printf("      2. No. Quiero reingresarla.\n");
    cout << endl;
    cout << "    ---> ";
    cin >> opc;

    cin.ignore();

    switch(opc){
        case 1: system("cls"); enterYourPassword(password); break;

        case 2: system("cls"); main(); break;

        default: 
            system("cls"); 
            areUSure(password);
            break;
    }
}

void enterYourPassword(char password[]){
    string typePwd;
    int attempts = 0;
    bool typing = false;

    do{
        cout << "            LOGIN            " << endl;
        cout << "           =======           " << endl;
        cout << endl;
        printf(" Contrase%ca: ", 164);
        char caracter;
        caracter = getch();
        typePwd = "";

        while(caracter != 13){ //El While se termina cuando se presiona Enter, código ASCII
            if (caracter != 8) { // Si se presiona Borrar, borra el último caracter de la contraseña, CÓDIGO ASCII
                typePwd.push_back(caracter);
                cout << "*";
            } else{
                if(typePwd.length() > 0){
                    cout << "\b \b";
                    typePwd = typePwd.substr(0, typePwd.length()-1);
                }
            }
            caracter = getch();
        }


        if(typePwd == password){
            typing = true;
            
        } else{
            cout << endl;
            printf(" LA CONTRASE%CA ES INCORRECTA \n", 165); //Ñ en código ASCII
            system("pause");
            attempts++;
            system("cls");
        }
    } while(typing == false && attempts < 3);

    if(typing == false){
        cout << endl;
        printf(" ACCESO DENEGADO. SALIENDO DEL PROGRAMA...\n");
    } else{
        cout << endl;
        printf(" ACCESO CONCEDIDO. BIENVENIDO AL SISTEMA\n");
    }
}
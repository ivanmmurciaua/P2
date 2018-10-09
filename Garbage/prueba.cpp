#include<cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct{
    char genero[20];
    int numero;
}TSKL;


void limpiarBuffer(){

    while(cin.get()!='\n');
    
    
}

int main(){

    TSKL biblioteca[2];
    char prueba[20];
    char pa[20];
    for(int i=0;i<1;i++){
    
    do{

    
    cout << "Introduce el genero" << endl;
    cin.getline(prueba,20);
    
    if(strlen(prueba)==0)
        cout << "Introduce" << endl;
    
    }while(strlen(prueba)==0);
    
    if(strcmp(prueba,"S")==0 || strcmp(prueba,"N")==0)
        cout << "Funciona" << endl;
    else
        cout << "No funciona" << endl;
    
    strcpy(biblioteca[i].genero,prueba);
    
    cout << "INtrouce num" << endl;
    cin >> biblioteca[i].numero;
    
        
    }
    
    for(int i=0;i<1;i++){
    
        cout << biblioteca[i].genero << endl;
        cout << biblioteca[i].numero << endl;
    }


}
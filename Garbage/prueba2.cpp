#include<cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct{
    string genero;
    int numero;
}TSKL;


void limpiarBuffer(){

    while(cin.get()!='\n');
    
    
}

int main(){

    TSKL biblioteca[2];
   string prueba;
    char pa[20];
    for(int i=0;i<1;i++){
    
    do{

    
    cout << "Introduce el genero" << endl;
    cin>>prueba;
    
    if(prueba=="")
        cout << "Introduce" << endl;
    
    }while(prueba=="");
    
    if(prueba=="S" || prueba == "N")
        cout << "Funciona" << endl;
    else
        cout << "No funciona" << endl;
    
    biblioteca[i].genero=prueba;
    
    cout << "INtrouce num" << endl;
    cin >> biblioteca[i].numero;
    
        
    }
    
    for(int i=0;i<1;i++){
    
        cout << biblioteca[i].genero << endl;
        cout << biblioteca[i].numero << endl;
    }


}
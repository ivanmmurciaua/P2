#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;

const int filas=6;
const int columnas=20;

typedef char TPalabra[columnas];

TPalabra palabra[filas]={
"",
"PROGRAMA",
"LENGUAJE",
"OBJETIVO",
"PRACTICA",
"NUMERO"
};

int main(){;

	int tamanyo=0;
	char juego[tamanyo];
	srand(time(NULL));
	int pal_al=rand()%5+1;
	int cont=0;

	cout << palabra[pal_al] << endl;
	cout << strlen(palabra[pal_al]) << endl;
	cout << "BIENVENIDO AL JUEGO DEL AHORCADO" << endl;

	tamanyo=strlen(palabra[pal_al])-1;
	
	for(int i=0;i<=tamanyo;i++){
		juego[i]='_';
	}

	for(int i=0;i<=tamanyo;i++){
		cout << juego[i] << " ";
	}
	cout << endl;

	
	char letra;
	do{
	cout << "Pon una letra: ";
	cin >> letra;

    for(int i=0;i<=tamanyo;i++){
    	if(palabra[pal_al][i]==letra)
    		juego[i]=letra;
    		cont++;
    }

    for(int i=0;i<=tamanyo;i++){
		cout << juego[i] << " ";
	}
	cout << endl;
	}while(cont>tamanyo);





}
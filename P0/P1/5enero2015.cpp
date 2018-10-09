#include <cstring>
#include <iostream>
using namespace std;

const int MAXL=500;
const int MAXE=40;

typedef struct{
	char titulo[255];
	char ISBN[9];
	char autor[255];
	char genero[255];
	int editorial;
}Libros;

typedef struct{
	int cod;
	char nombre[100];
	char direccion[100];
	char cor[100];
}Editoriales;

string generosd[5]={"suspense","romantica","historica","poesia","infantil"}; //Por si aca hay que hacer comparaciones que si el genero existe que si pollas pollas

Libros almacen[MAXL]={{"Antonio y el tesoro perdido","3468A21","Manolo","romantica",3},
					  {"Manolo y la cueva de los patos","3528A21","Antonio","historica",2},
					  {"Geografía segun el bicho","3346538A","El bicho","infantil",1},
					  {"El futbol de los ultimos años","334628B2","Maldini","historica",1}};

Editoriales editoriales[MAXE]={{1,"Editoriales el bicho","Calle 9","elbicho@gmail.com"},
							   {2,"Editorial tuputamadre","Calle yoquese","jajaxd@gmail.com"},
							   {3,"Editorial hastaloshuevos","Calle falsa123","possi@gmail.com"}};


void generoMayor(int &nummay, string &genmay){//esto lo hago porque dice que devuelva al main -.-""

	int arraygenerosquehay[5]={0,0,0,0,0};
	int b;

	for(int i=0;i</*MAXL*/4;i++){

		if(strcmp(almacen[i].genero,"suspense")==0)
			arraygenerosquehay[0]++;
		if(strcmp(almacen[i].genero,"romantica")==0)
			arraygenerosquehay[1]++;
		if(strcmp(almacen[i].genero,"historica")==0)
			arraygenerosquehay[2]++;
		if(strcmp(almacen[i].genero,"poesia")==0)
			arraygenerosquehay[3]++;
		if(strcmp(almacen[i].genero,"infantil")==0)
			arraygenerosquehay[4]++;

	}
	
		for(int i=0;i<5;i++){
			if(arraygenerosquehay[i]!=0){
			if(nummay<arraygenerosquehay[i]){
				nummay=arraygenerosquehay[i];
				genmay=generosd[i];
			}
			}
		}

	/*for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			if(arraygenerosquehay[i]>arraygenerosquehay[j]){
				b=arraygenerosquehay[i];
				arraygenerosquehay[i]=arraygenerosquehay[j];
				arraygenerosquehay[j]=b;

			}
		}*/

}

void mecagoentodoyaeh(){

char paco[255];
int p=5;
int edi=5;

cout << "Pls introdusca el nombre de un libro" << endl;
cin.getline(paco,255);

for(int i=0;i</*MAXL*/4;i++){

	if(strcmp(paco,almacen[i].titulo)==0)
		edi=almacen[i].editorial;	
}

for(int j=0;j<3;j++){
	if(edi==editoriales[j].cod)
		p=j;
}

//Esto es cebarse ya con el alumno...
cout << "La editorial: " << editoriales[p].nombre << " cuyo correo es " << editoriales[p].cor << " ha impreso ese libro" << endl;

		cout << "La editorial: " << editoriales[p].nombre << " ha impreso estos además " << endl;
		for(int z=0;z<4;z++){
				if(editoriales[p].cod==almacen[z].editorial)
					cout << "--> " << almacen[z].titulo << endl;
		}			
		

}


int main(){

int nummay;
string genmay;

generoMayor(nummay,genmay);
cout << "Del genero " << genmay << " hay "<< nummay << " libros" << endl;
mecagoentodoyaeh();
}
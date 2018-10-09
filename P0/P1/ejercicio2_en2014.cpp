#include <iostream>
using namespace std;

const int TMAXMED=500;
const int TMAXLAB=50;

typedef struct{
	int codigo;
	char nombre[100];
	char descripcion[100];
	double precioc;
	double preciov;
	int laboratorios[10];
}TMed;

typedef struct{
	int codigo;
	char nombre[100];
	char domsocial[100];
}TLab;

TMed medicamentos[TMAXMED]={{1000,"Paracetamol","Muy bueno para la resaca",23,54,{23,15,26,89}},
							{2000,"Gelocatil","Una maravilla",10,25,{34,23,26,89}},
							{5600,"QuoProVadis","Asi no tu",6,75,{65,29,34,97,23}}};
TLab laboratorios[TMAXLAB]={{23,"Quinton","Calle tuputamadre"},
							{97,"Pacopaco","Calle antonioasinotu"},
							{34,"JejeXd","Calle Paco"}};

int mayorBeneficio(){
	
	int max=0;
	int aux=0;
	int codigo=0;

	for(int i=0;i<TMAXMED;i++){
		aux=medicamentos[i].preciov-medicamentos[i].precioc;
	if(aux>max){
		max=aux;
		codigo=medicamentos[i].codigo;
	}

	}

	return(codigo);

}

void apartadoC(){

	int nummec[TMAXLAB];
	int cont=0;
	int max=0;
	int min=10000;
	int labmay;
	int labmen;

	for(int i=0;i</*TMAXLAB*/3;i++){
		cout << "El laboratorio: " << laboratorios[i].nombre << " situado en la " << laboratorios[i].domsocial << " produce estos medicamentos" << endl;
		cont=0;
		for(int j=0;j</*TMAXMED*/3;j++){
			for(int c=0;c<10;c++){
				if(laboratorios[i].codigo==medicamentos[j].laboratorios[c]){
					cout << "--> " << medicamentos[j].nombre << endl;
					cont++;}
			}


			
		}
		
		nummec[i]=cont;

		cout << endl;

	}

		for(int z=0;z</*TMAXLAB*/3;z++){
			if(nummec[z]!=0){
				if(max<nummec[z]){
					max=nummec[z];
					labmay=z;
				}
				if(min>nummec[z]){
					min=nummec[z];
					labmen=z;
				}
			}
		}

	cout << "El laboratorio que mayor variedad de productos produce es " << laboratorios[labmay].nombre << 
	" con " << max << " productos de variedad" << " y el que menos " << laboratorios[labmen].nombre << " con " << min << " productos de variedad." << endl << endl;

}

int main(){

	cout << endl << "El medicamento que mayor beneficio proporciona es " << mayorBeneficio() << endl << endl << endl;
	apartadoC();

	/*for(int i=0;i<1;i++)
		cout << medicamentos[i].codigo << ", "
	 		 << medicamentos[i].nombre << ", "
	 		 << medicamentos[i].descripcion << ", " 
	 		 << medicamentos[i].precioc << ", "
	 		 << medicamentos[i].preciov << ", " << endl;
	
	    for(int j=0;j<10;j++){
	    	if(medicamentos[0].laboratorios[j]!=0)
			cout << "Laboratorio -> " << medicamentos[0].laboratorios[j] << endl;
		}*/
}

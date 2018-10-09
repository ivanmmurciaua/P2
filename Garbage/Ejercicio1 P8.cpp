#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	
	int real;
	
	int imaginaria;
	
}TComplejo;

void leer(TComplejo&);

void mostrar(TComplejo);

TComplejo suma(TComplejo, TComplejo&);




int main () {
	
	TComplejo n;
	TComplejo m;
	
		leer(n);
		
		mostrar(n);
		
		leer(m);
		mostrar(m);
		cout << suma(n, m).real << "+" << suma(n,m).imaginaria << "i" << endl;
	
	
	
	
}


void leer(TComplejo& n){
	
	cout<<"Introduce la parte real: "<<endl;
	cin>>n.real;
	
	cout<<"Introduce la parte imagianria: "<<endl;
	cin>>n.imaginaria;
	
}


void mostrar(TComplejo n){
	
	
	if (n.imaginaria >0) 
	
		cout<<"\nEl numero complejo es: "<<n.real<<"+"<<n.imaginaria<<"i "<<endl;
	
	else
	
		cout<<"\nEl numero complejo es: "<<n.real<<""<<n.imaginaria<<"i "<<endl;	
}


TComplejo suma(TComplejo n, TComplejo& m){
	
	TComplejo resultado;

	resultado.real=n.real+m.real;
	resultado.imaginaria=n.imaginaria+m.imaginaria;

	return(resultado);
	
	
	

	
}






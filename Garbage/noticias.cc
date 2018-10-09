#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

bool checkArg(int argg){
	if(argg>1){
		return(true);
	}
	else{
		return(false);
	}

}

string argumento(int i,char const *argv[]){
	string pato;
	pato=argv[i];
	return(pato);
}

string cualEs(int i){
	switch(i){
		case 1: return("1");
		break;
		case 2 : return("2");
		break;
	}
}

string processRow(string s,vector<string> &fechas,vector<string> &personas,vector<string> &empresas,vector<string> &lugares){
	bool switchp=false;
	string resultado="";
	for(size_t i=0;i<s.size();i++){
		if(s[i]=='@'){
			if(!switchp){
					switchp=true;
				}
			else{
				switchp=false;
				fechas.push_back(resultado);
				resultado="";
			}
		}
		else if(switchp)
				resultado+=s[i];
		}
		
		for(size_t i=0;i<s.size();i++){
		if(s[i]=='$'){
			if(!switchp){
					switchp=true;
				}
			else{
				switchp=false;
				personas.push_back(resultado);
				resultado="";
			}
		}
		else if(switchp)
				resultado+=s[i];
		}
		for(size_t i=0;i<s.size();i++){
		if(s[i]=='*'){
			if(!switchp){
					switchp=true;
				}
			else{
				switchp=false;
				lugares.push_back(resultado);
				resultado="";
			}
		}
		else if(switchp)
				resultado+=s[i];
		}
		for(size_t i=0;i<s.size();i++){
		if(s[i]=='#'){
			if(!switchp){
					switchp=true;
				}
			else{
				switchp=false;
				empresas.push_back(resultado);
				resultado="";
			}
		}
		else if(switchp)
				resultado+=s[i];
		}
}

void mostrarDatos(vector<string> fechas,vector<string> personas,vector<string> empresas,vector<string> lugares){
	
	cout << "Fechas: ";
	for(size_t i=0;i<fechas.size();i++){
		cout << fechas[i] << "|";
	}
	cout << endl << "Personas: ";
	for(size_t i=0;i<personas.size();i++){
		cout << personas[i] << "|";
	}
	cout << endl << "Empresas: ";
	for(size_t i=0;i<empresas.size();i++){
		cout << empresas[i] << "|";
	}
	cout << endl << "Lugares: ";
	for(size_t i=0;i<lugares.size();i++){
		cout << lugares[i] << "|";
	}
	cout << endl;
}


const string filename="noticia";
int main(int argc, char const *argv[])
{
	vector<string> fechas,personas,empresas,lugares;
	if(checkArg(argc)){
		ifstream fl;
		for(int i=1;i<argc;i++){
			
			//string ficheroparatratar;
			fl.open(argumento(i,argv).c_str(),ios::in);
			if(fl.is_open()){
				string pepe;
				while(getline(fl,pepe)){
					processRow(pepe,fechas,personas,empresas,lugares);
					//processRow(pepe,personas,'$');
					//processRow(pepe,lugares,'*');
					//processRow(pepe,empresas,'#');
				}
			}
			else
				cout << "NO" << endl;
			fl.close();
		}
		mostrarDatos(fechas,personas,empresas,lugares);
	}
	else
		cout << "No has puesto suficientes argumentos"<< endl;
	return 0;
}

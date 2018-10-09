#include <iostream>
using namespace std;

const int TOTP=20;
const int TOTPR=5;

typedef struct{
	int codigo;
	char nombre[20];
	char proveedor[20];
	float precio;
	int stock;
	int stockmin;
	int stockmax;
}TProducto;

typedef struct{
	int CIF;
	char nombre[20];
	int telefono;
	char direccion[100];
	char sector[15]; //Varios tipos ?? ARRAY	
}TProveedor;


int menu(){

	int opcion=0;

	cout << "-------------MENU--------------" << endl;
	cout << "1. Dar de alta producto" << endl;
	cout << "2. Dar de alta proveedor" << endl;
	cout << "3. Dar de baja producto" << endl;
	cout << "4. Mostrar listado con los datos de los proveedores" << endl;
	cout << "5. Mostrar listado de pedidos a realizar" << endl << endl;
	cin >> opcion;
	return(opcion);

}

void darAltaP(int &p, TProducto productos[]){
	
	if(p<TOTP){
	cout << "Codigo" << endl;
	cin >> productos[p].codigo;
	cout << "Nombre" << endl;
	cin >> productos[p].nombre;
	cout << "Proveedor" << endl;
	cin >> productos[p].proveedor;
	cout << "Precio" << endl;
	cin >> productos[p].precio;
	cout << "Stock" << endl;
	cin >> productos[p].stock;
	cout << "Stock Max" << endl;
	cin >> productos[p].stockmax;
	cout << "Stock Min" << endl;
	cin >> productos[p].stockmin;
	p++;
	}
	else
		cout << "Has alcanzado el numero maximo de productos" << endl;

}


void darAltaPr(int &pr, TProveedor proveedores[]){
	
	if(p<TOTPR){
	cout << "CIF" << endl;
	cin >> proveedores[pr].CIF;
	cout << "Nombre" << endl;
	cin >> proveedores[pr].nombre;
	cout << "Telefono" << endl;
	cin >> proveedores[pr].telefono;
	cout << "Direccion" << endl;
	cin >> proveedores[pr].direccion;
	cout << "Sector" << endl;
	cin >> proveedores[pr].sector;
	pr++;
	}
	else
		cout << "Has alcanzado el numero maximo de proveedores" << endl;

}

kljfdklkdskldklksdñklfsdñkljdskljkljsdlkfklañlksñlkjsdflksdlñkjsadfñlksadflkñlksdfjkfikslsñalskdjfñlsdfksfla

int main(){

	TProducto productos[TOTP];
	TProveedor proveedores[TOTPR];
	int opcionelegida;
	int p=0;
	int pr=0;

	
	do{

		opcionelegida=menu();
		switch(opcionelegida){
			case 1: darAltaP(p,productos);
			break;
			case 2: darAltaPr(pr,proveedores);			;
			break;
			case 3: cout << "Jaja xd" << endl;
			break;
			case 4: cout << "Cara anchoa, caranchoa o caraanchoa.....this is the question" << endl;
			break; 
			case 5: cout << "Por el culo te la hinco" << endl;
			break;
		}
	}while(opcionelegida!=6);

	return 0;

}
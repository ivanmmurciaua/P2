#include <ctime>
#include <iostream>
using namespace std;

void rellena(int array[]){

	srand(time(NULL));
	for(int i=0;i<10;i++)
		array[i]=rand()%9+1;
	array[10]=0;
	
}
//Mover a la derecha
void mueve(int array[]){
	for(int i=11;i>0;i--)
			array[i]=array[i-1];

}

void muestra(int array[]){
	for(int i=0;i<11;i++)
		cout << array[i];

	cout << endl;
	
}

void ordenamen(int array[]){

	int aux;
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(array[i]<array[j]){
				aux=array[i];
				array[i]=array[j];
				array[j]=aux;
			}
		}
	}
}

void ordenamay(int array[]){

	int aux;
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(array[i]>array[j]){
				aux=array[i];
				array[i]=array[j];
				array[j]=aux;
			}
		}
	}
}

int main(){

	int array[11];	
	rellena(array);
	muestra(array);
	mueve(array);
	muestra(array);
	ordenamen(array);
	muestra(array);
	ordenamay(array);
	muestra(array);

}
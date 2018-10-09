#include <iostream>
using namespace std;

int calculo(int, int);

int main () {
	
	int x, y;
	
		cout<<"Introduce un numero: ";
		cin>>x;
		cout<<"Otro: ";
		cin>>y;
		cout<<"El maximo comun divisor es: "<<calculo(x,y);	
	
	getch();
	return 0;
}

int calculo(int x, int y){
	
	int n;
	
		if(x==y){
			n=x;
		}
		else if(x>y){
			n=calculo(x-y, y);
		}
		else if(x<y){
			n=calculo(x, y-x);
		}
		
	return n;
}

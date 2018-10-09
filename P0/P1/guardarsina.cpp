#include <iostream>
using namespace std;

int main(){

	int x=0;
	int cont=0;
	int sum=0;
	do{
	cout << "Introduce un numero: ";
	cin >> x;
	cont++;
	if(x!=-1)
	sum=sum*10+x;
	}while(x!=-1&&cont<6);

	cout << sum << endl;

}
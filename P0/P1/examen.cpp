#include <iostream>
using namespace std;


void rev(int num, int &cont){
	int numero[100];
	int rest;

	if(num==1){
		for(int i=cont;i>=0;i--){
			cout << numero[i] << num;
		}
	}
	num=num/2;
	rest=num%2;
	
	if(rest==0){
		numero[cont]=0;
		cont++;
	}
	else{
		numero[cont]=1;
		cont++;
	}
	rev(num,cont);
}
int main(){

	int num;
	int cont=0;

	cout << "Introduce un numero" << endl;
	cin >> num;

	rev(num,cont);

}
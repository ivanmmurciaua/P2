#include <iostream>
using namespace std;

int numeros[4][5]={{4,0,7,4,9},
				   {5,2,9,1,9},
				   {6,7,5,3,7},
				   {7,1,0,7,8}};

void ordenaPollas(){
	for(int i=0;i<4;i++){
		
		for(int j=0;j<5;j++)
			cout << numeros[i][j];
	  cout << endl;
		}

}



int main(){
	
ordenaPollas();

}
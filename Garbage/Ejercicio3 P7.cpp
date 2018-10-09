#include <iostream>
#include <cstring>
using namespace std;

void pedir(char[], char[], int&);

char letra(char[], char&, int, char&);

void sustituir(char[],char[], char&, int);


int main () {
	
	char palabra[15];
	char palabra2[15];
 	int n;
	char band;
	char x;
	int cont=0;
	
		pedir(palabra,palabra2, n);
		
		do{
		letra(palabra, band, n, x);
		
			if (band == 'V'){
				
				cout<<"\nLa letra esta en la palabra misteriosa. "<<endl;

						sustituir(palabra,palabra2, x, n);	
						cont++;

			
			}
				
			else{
				
				cout<<"\nLa letra no se encuentra en la palabra misteriosaa. "<<endl;
			}
			}while(cont<=9);
						
				
}


void pedir(char palabra[], char palabra2[], int &n){
	
	int i;
	char band;
	
	cout<<"Introduce la palabra deseada: "<<endl;
	cin.getline(palabra, 15);
	
		n = strlen(palabra);
	
		for(int i=0;i<n;i++){
		palabra2[i]='_';
	}

	for(int i=0;i<=n;i++){
		cout << palabra2[i] << " ";
	}
	cout << endl;
			
		
}


char letra(char palabra[], char &band, int n, char &x){
	
	int i;
	
	cout<<"\nIntroduce una letra: "<<endl;
	cin>>x;
	
		band = 'F';
		i = 0;
		while (band == 'F' && i<n){
			
			if (palabra[i] == x){
				
				band = 'V';
				
			}
			
			else
			
				band = 'F';
		i++;
			
		}
		
return(band);
	
}


void sustituir(char palabra[], char palabra2[],char &x, int n){
	
	int i;
	char aux;
	int cont = 0;
	
		for (i=0; i<n; i++){
				
				if (palabra[i] == x){
				
					//aux = x;
					palabra2[i]=x;
				
						
				
				}

			
			
				
		}
		for(int i=0;i<=n;i++){
						cout << palabra2[i] << " ";
						}
			
					
}

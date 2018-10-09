#include <iostream>
#include <cstring>

using namespace std;

void extractData(char data[]){

  int cont=0;
  char datos[255];

  cont=strlen(data);
  
  for(int i=0;i<=cont;i++){
    int contdata=0;
    while(data[i]!=':' && i<=cont && data[i]!='\0'){
          datos[contdata]=data[i];
          contdata++;
          i++;
      }
    
    int j=0;
    bool comp=true;
          
    while(comp && j<contdata){
      if(datos[j]>='0' && datos[j]<='9')
        comp=false;
      j++;
    }
    
    if(comp){
      for(int i=0;i<contdata;i++)
        cout << datos[i];
      cout << endl;
    }      

  }

};

int main(){

  cout << "Exercise 4:" << endl;
  char cad[] = "12345678:Perez Perez, Pedro:  12.4: C/Rue del Percebe, no. 13: Aviador";
  cout << "extractData(\"" << cad << "\")" << endl;
  extractData(cad);
  char otra[] = "c4d3n4 c0n num3r0s: Perez; Perez+- * Pedro: ab12.4:   Piloto X-Wing";
  cout << "extractData(\"" << otra << "\")" << endl;
  extractData(otra);
  cout << "-------------------------------------" << endl;

}
//DNI 48729799K MAÑÚS MURCIA,IVÁN
#include <iostream>
#include <cstring>

using namespace std;

int getIntermediate(int a,int b,int c){
  
  int aux;

  if(a>b)
    aux=a;
  else
    aux=b;
  
  if(aux>c)
    return(c);
  else
    return(aux);

};

int diamond(int n){
  int fila=0;
        int cont=0;

        while(fila<n){
            if(fila==0){
                for(int c=n-1;c>0;c--)
                    cout << " ";
                cout << "0";

            }
            else{
                for(int v=n-1;v>0;v--){
                    if(fila==v||v<fila)
                        cout << v;
                    else
                        cout << " ";
                }
                cout << "0";
            }
            if(fila==0){
                for(int z=1;z<n;z++)
                    cout << " ";
            }
            else{
                for(int f=1;f<n;f++){
                    if(f==fila||f<fila)
                        cout << f;
                    else
                        cout << " ";
                }
            }
            cout << endl;
            fila++;
            cont++;
        }
        
        fila=fila-2;

        while(fila>=0){
            if(fila==0){
                for(int c=n-1;c>0;c--)
                    cout << " ";
                cout << "0";

            }
            else{
                for(int v=n-1;v>0;v--){
                    if(fila==v||v<fila)
                        cout << v;
                    else
                        cout << " ";
                }
                cout << "0";
            }
            if(fila==0){
                for(int z=1;z<n;z++)
                    cout << " ";
            }
            else{
                for(int f=1;f<n;f++){
                    if(f==fila||f<fila)
                        cout << f;
                    else
                        cout << " ";
                }
            }
            cout << endl;
            fila--;
            cont++;
        }
        return(cont);
};

bool binary8bits(int n,char b[]){

  bool res=false;
  char control[255];

  if(n<0||n>255)
    return(res);
  
  else{

    //Conversión a binario
    
    int cont=0;
    int resto=0;

    while(n!=1){
      resto=n%2;
      n=n/2;

      if(resto==0)
        control[cont]='0';
      else
        control[cont]='1';

      cont++;
    }

    if(n==1)
      control[cont]='1';
    else
      control[cont]='0';

      while(cont<=6){
        cont++;
        control[cont]='0';
      }

      control[cont+1]='\0'; //Final de array

      //Copia de array al derecho para devolverlo bien
      
      int contb=0;
      
      for(int i=cont;i>=0;i--){
        b[contb]=control[i];
        contb++;
      }

      b[contb]='\0';

      res=true;
      return(res);
  }

};

void extractData(char data[]){

  int cont=0;
  char varcon='0';
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




/*

La salida del programa debe ser:

Exercise 1:
getIntermediate(1,-7,4)    1
getIntermediate(15,-2,14)  14
getIntermediate(0,0,1)     0
-------------------------------------
Exercise 2:
diamond(4)
   0   
  101  
 21012 
3210123
 21012 
  101  
   0   
number of lines: 7
diamond(8)
       0       
      101      
     21012     
    3210123    
   432101234   
  54321012345  
 6543210123456 
765432101234567
 6543210123456 
  54321012345  
   432101234   
    3210123    
     21012     
      101      
       0       
number of lines: 15
-------------------------------------
Exercise 3:
binary8bits(28,...) = 00011100
binary8bits(187,...) = 10111011
binary8bits(255,...) = 11111111
-------------------------------------
Exercise 4:
extractData("12345678:Perez Perez, Pedro:  12.4: C/Rue del Percebe, no. 13: Aviador")
Perez Perez, Pedro
 Aviador
extractData("c4d3n4 c0n num3r0s: Perez; Perez+- * Pedro: ab12.4:   Piloto X-Wing")
 Perez; Perez+- * Pedro
   Piloto X-Wing
-------------------------------------


*/


int main()
{
  cout << "Exercise 1:" << endl;
  cout << "getIntermediate(1,-7,4)    " << getIntermediate(1,-7,4) << endl;
  cout << "getIntermediate(15,-2,14)    " << getIntermediate(15,-2,14) << endl;
  cout << "getIntermediate(0,0,1)    " << getIntermediate(0,0,1) << endl;/*
  cout << "getIntermediate(-17,20,23)    " << getIntermediate(-17,20,23) << endl;
  cout << "getIntermediate(5,4,8)    " << getIntermediate(5,4,8) << endl;
  cout << "getIntermediate(16,5,8)    " << getIntermediate(16,5,8) << endl;
  cout << "getIntermediate(9,18,33)    " << getIntermediate(9,18,33) << endl;
  cout << "getIntermediate(2,40,19)    " << getIntermediate(2,40,19) << endl;*/
  cout << "-------------------------------------" << endl;
  
  cout << "Exercise 2:" << endl;
  cout << "diamond(4)" << endl;
  int nlineas=diamond(4);
  cout << "number of lines: " << nlineas << endl;
  cout << "diamond(8)" << endl;
  nlineas=diamond(8);
  cout << "number of lines: " << nlineas << endl;
  cout << "-------------------------------------" << endl;
  
  cout << "Exercise 3:" << endl;
  char b[100];
  cout << binary8bits(28,b) << endl;
  cout << "binary8bits(28,...) = " << b << endl;
  cout << binary8bits(187,b) << endl;
  cout << "binary8bits(187,...) = " << b << endl;
  cout << binary8bits(255,b) << endl;
  cout << "binary8bits(255,...) = " << b << endl;
  cout << "-------------------------------------" << endl;
  
  cout << "Exercise 4:" << endl;
  char cad[] = "12345678:Perez Perez, Pedro:  12.4: C/Rue del Percebe, no. 13: Aviador";
  //char cad[] = "12345678:Perez Perez, Pedro";
  cout << "extractData(\"" << cad << "\")" << endl;
  extractData(cad);
  char otra[] = "c4d3n4 c0n num3r0s: Perez; Perez+- * Pedro: ab12.4:   Piloto X-Wing";
  cout << "extractData(\"" << otra << "\")" << endl;
  extractData(otra);
  cout << "-------------------------------------" << endl;
}
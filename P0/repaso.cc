//DNI 48729799K MAÑÚS MURCIA,IVÁN
#include <iostream>

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
  char varco;
  char hola='a';
  char datos[255];
  char datosbuenos[255];
  
  // Sin strlen, total de la frase

  do{
    cont++;
    varco=data[cont];
  }while(varco!='\0');
  
    for(int i=0;i<=cont;i++){
      
      int contdata=0;
      
      do{   
        if(hola!='\0'){
          hola=data[i];
          datos[contdata]=data[i-1];
          contdata++;
          i++;
        }
      }while(hola!=':' && i<=cont);
      
      int j=0;
      int contp=0;
      bool comp=true;
          
      do{
        if(datos[j]>=48 && datos[j]<=57)
          comp=false;
        j++;
      }while(comp && j<contdata);

    if(comp){

    for(int i=0;i<contdata;i++)
      cout << datos[i];
      cout << endl;
    }      

  }

};
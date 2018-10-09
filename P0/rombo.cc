#include<iostream>
using namespace std;
 
int main()
{


    int a; //contador de lineas
    int b;  //contador de hashes #
    int c;  //contador de espacios =num total de lineas - 2
    int n;
   
    
           cout << "Ingrese la Altura de la Piramide: " << endl;
           cin >> n;
           
               for(a=1;a<=n-1;a++){
                  
               
                    for (c=n-2;c>=a;c--)
                        cout << (" ");
                       
                  
                    for (b=1;b<=a;b++)
                        cout << b;  
           
             
      
       
                 cout << endl;   
           
      }    


 
    int i;
    int m;
    int valor;
 
 
    cout<<"introduzca valor (1-7)"<<endl;
    cin>>valor;
    cout<<endl;
 
    for(i=1;i<valor;i++){
        for(m=0;i>=m;m++)
             cout << m;
            cout << endl;
        //printf("\n");
 
    }
 
}

    /*# include <iostream>
    using namespace std ;

    int main (){
        int n=5;
        int fila=0;

        for (int j = 0; j < n ; ++j) {
            for (int i = 0; i < n-j-1; ++i)
                cout << " ";
            for (int i = 0; i < 2*j+1; ++i)
                 if(fila!=0){
                    int control=fila;
                 cout << fila ; 
                 control--;
                 }
                 else{
                    cout << '0';
                 }
                 
            cout << endl ;
            fila++;
    }*/

    /*for(int p=1;p<n-1;p++){
        for(int espacios=n-1;espacios>0;espacios--){
            cout << "";
        }
        for(int a=0;a<n-1;a++){
            cout << a;
        }
        cout << endl;
    }*/

    




    /*

    fila=1;
         cout << endl << endl;

         for(int i=0;i<n;i++){
                for(int t=fila;t>0;t--){
                cout << t;
            }
            cout << '0' << endl;
            fila++;
         }

         
         fila=1;

    for(int i=0;i<n;i++){
        
        if(fila>=1){
            for(int t=1;t<fila;t++){
                cout << t;
            }
            cout << endl;
            fila++;
        }



        for(int j=0;j<n-i-1;j++)
            cout << " ";
        cout << 0 << endl;
        if(fila==1){


        }*/
        
    





/*{
    int n ;
    cout << " Ingrese un numero : " ;
    cin >> n ;
    for (int j = 0; j < n ; ++j) {
        for (int i = 0; i < n-j-1; ++i)
            cout << " ";
        for (int i = 0; i < 2*j+1; ++i)
             cout << i ;
        cout << endl ;
    }

    for (int j=n-2; j>=0; --j) {
        for (int i=0; i<n-j-1; ++i)
            cout << " " ;
        for (int i=0; i<2*j+1; ++i)
            cout << i ;
        cout << endl ;
    }
    return 0;
}*/
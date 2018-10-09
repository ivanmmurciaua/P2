# include <iostream>
    using namespace std ;

    int main (){
        int n=5;
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

        cout << "Numero de lineas: " << cont << endl;


    }
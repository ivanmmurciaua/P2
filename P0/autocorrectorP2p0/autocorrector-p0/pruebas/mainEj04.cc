
#include <iostream>
#include <cstring>

using namespace std;

void extractData(char data[]);


int main()
{
  cout << "Exercise 4:" << endl;
  char cad[] = "12345678:Perez Perez, Pedro:  12.4: C/Rue del Percebe, no. 13: Aviador";
  cout << "extractData(\"" << cad << "\")" << endl;
  extractData(cad);
  char otra[] = "c4d3n4 c0n num3r0s: Perez; Perez+- * Pedro: ab12.4:   Piloto X-Wing";
  cout << "extractData(\"" << otra << "\")" << endl;
  extractData(otra);
}

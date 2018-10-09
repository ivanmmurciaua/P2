#include <fstream>
#include <iostream>
using namespace std;

const string filename="pepe.txt";
int main(int argc, char const *argv[])
{
	ofstream fesc;
	fesc.open(filename.c_str(),ios::out);
	if(fesc.is_open()){
		fesc << "Hola esta es la primera linea xd" << endl;
		fesc << "Pepe está en la segunda y sacabú";
		fesc.close();
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}

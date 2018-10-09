
#include <iostream>
#include <cstring>

using namespace std;

int diamond(int n);

int main()
{
  cout << "Exercise 2:" << endl;
  cout << "diamond(4)" << endl;
  int nlineas=diamond(4);
  cout << "number of lines: " << nlineas << endl;
  cout << "diamond(8)" << endl;
  nlineas=diamond(8);
  cout << "number of lines: " << nlineas << endl;
}

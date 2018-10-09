
#include <iostream>
#include <cstring>

using namespace std;

bool binary8bits(int n,char b[]);

int main()
{
  cout << "Exercise 3:" << endl;
  char b[100];
  binary8bits(28,b);
  cout << "binary8bits(28,...) = " << b << endl;
  binary8bits(187,b);
  cout << "binary8bits(187,...) = " << b << endl;
  binary8bits(255,b);
  cout << "binary8bits(255,...) = " << b << endl;
}

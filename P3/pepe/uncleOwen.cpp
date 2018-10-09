#include <iostream>
#include <cstdlib>

using namespace std;

//#include "Farm.h"
//#include "Util.h"

void menu(int hour){
  cout << "-----========== Farm manager ==========-----" << endl
       << "1- List farm info" << endl
       << "2- Add field" << endl
       << "3- Add android" << endl
       << "4- Start working hour ("<< hour << ")" << endl
       << "q- Quit" << endl
       << "Option: " ;
}

#include "Farm.h"

int main(){
	Android a1;
	//Field f1("paco");
	cout << a1;
	Farm farm("west farm");
	Android a2("asdfgh",789);
	cout << a2;
	cout << farm;
	//cout << f1 << endl;
	//return 0;

   //Farm farm("west farm");
   char option;
   int hour=1;

   do {
        menu(hour);
        cin >> option; cin.get();

        switch (option) {
          case '1': cout << farm;
            break;
          case '2': farm.createField("antonio");
          cout << farm.getNumAndroids() << endl;
            break;
          //case '3': farm.createAndroid();
            //break;
          //case '4': farm.startWorkingHour(hour);
            //break;
          case 'q':
            break;
          //default: Util::error(ERR_UNKNOWN_OPTION);

        }
   } while (option != 'q');
}

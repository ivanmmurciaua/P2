//DNI 48729799K MAÑUS MURCIA,IVÁN
#include <iostream>
#include <climits>
#include <vector>
#include <string>

using namespace std;

// ---------------- android -------------------------
const int NUMDROIDMODELS=5;

const string droidModels[NUMDROIDMODELS] = { 
   "x-75",
   "fx-7",
   "JK9",
   "XAR-25",
   "HC-2"
};


enum Status {ST_WORKING, ST_IDLE};

typedef struct {
   string model; 
   int speed;
   int serialNumber;
   Status status; 
} Android;

// ---------------- field -------------------------

int const WORK_HOURS=5;

typedef struct {
   string name;
   int products;
   vector<Android> androids;
} Field;

// ---------------- farm --------------------------

typedef struct {
  string name;
  vector<Field> fields;
  vector<Android> androids;
} Farm;

// ---------------- error -------------------------

enum Error {ERR_NO_FIELDS, ERR_UNKNOWN_OPTION, ERR_WRONG_MODEL, ERR_WRONG_FIELD, ERR_WRONG_SPEED, ERR_WRONG_PRODUCTS, ERR_NAME}; 

void error(Error n){
  switch (n) {
   
    case ERR_NO_FIELDS:
      cout << "Error, there are no fields in the farm" << endl;
      break;
      
    case ERR_UNKNOWN_OPTION:
      cout << "Error, unknown option" << endl;
      break;

    case ERR_WRONG_MODEL:
      cout << "Error, wrong android model name" << endl;
      break;

    case ERR_WRONG_FIELD:
      cout << "Error, wrong field name" << endl;
      break;

    case ERR_WRONG_SPEED:
      cout << "Error, wrong speed" << endl;
      break;

    case ERR_WRONG_PRODUCTS:
      cout << "Error, wrong number of products" << endl;
      break;

    case ERR_NAME:
      cout << "Error, field name repeated" << endl;
      break;
  }

}

//---------------------------------------------------------------
const string HEADER1="---- start ----";
const string HEADER2="---- distribution ----";
const string HEADER3="---- end ----";
//---------------------------------------------------------------

 //clear buffer
void clearBf(){

  while (cin.get() != '\n');
}

 // validate model of Android
bool validModel(string model){

  bool result=false;

  for(int i=0;i<NUMDROIDMODELS;i++){
    if(model==droidModels[i])
      result=true;
  }

  return(result);
}

 // validate that the dato sea mayor que 0
bool validHigherThan0(int quantity){

  bool result=true;

  if(quantity<=0)
    result=false;

  return(result);
}

 // validate the repetition of field name
bool equalityFarmName(string fname, const Farm &farm){

    bool result=true;
  
    for(size_t i=0;i<farm.fields.size();i++){
      if(fname==farm.fields[i].name)
        result=false;
    }
  
    return(result);
}

 // at least one field in the farm
bool atLeastOne(const Farm &farm){

  bool result=true;

  if(farm.fields.size()==0)
    result=false;

  return(result);
}

 // comprobate that there are more than 0 products to recollect
bool dif0(const Farm &farm, int tamanyo){

  bool result=false;

  for(size_t i=0;i<farm.fields.size();i++){
    if(farm.fields[i].products!=0)
      result=true;
  }
  return(result);
}

// position of the elected field to add products
int positionOfField(string farmname, const Farm &farm){
  int result=0;

  for(size_t i=0;i<farm.fields.size();i++){
    if(farmname==farm.fields[i].name){
      result=i;
    }
  }
  return(result);
}

 // prints android info
void printAndroid(const Android &android){

  cout << "[" << android.model << " sn=" << android.serialNumber << " s=" << android.speed << " st=" << android.status << "]" << endl;
}

// prints field info
void printField(const Field &field){
  
  cout << "{Field: " << field.name << "(" << field.products << ")" << endl;

    for(size_t i=0;i<field.androids.size();i++)
      printAndroid(field.androids[i]);

    cout << "}" << endl; 
}

// prints farm info
void printFarm(const Farm &farm){
  
  cout << "Farm: " << farm.name << endl;
  
  for(size_t i=0;i<farm.fields.size();i++)
    printField(farm.fields[i]);

  for(size_t i=0;i<farm.androids.size();i++)
    printAndroid(farm.androids[i]);
}

// Creates a new android asking the data to the user given nextSerialNumber, and
// adds the android to the farm
void createAndroid(Farm &farm, int &nextSerialNumber){
  
  Android a;
  string model="";
  int velocity;
  
  cout << "Enter android speed: ";
    cin>>velocity;
    
    if(validHigherThan0(velocity)){
      clearBf();
      cout << "Enter android model: ";
        getline(cin,model);
        //cin>>model;

      if(validModel(model)){
        a.model=model;
        a.speed=velocity;
        a.serialNumber=nextSerialNumber;
        a.status=ST_IDLE;
        farm.androids.push_back(a);
        nextSerialNumber++;
      }
      else
        error(ERR_WRONG_MODEL);
    }
    else
      error(ERR_WRONG_SPEED);
}

// creates a new field in the farm with the name provided by the user
void createField(Farm &farm){

  Field f;
  string fname="";

  cout << "Enter field name: ";
    //cin >> fname;
    getline(cin,fname);
  if(equalityFarmName(fname,farm)){
    f.name=fname;
    f.products=0;
    farm.fields.push_back(f);
  }
  else
    error(ERR_NAME);
}

//distribute the androids
void distribution(Farm &farm, int position){

  int maxsp=0;
  Android android;
  int pos;

  for(size_t i=0;i<farm.androids.size();i++){
        if(farm.androids[i].speed>maxsp){
          maxsp=farm.androids[i].speed;
          pos=i;
        }
  }

  android.model=farm.androids[pos].model;
  android.speed=farm.androids[pos].speed;
  android.serialNumber=farm.androids[pos].serialNumber;
  android.status=ST_WORKING;

  farm.fields[position].androids.push_back(android);
  farm.androids.erase(farm.androids.begin()+pos);
} 

// distributes the farm's androids among its fields
void distributeAndroids(Farm &farm){
  
  int fieldNum=farm.fields.size();
  vector<int> iguales;

  if(dif0(farm,fieldNum)){

    while(farm.androids.size()>0){
      int min=INT_MAX;
      int max=0;
      int pos,tamanyo;
      
      for(size_t i=0;i<farm.fields.size();i++){
        tamanyo=farm.fields[i].androids.size();
          if(tamanyo<min)
            min=tamanyo;
          if(tamanyo==min)
            iguales.push_back(i);
      }

      for(size_t i=0;i<iguales.size();i++){
        if(farm.fields[iguales[i]].products>max){
          max=farm.fields[iguales[i]].products;
          pos=i;  //POSICION DEL CAMPO CON MAS PRODUCTOS Y NUM IGUAL DE ANDROIDES
        }
      }
      iguales.clear();
      distribution(farm,pos);
    }
  } 
}

//return one android to recollect
Android recollectAndroids(Field &field,int pos){
  Android android;
  android.model=field.androids[pos].model;
  android.speed=field.androids[pos].speed;
  android.serialNumber=field.androids[pos].serialNumber;
  android.status=ST_IDLE;
  return(android);
}

// simulates the collection of products in a field by its androids
void collectField(Field &field){

  int vel=0;

  for(size_t i=0;i<field.androids.size();i++)
    vel=vel+field.androids[i].speed;
  field.products=field.products-(vel*WORK_HOURS);
  if(field.products<0)
    field.products=0;
}

// collects the products in the farm's fields
void collectFarm(Farm &farm){

  cout << HEADER1 << endl;
  printFarm(farm);
  cout << HEADER2 << endl;
  distributeAndroids(farm);
  printFarm(farm);
  cout << HEADER3 << endl;
  for(size_t i=0;i<farm.fields.size();i++){
    collectField(farm.fields[i]);
    for(size_t j=0;j<farm.fields[i].androids.size();j++)
      farm.androids.push_back(recollectAndroids(farm.fields[i],j));
    farm.fields[i].androids.clear();
  }

  printFarm(farm);
}

// asks for products data in the farm's fields, then collects them
void startWorkingDay(Farm &farm){

  if(atLeastOne(farm)){
    string option="";
    int products=0;

      do{
        cout << "Enter field name: ";
        getline(cin,option);
        cin.clear();

        if(option!="q"){
          if(!equalityFarmName(option,farm)){
            cout << "Products: ";
            cin >> products;
            clearBf();
            if(validHigherThan0(products)){
              farm.fields[positionOfField(option,farm)].products=farm.fields[positionOfField(option,farm)].products+products;
            }
            else
              error(ERR_WRONG_PRODUCTS);
          }
          else
            error(ERR_WRONG_FIELD);
        }

      }while(option!="q");
      collectFarm(farm);
  }
  else
    error(ERR_NO_FIELDS);
}

void menu(){
  cout << "-----========== Farm manager ==========-----" << endl
       << "1- List farm info" << endl
       << "2- Add field" << endl
       << "3- Add android" << endl
       << "4- Start working day" << endl
       << "q- Quit" << endl
       << "Option: " ;
}

int main(){

   Farm farm;
   farm.name = "west farm";
   char option;
   int nextSerialNumber = 100;  

   do {
        menu();
        cin >> option; cin.get();
        
        switch (option) { 
          case '1': {printFarm(farm);
            break;
          }
          case '2': {createField(farm);
            break;
          }
          case '3': {createAndroid(farm,nextSerialNumber);
            break;
          }
          case '4': {startWorkingDay(farm);
            break;
          }
          case 'q': {
            break;
          }
          default:  {
            error(ERR_UNKNOWN_OPTION); 
            break;
          }
        }
   } while (option != 'q');
   
   return 0;
}
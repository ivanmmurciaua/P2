//DNI 48729799K MAÑÚS MURCIA,IVÁN
#include <iostream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

// ---------------- android -------------------------
const int NUMDROIDMODELS=25;

typedef struct {

  string modelName;
  int    hoursMaintenance;

} AndroidData;

const AndroidData ANDROIDDATA[NUMDROIDMODELS] = 
  {
    "x-75", 8,
    "fx-7", 10,
    "JK9", 15,
    "XAR-25", 5,
    "HC-2", 12,
    "Xj 23 v7.5", 10,
    "c3p0-2", 20,
    "r2d2", 15,
    "f9-x d27", 10,
    "-v65 +23", 11,
    "@prog2ua", 13,
    "#h45ht4g", 18,
    "fx-9", 10,
    "x-7", 12,
    "JK10", 7,
    "GHR tdi9", 10,
    "fx-8", 20,
    "fx-75", 5,
    "JK9-75", 14,
    "HC-3.7", 12,
    "xw-a87", 17,
    "tiDef 8", 25,
    "fx-5", 10,
    "fx-3", 8,
    "fx-4", 9
 };

enum Status {
  ST_WORKING, 
  ST_IDLE, 
  ST_MAINTENANCE0,
  ST_MAINTENANCE1 
};

typedef struct {

   string model;
   int speed;
   int serialNumber;
   Status status;
   int hoursWorked;
   
} Android;

// ---------------- field -------------------------

typedef struct {

   string name;
   int products;
   int hoursLeft;
   
   vector<Android> androids;
} Field;

// ---------------- farm --------------------------

const int DAILY_WORKING_HOURS=10;

typedef struct {

  string name;
  vector<Field> fields;
  vector<Android> androids;

} Farm;

// ---------------- error -------------------------
enum Error {
  ERR_NO_FIELDS, 
  ERR_UNKNOWN_OPTION,
  ERR_WRONG_MODEL,
  ERR_WRONG_FIELD,
  ERR_WRONG_SPEED, 
  ERR_WRONG_PRODUCTS,
  ERR_NAME,
  ERR_OPEN_FILE,
  ERR_ARGS
};

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

    case ERR_OPEN_FILE:
      cout << "Error, can't open file" << endl;
      break;
    
    case ERR_ARGS:
      cout << "Error, wrong arguments" << endl
           << "Usage: uncleOwen [-f fieldName] [-a androidsFile] [-p productsFile]" << endl;
      break;
  }
}

//---------------------------------------------------------------
const string HEADER1="---- start ----";
const string HEADER2="---- distribution ----";
const string HEADER3="---- end ----";
const string HOUR="Hour: ";
const string SEPARATOR="===============================================";
//---------------------------------------------------------------
const string FILENAME="Enter filename: ";
const string ENTERANDS="Enter android speed: ";
const string ENTERANDM="Enter android model: ";
const string ENTERFIELD="Enter field name: ";
const string STARTWH="Products: ";

//clear buffer
void clearBf(){

  while (cin.get() != '\n');
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

// comprobate that there are more than 0 products to recollect
bool dif0(const Farm &farm){

  bool result=false;

  for(size_t i=0;i<farm.fields.size();i++){
    if(farm.fields[i].products!=0)
      result=true;
  }
  return(result);
}

// validate model of Android
bool validModel(string model){

  bool result=false;

  for(int i=0;i<NUMDROIDMODELS;i++){
    if(model==ANDROIDDATA[i].modelName)
      result=true;
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

// validate that number > 0
bool validHigherThan0(int quantity){

  bool result=true;

  if(quantity<=0)
    result=false;

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


void printAndroid(const Android &a){

  cout << "[" << a.model << " sn=" << a.serialNumber << " s=" << a.speed << " hw=" << a.hoursWorked << " st=" << a.status << "]" << endl;
}


void printField(const Field &f){
  
  cout << "{Field: " << f.name << "(" << f.products << " " << f.hoursLeft << ")" << endl;

    for(size_t i=0;i<f.androids.size();i++){
      cout << "  ";
      printAndroid(f.androids[i]);
    }

    cout << "}" << endl; 
}


void printFarm(const Farm &f){
  
  cout << "Farm: " << f.name << endl;
  
  for(size_t i=0;i<f.fields.size();i++)
    printField(f.fields[i]);

  for(size_t i=0;i<f.androids.size();i++)
    printAndroid(f.androids[i]);
}

// creates a new field in the farm with the name provided by the user
void createField(Farm &farm){

  Field f;
  string fname="";

  cout << ENTERFIELD;
    getline(cin,fname);
    
  if(equalityFarmName(fname,farm)){
    f.name=fname;
    f.hoursLeft=DAILY_WORKING_HOURS;
    f.products=0;
    farm.fields.push_back(f);
  }
  else
    error(ERR_NAME);
}

void createAndroid2(Farm &farm, int vel, string model, int &nextSerialNumber,bool switcha){
	Android a;
    if(validHigherThan0(vel)){
    	if(switcha){
    		clearBf();
    		cout << ENTERANDM;
    		getline(cin,model);
		}
		if(validModel(model)){
		a.model=model;                              //      After the necesary comprobations
        a.speed=vel;                               //           create the variable a
        a.hoursWorked=0;                          //                  with all
        a.serialNumber=nextSerialNumber;
        a.status=ST_IDLE;        
        farm.androids.push_back(a);                  //Introduce the android to the farm.androids vector
        nextSerialNumber++;
        }
        else
        	error(ERR_WRONG_MODEL);
    }
    else
    	error(ERR_WRONG_SPEED);
}

// Creates a new android asking the data to the user given nextSerialNumber, and
// adds the android to the farm
void createAndroid(Farm &farm, int &nextSerialNumber){

  Android a;
  string model="";
  int velocity;
  
  cout << ENTERANDS;
    cin>>velocity;

  createAndroid2(farm,velocity,model,nextSerialNumber,true);    
}

//distribute the androids
void distribution(Farm &farm, int position){

  int maxsp=0;
  Android android;
  int pos;
  bool control=false;

  for(size_t i=0;i<farm.androids.size();i++){                                             //
        if(farm.androids[i].speed>maxsp && farm.androids[i].status==ST_IDLE){            //  Search the fastest android with it state IDLE
          maxsp=farm.androids[i].speed;                                                 //
          pos=i;
        }
  }

  if(maxsp>0){
  android.model=farm.androids[pos].model; android.speed=farm.androids[pos].speed;
  android.serialNumber=farm.androids[pos].serialNumber; android.hoursWorked=farm.androids[pos].hoursWorked;
  android.status=ST_WORKING;
  control=true;
  }
  if(control){
  farm.fields[position].androids.push_back(android);
  farm.androids.erase(farm.androids.begin()+pos);
  }
} 

void prueba(const Farm &farm, int position){

  for(size_t i=0;i<farm.androids.size();i++){                                             
        if(farm.androids[i].status==ST_MAINTENANCE0)
          cout << "EL androide " << farm.androids[i].model << "tiene que estar en mantenimiento por que su estado es " << farm.androids[i].status << "." << endl;
  } 
}

// fields not equal 0
void fieldsW0P(vector<int> &v,const Farm &farm){
  
  for(size_t i=0;i<farm.fields.size();i++){
    if(farm.fields[i].products!=0)
      v.push_back(i);
  }
}
 
// pACO
void antoniomanolo(vector <int> &v,const Farm &f){
  vector<int> garbage;

  for(size_t i=0;i<v.size();i++){
    if(f.fields[v[i]].androids.size()>0){
      int androidspeedplus=0;
      for(size_t j=0;j<f.fields[v[i]].androids.size();j++)
        androidspeedplus += f.fields[v[i]].androids[j].speed;
      if(androidspeedplus>=f.fields[v[i]].products)
        garbage.push_back(i);
    }
  }
  for(size_t i=0;i<garbage.size();i++)
    v.erase(v.begin()+garbage[i]);
}

 // Comprobamos si necesita mas androides o funciona perfecto con los que ya tiene metidos loco
bool fieldOk(vector<int> &v,const Field &f,int pos){
  
  bool result=false;
  int numand=f.androids.size();
  int androidspeedplus=0;

  if(numand>0){
    for(int i=0;i<numand;i++)
      androidspeedplus += f.androids[i].speed;
    if(androidspeedplus>=f.products){
      result=true;
      v.erase(v.begin()+pos);
    }
  }
  return(result);
}

int minandr(vector<int> v, const Farm &f){
  //int result;
 int min=INT_MAX;

  for(size_t i=0;i<v.size();i++){
    int tam=f.fields[v[i]].androids.size();
    if(tam<min)
      min=f.fields[v[i]].androids.size();
  }
  return(min);
}

//
bool quedanAndroidesQuePuedanTrabajar(const Farm &farm){
  bool result=true;
  int cont=0;
  for(size_t i=0;i<farm.androids.size();i++){
    if(farm.androids[i].status==ST_IDLE)
      cont++;
  }
  if(cont==0){
    result=false;
  }
  return(result);
}

// distributes the farm's androids among its fields
void distributeAndroids(Farm &farm){
  vector<int> v;                                            //Vector fields > 0
  vector<int> iguales;                                      //Vector with the same androids size
  int min=INT_MAX;

  fieldsW0P(v,farm);                                        //Fill vector with fields with his products are different 0
  
  if(dif0(farm)){                                           //Check that there are at least one field with products else exit
    while(farm.androids.size()>0 && v.size()>0 && 
      quedanAndroidesQuePuedanTrabajar(farm)){
      int max=0;
      min=minandr(v,farm);
      int pos,tamanyo;
      antoniomanolo(v,farm);                                // Comprobamos si los androides están agustico en el campo o no
      for(size_t i=0;i<v.size();i++){
        tamanyo=farm.fields[v[i]].androids.size();          
        if(tamanyo<min)                                     //    Search if there are fields with the same 
          min=tamanyo;                                      //    number of androids and set the min number 
        if(tamanyo==min)                                    //                 of androids size
          iguales.push_back(v[i]);                          //Fill iguales vector with the position of the fields that have the same androids size
      }
      if(iguales.size()>0){                                 //If there aren't androids with min size set the min++ to continue
        for(size_t i=0;i<iguales.size();i++){
          if(farm.fields[iguales[i]].products>max){         //      Search the max products in the fields iguales to min
            max=farm.fields[iguales[i]].products;           //                 set max and pos to use after
            pos=iguales[i];
          }
        }
        iguales.clear();                                    //Clear the iguales vector to start over
        //prueba(farm,pos);
        distribution(farm,pos);
      }
      else
        min++;
      }
  }
}
 //Rescata del array tipo ANDROIDDATA las horas que puede trabajar sin cansarse el androide que le pasamos
int hoursAvailableForThisAndroid(Android a){
  int hoursAvailable;
  for(int i=0;i<NUMDROIDMODELS;i++){
    if(a.model==ANDROIDDATA[i].modelName)
      hoursAvailable=ANDROIDDATA[i].hoursMaintenance;
  }

  return(hoursAvailable);
}

//Vacia androides a 2 de los campos
void vaciaMantenimiento(Field &f){
  unsigned int i=0;
  while(i<f.androids.size()){
    if(f.androids[i].status==ST_MAINTENANCE0)
      f.androids.erase(f.androids.begin()+i);
    else
      i++;
  }
}

vector<Android> collectField(Field &f){
  vector<Android> va;
  Android a;
  int vel=0;

  //if(f.androids.size()>0){
    for(size_t i=0;i<f.androids.size();i++){
      vel += f.androids[i].speed;
      f.androids[i].hoursWorked++;
      if(f.androids[i].hoursWorked==hoursAvailableForThisAndroid(f.androids[i])){
        f.androids[i].status=ST_MAINTENANCE0;
        va.push_back(f.androids[i]);
        // me jode la vida entera f.androids.erase(f.androids.begin()+i);
      }
    }
    vaciaMantenimiento(f);

    f.products=f.products-vel;
    if(f.products<0)f.products=0;
    if(f.hoursLeft>0)f.hoursLeft--;
    if(f.products==0 || f.hoursLeft==0){
      for(size_t i=0;i<f.androids.size();i++){
        f.androids[i].status=ST_IDLE;
        va.push_back(f.androids[i]);
      }
      f.androids.clear();  //Ah pos no con esto sobraba xdd
      // POR ESTA PUTISIMA MIERDA VOY A TENER QUE HACER OTRO MODULOf.androids.erase(f.androids.begin()+i); //THERE IS THE PROBLEM MY FREI
      f.hoursLeft=DAILY_WORKING_HOURS;
    }
  //}
    return(va);
}

void maintenance(Farm &f){
  for(size_t i=0;i<f.androids.size();i++){
  	if(f.androids[i].status==ST_MAINTENANCE1){
  		f.androids[i].status=ST_IDLE;
  		f.androids[i].hoursWorked=0;
  	}
    if(f.androids[i].status==ST_MAINTENANCE0)
    	f.androids[i].status=ST_MAINTENANCE1;
  }
}

void vaciagranja(Farm &farm){
	for(size_t i=0;i<farm.fields.size();i++)
		farm.fields[i].androids.clear();
  farm.fields.clear();
  farm.androids.clear();
}

void collectFarm(Farm &farm,int &hour){
  vector<Android> andr;
  cout << SEPARATOR << endl;
  cout << "Hour: " << hour << endl;
  cout << HEADER1 << endl;
  printFarm(farm);
  cout << HEADER2 << endl;
  distributeAndroids(farm);
  printFarm(farm);
  cout << HEADER3 << endl;
  for(size_t i=0;i<farm.fields.size();i++){
    andr=collectField(farm.fields[i]);
    for(size_t j=0;j<andr.size();j++)
      farm.androids.push_back(andr[j]);
    andr.clear();
  }
  if(hour==1){

  }
  printFarm(farm);
  if(hour==10)
    maintenance(farm);
  //ponera3silahoraes10
  if(hour<DAILY_WORKING_HOURS)
    hour++;
  else
    hour=1;
}

void processProducts(Farm &f,string products){
  string nombrec="";
  string numerop="";

  for(size_t i=0;i<products.size();i++){
    if(products[i]==':'){                                      //Find after : the products to recollect
      while(products[i]!='"' && i<products.size()){
        if(products[i]>47 && products[i]<58)
          numerop=numerop+products[i];
        i++;
      }
      int product=atoi(numerop.c_str());
      if(!equalityFarmName(nombrec,f)){
         if(product==0)
           error(ERR_WRONG_PRODUCTS);
        f.fields[positionOfField(nombrec,f)].products += product;
      }
      else
        error(ERR_WRONG_FIELD);
      numerop="";
    }
    if(products[i]=='"'){
      nombrec="";
      i++;
      while(products[i]!='"'){
        nombrec=nombrec+products[i];
        i++;
      }
    }
  }
}

void startWorkingHour(Farm &f,int &hour){

  if(hour==1){
  if(atLeastOne(f)){  //Check that there are more than 1 field in the farm vector
    string option="";
    //int products=0;
    cout << STARTWH;
        getline(cin,option);
        cin.clear();
        processProducts(f,option);
     }
     else
      error(ERR_NO_FIELDS);
   }
    collectFarm(f,hour);
}

//--------------------------------------------------------

const int MAXNAME=10;

typedef struct {
  char model[MAXNAME];
   int speed;
   int serialNumber;
   Status status;
   int hoursWorked;
} AndroidBin;

typedef struct {
  char name[MAXNAME];
  unsigned int products;
  int hoursLeft;
  unsigned int numAndroids;
} FieldBin;

typedef struct {
  char name[MAXNAME];
  int nextSerialNumber;
  int hour;
  unsigned int numFields;
} FarmBin;

//Converts string to char
void fjk(char c[],string s){
	for(int j=0;j<MAXNAME-1;j++)
		c[j]=s[j];
	c[MAXNAME-1]='\0';                                                     //REVISAR
}

// asks for the filename, then opens the file and writes farm data. If the
// file can't be opened returns false, otherwise returns true
bool writeFarmData(const Farm &farm,int nextSerialNumber,int hour){
  bool result=true;
  FarmBin fa;AndroidBin al;FieldBin fl;
  cout << FILENAME;
  string filename;
  cin>>filename;cin.clear();
  
  //if(filename=="")error(ERR_OPEN_FILE);
  ofstream fichesc(filename.c_str(),ios::binary);
  
  if(fichesc.is_open()){
  	fjk(fa.name,farm.name);        fa.nextSerialNumber=nextSerialNumber;
    fa.hour=hour;              fa.numFields=farm.fields.size();
  	fichesc.write((char *)&fa,sizeof(FarmBin));
  	for(size_t i=0;i<farm.fields.size();i++){
  		fjk(fl.name,farm.fields[i].name);        fl.products=farm.fields[i].products;
        fl.hoursLeft=farm.fields[i].hoursLeft;   fl.numAndroids=farm.fields[i].androids.size();
        fichesc.write((char *)&fl,sizeof(FieldBin));
        for(size_t j=0;j<farm.fields[i].androids.size();j++){
        	fjk(al.model,farm.fields[i].androids[j].model);               al.speed=farm.fields[i].androids[j].speed;
            al.serialNumber=farm.fields[i].androids[j].serialNumber;  al.status=farm.fields[i].androids[j].status;
            al.hoursWorked=farm.fields[i].androids[j].hoursWorked;
            fichesc.write((char *)&al,sizeof(AndroidBin));
        }
    }
    for(size_t i=0;i<farm.androids.size();i++){
      	fjk(al.model,farm.androids[i].model);               al.speed=farm.androids[i].speed;
        al.serialNumber=farm.androids[i].serialNumber;  al.status=farm.androids[i].status;
        al.hoursWorked=farm.androids[i].hoursWorked;
        fichesc.write((char *)&al,sizeof(AndroidBin));
    }
  }
  fichesc.close();
  return(result);
}

// asks for the filename, then opens the file and reads farm data. If the
// file can't be opened returns false, otherwise returns true

                                                                   ////////////////////////CUIDAO LOCO LO DE BORRAR TOA LA GRANJA PEPE
bool readFarmData(Farm &farm, int &nextSerialNumber,int &hour){
  bool result=true;
          FarmBin    fl;
  AndroidBin al;   Android ac;
  FieldBin   fil;  Field   fc;
  string paco;
  cout << FILENAME;
  cin>>paco;cin.clear();
  ifstream fichleer;
  fichleer.open(paco.c_str(),ios::in|ios::binary);
  if(fichleer.is_open()){
  	vaciagranja(farm);
      fichleer.read((char *)&fl,sizeof(FarmBin));
      //cout << farm.name << endl; //////////////////////////////////////////////////////CUIDADO
      nextSerialNumber=fl.nextSerialNumber;
      hour=fl.hour;
      for(size_t i=0;i<fl.numFields;i++){
        fichleer.read((char *)&fil,sizeof(FieldBin));
        fc.name=fil.name;
        fc.products=fil.products;
        fc.hoursLeft=fil.hoursLeft;
        farm.fields.push_back(fc);
        for(size_t j=0;j<fil.numAndroids;j++){
          fichleer.read((char *)&al,sizeof(AndroidBin));
          ac.model=al.model;
          ac.speed=al.speed;
          ac.serialNumber=al.serialNumber;
          ac.status=al.status;
          ac.hoursWorked=al.hoursWorked;
          farm.fields[i].androids.push_back(ac);
        }

    }
    while(fichleer.read((char *)&al,sizeof(AndroidBin))){
      ac.model=al.model;  ac.speed=al.speed;
      ac.serialNumber=al.serialNumber;
      ac.status=al.status; ac.hoursWorked=al.hoursWorked;
      farm.androids.push_back(ac);
    }
    fichleer.close();
  }
  else{
   error(ERR_OPEN_FILE);
   result=false;
  }
  return(result);
}

int pepepaco(string filename){
  ifstream arch(filename.c_str(), ifstream::in);
  int lin=0;
  string s;
  if(arch.is_open()){
     while(arch.good()) if(arch.get()=='\n') lin++;
  }
  arch.close();
  return(lin);                                                       //REVISAR                                                     //REVISAR
}

void quitaespacios(string &s){
	unsigned int cont=0;
	bool encletra=false;
	while(cont<s.size()){
		if(s[cont]!=' ')
			encletra=true;
		if(s[cont]==' ' && !encletra)
		  s.erase(s.begin()+0);
		else
		  cont++;
	}                                                         //para import androids                                                    //REVISAR
}

// asks for the filename, then opens the file and reads android data. If the
// file can't be opened returns false, otherwise returns true
bool importAndroids(Farm &farm,int &nextSerialNumber){

 bool result=true;
 string filename;
 cout << FILENAME;
 getline(cin,filename);cin.clear();
 ifstream pato(filename.c_str(),ifstream::in);
 int e;
 Android a;
 string s;
 int filas;
 filas=pepepaco(filename);
 if(pato.is_open()){
 	while(filas>0){
 		pato>>e;
 		getline(pato,s);
 		quitaespacios(s);
 		a.speed=e;  a.model=s;
 	    createAndroid2(farm,e,s,nextSerialNumber,false);
 		filas--;
 	}	
 }
 else{
 	error(ERR_OPEN_FILE);
 	result=false;
 }
 	
 pato.close();
  return(result);                                      //REVISAR
}

// asks for the filename, then opens the file and reads product data. If the
// file can't be opened returns false, otherwise returns true
bool importProducts(Farm &farm){
	bool result=true;
	Field f;
	int filas;
	string field,filename;
	cout << FILENAME;
	getline(cin,filename);cin.clear();
	ifstream fields(filename.c_str(),ifstream::in);
	filas=pepepaco(filename);
	if(fields.is_open()){
		while(filas>0){
			getline(fields,field);
			processProducts(farm,field);
			filas--;
		}
	}
	else{
		error(ERR_OPEN_FILE);
		result=false;
	}
	fields.close();
	return(result);                                                              //REVISAR
}

//------------------------------------------------------
void menu(int hour){
  cout << "-----========== Farm manager ==========-----" << endl
       << "1- List farm info" << endl
       << "2- Add field" << endl
       << "3- Add android" << endl
       << "4- Start working hour (" << hour << ")" << endl
       << "5- Write farm data" << endl
       << "6- Read farm data" << endl
       << "7- Import androids" << endl
       << "8- Import products" << endl
       << "q- Quit" << endl
       << "Option: " ;
}

bool parimpar(int number){                     // PAR TRUE IMPAR FALSE
	bool result=false;
	if(number%2==0){
		result=true;
	}
	return(result);
}

bool compruebaArgumentos(vector<string> &v){
	bool result=true;
	int conta=0,contp=0,contf=0;
	for(size_t i=0;i<v.size();i++){
		if(v[i]!="-a" && v[i]!="-f" && v[i]!="-p")
			result=false;
		if(v[i]=="-a") conta++;
		if(v[i]=="-f") contf++;
		if(v[i]=="-p") contp++;
	}
	if(conta>1||contp>1)
		result=false;
	return(result);
}

bool importAndroids2(string filename,Farm &farm,int &nextSerialNumber){
	bool result=true;
	 ifstream andr(filename.c_str(),ifstream::in);
	 int e;
	 Android a;
	 string s;
	 int filas;
	 filas=pepepaco(filename);
	 if(andr.is_open()){
	 	while(filas>0){
	 		andr>>e;
	 		getline(andr,s);
	 		quitaespacios(s);
	 		a.speed=e;  a.model=s;
	 	    createAndroid2(farm,e,s,nextSerialNumber,false);
	 		filas--;
	 	}	
	 }
	 else{
	 	error(ERR_OPEN_FILE);
	 	result=false;
	 }
	 	
	 andr.close();
	  return(result);                                      //REVISAR
}

bool importProducts2(string filename,Farm &farm){
	bool result=true;
	Field f;
	int filas;
	string field;
	ifstream fields(filename.c_str(),ifstream::in);
	filas=pepepaco(filename);
	if(fields.is_open()){
		while(filas>0){
			getline(fields,field);
			processProducts(farm,field);
			filas--;
		}
	}
	else{
		error(ERR_OPEN_FILE);
		result=false;
	}
	fields.close();
	return(result);                                                              //REVISAR
}

void createFields(Farm &farm, string field){
	Field f;
	if(equalityFarmName(field,farm)){
    f.name=field;
    f.hoursLeft=DAILY_WORKING_HOURS;
    f.products=0;
    farm.fields.push_back(f);
  }
  else
    error(ERR_NAME);
}

bool processArguments(int argc,char *argv[],Farm &farm,int &nextSerialNumber){
	bool result=false;
	string x;
	vector<string> vi,vp,fiel;
	if(argc==1)
		result=true;
	else{
		for(int i=1;i<argc;i++){
			x=argv[i];
			if(parimpar(i))
				vp.push_back(x);
		    else
		    	vi.push_back(x);
	    }
	}
	if(!compruebaArgumentos(vi))
		error(ERR_ARGS);
	else{
		if(vp.size()!=vi.size())
			error(ERR_ARGS);
		else{
			result=true;
			for(size_t i=0;i<vi.size();i++){
				if(vi[i]=="-f")
					fiel.push_back(vp[i]);
			}
			for(size_t j=0;j<fiel.size();j++)
				createFields(farm,fiel[j]);

			for(size_t i=0;i<vi.size();i++){
				if(vi[i]=="-a")
					importAndroids2(vp[i],farm,nextSerialNumber);
				if(vi[i]=="-p")
					importProducts2(vp[i],farm);
			}
		}
	}
	return(result);
}


int main(int argc,char *argv[]){
   Farm farm;
   farm.name = "west farm";
   char option;
   int nextSerialNumber = 100;
   int hour=1;

   if (processArguments(argc,argv,farm,nextSerialNumber))
     do {
        menu(hour);
        cin >> option; cin.get();
        
        switch (option) {
          case '1':printFarm(farm);
            break;
          case '2':createField(farm);
            break;
          case '3':createAndroid(farm,nextSerialNumber);
            break;
          case '4':startWorkingHour(farm,hour);
            break;
          case '5':writeFarmData(farm,nextSerialNumber,hour);
            break;
          case '6':readFarmData(farm,nextSerialNumber,hour);
            break;
          case '7':importAndroids(farm,nextSerialNumber);
            break;
          case '8':importProducts(farm);
            break;
          case 'q':
            break;
          default: error(ERR_UNKNOWN_OPTION);
            break;
        }
     } while (option != 'q');
     
   return 0;
}

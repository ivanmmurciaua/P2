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

// clear buffer
void clearBf(){

	while (cin.get() != '\n');
}

// validate the repetition of a field name
bool equalityFarmName(string fname, const Farm &farm){
	bool result=true;
  
    for(size_t i=0;i<farm.fields.size();i++){
      if(fname==farm.fields[i].name)
        result=false;
    }
    return(result);
}

// check that there are more than 0 products to collect
bool dif0(const Farm &farm){
	bool result=false;

	for(size_t i=0;i<farm.fields.size();i++){
	    if(farm.fields[i].products!=0)
	      result=true;
	}
	return(result);
}

// validate the android model
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

// validate that the number is greater than 0
bool validHigherThan0(int quantity){
	bool result=true;

  	if(quantity<=0)
      result=false;
	return(result);
}

// position of the field chosen to add products to it
int positionOfField(string farmname, const Farm &farm){
  int result=0;

  for(size_t i=0;i<farm.fields.size();i++){
    if(farmname==farm.fields[i].name)
      result=i;
  }
  return(result);
}

// prints android info
void printAndroid(const Android &a){

  cout << "[" << a.model << " sn=" << a.serialNumber << " s=" << a.speed << " hw=" << a.hoursWorked << " st=" << a.status << "]" << endl;
}

// prints field info
void printField(const Field &f){
  
  cout << "{Field: " << f.name << "(" << f.products << " " << f.hoursLeft << ")" << endl;

    for(size_t i=0;i<f.androids.size();i++){
      cout << "  ";
      printAndroid(f.androids[i]);
    }

    cout << "}" << endl; 
}

// prints farm info
void printFarm(const Farm &f){
  
  cout << "Farm: " << f.name << endl;
  
  for(size_t i=0;i<f.fields.size();i++)
    printField(f.fields[i]);

  for(size_t i=0;i<f.androids.size();i++)
    printAndroid(f.androids[i]);
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

// creates a new field in the farm with the name provided by the user
void createField(Farm &farm){

  Field f;
  string fname="";

  cout << ENTERFIELD;
    getline(cin,fname);
    
  createFields(farm,fname);
}

// complement of createAndroid and importAndroids
void createAndroid2(Farm &farm, int vel, string model, int &nextSerialNumber,bool switcha){
	Android a;
    if(validHigherThan0(vel)){
    	if(switcha){                                      //  bool to enter if the call has occurred from createAndroid
    		clearBf();
    		cout << ENTERANDM;
    		getline(cin,model);
		}
		if(validModel(model)){
		a.model=model;                                  //      after the necesary comprobations
        a.speed=vel;                               //           create the variable a
        a.hoursWorked=0;                          //                  with all
        a.serialNumber=nextSerialNumber;
        a.status=ST_IDLE;        
        farm.androids.push_back(a);             //          introduce the android to the farm.androids vector
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

// choose the fastest android and check that it state be equal to ST_IDLE and put it to work
void distribution(Farm &farm, int position){

  int maxsp=0;
  Android android;
  int pos;
  bool control=false;

  for(size_t i=0;i<farm.androids.size();i++){                                             //
        if(farm.androids[i].speed>maxsp && farm.androids[i].status==ST_IDLE){            //  search the fastest android with it state IDLE
          maxsp=farm.androids[i].speed;                                                 //
          pos=i;
        }
  }

  if(maxsp>0){
    android.model=farm.androids[pos].model; android.speed=farm.androids[pos].speed;                              //    fill the android variable with the
    android.serialNumber=farm.androids[pos].serialNumber; android.hoursWorked=farm.androids[pos].hoursWorked;   //             date of the chosen 
    android.status=ST_WORKING;                                                                                 //                   android
    control=true;                                                                                             
  }                                                                                                        
  if(control){                                                                                              //
    farm.fields[position].androids.push_back(android);                                                     //         introduce the android to work   
    farm.androids.erase(farm.androids.begin()+pos);                                                       //         delete in the farm.androids vector           
  }
} 

// fill the v vector with fields that it products are not equal to 0
void fieldsW0P(vector<int> &v,const Farm &farm){
  
  for(size_t i=0;i<farm.fields.size();i++){
    if(farm.fields[i].products!=0)
      v.push_back(i);
  }
}
 
// check if the chosen field needs more androids or works perfectly with those who have
void fieldOk(vector <int> &v,const Farm &f){
  vector<int> garbage;                                                  //vector to fill with fields that are OK

  for(size_t i=0;i<v.size();i++){
    if(f.fields[v[i]].androids.size()>0){
      int androidspeedplus=0;
      for(size_t j=0;j<f.fields[v[i]].androids.size();j++)
        androidspeedplus += f.fields[v[i]].androids[j].speed;       //    put in the androidspeedplus variable the sum of all the androids that are working in it
      if(androidspeedplus>=f.fields[v[i]].products)                //     if the sum stored in androidspeedplus is higher or equal to the products
        garbage.push_back(i);                                     //      puts these field into garbage vector
    }
  }
  for(size_t i=0;i<garbage.size();i++)
    v.erase(v.begin()+garbage[i]);                              //        erase from the v vector the fields that are OK according to the fields in garbage vector
}

// returns the min of androids in some field to use after
int minAndr(vector<int> v, const Farm &f){
 int min=INT_MAX;

  for(size_t i=0;i<v.size();i++){
    int tam=f.fields[v[i]].androids.size();
    if(tam<min)
      min=f.fields[v[i]].androids.size();
  }
  return(min);
}

// return true if there are androids who can work
bool androidsWhoCanWork(const Farm &farm){
  bool result=true;
  int cont=0;
  for(size_t i=0;i<farm.androids.size();i++){
    if(farm.androids[i].status==ST_IDLE)
      cont++;
  }
  if(cont==0)
    result=false;
  return(result);
}

// distributes the farm's androids among its fields
void distributeAndroids(Farm &farm){
  vector<int> v,iguales;                                                            //vector fields > 0 and vector with the same androids size
  int min=INT_MAX;
  fieldsW0P(v,farm);                                                              //fill vector with fields with his products are different 0
  if(dif0(farm)){                                                                //check that there are at least one field with products else exit
    while(farm.androids.size()>0 && v.size()>0 && androidsWhoCanWork(farm)){
      int max=0,pos,tamanyo;
      min=minAndr(v,farm);
      fieldOk(v,farm);                                               // check if the androids are ok in the field or need more
      for(size_t i=0;i<v.size();i++){                               //
        tamanyo=farm.fields[v[i]].androids.size();                 //
        if(tamanyo<min)min=tamanyo;                               //    search if there are fields with the same number of androids and set the min number
        if(tamanyo==min)iguales.push_back(v[i]);                 // of androids size and fill iguales vector with the position of the fields that have the same androids size
      }
      if(iguales.size()>0){                                    //    if there aren't androids with min size set the min++ to continue
        for(size_t i=0;i<iguales.size();i++){
          if(farm.fields[iguales[i]].products>max){          //      search the max products in the fields iguales to min
            max=farm.fields[iguales[i]].products;           //                 set max and pos to use after
            pos=iguales[i];
          }
        }
        iguales.clear();distribution(farm,pos);          //clear the iguales vector to start over
      }
      else
        min++;
      }
  }
}
 // rescue form the array ANDROIDDATA the hours it can work without getting tired
int hoursAvailableForThisAndroid(Android a){
  int hoursAvailable;
  for(int i=0;i<NUMDROIDMODELS;i++){
    if(a.model==ANDROIDDATA[i].modelName)
      hoursAvailable=ANDROIDDATA[i].hoursMaintenance;
  }

  return(hoursAvailable);
}

// clear from the field the androids with status ST_MAINTENANCE0
void cleanMaintenance(Field &f){
  unsigned int i=0;
  while(i<f.androids.size()){
    if(f.androids[i].status==ST_MAINTENANCE0)
      f.androids.erase(f.androids.begin()+i);
    else
      i++;
  }
}

// collects the field
vector<Android> collectField(Field &f){
  vector<Android> va;
  Android a;
  int vel=0;

    for(size_t i=0;i<f.androids.size();i++){
      vel += f.androids[i].speed;                                                                 //total of speed of the androids in the field    
      f.androids[i].hoursWorked++;                                                               //increment hoursWorked
      if(f.androids[i].hoursWorked==hoursAvailableForThisAndroid(f.androids[i])){               //if the hours worked is equal to the hours available
        f.androids[i].status=ST_MAINTENANCE0;                                                  //put it status to ST_MAINTENANCE0
        va.push_back(f.androids[i]);                                                          //put into vector of androids to return
      }
    }
    cleanMaintenance(f);                                                                   //clear from the field the androids with status 2
    f.products=f.products-vel;                                                            // update field products
    if(f.products<0)f.products=0;                                                        //
    if(f.hoursLeft>0)f.hoursLeft--;                                                     //   other comprobations 
    if(f.products==0 || f.hoursLeft==0){                                               //    if products == 0 or hoursleft 0    
      for(size_t i=0;i<f.androids.size();i++){                                        //      
        f.androids[i].status=ST_IDLE;                                                //      put it status to IDLE
        va.push_back(f.androids[i]);                                                //
      }                                                                            //
      f.androids.clear();                                                         //         clear the vector
      f.hoursLeft=DAILY_WORKING_HOURS;                                           //          restart the hoursleft
    }
    return(va);
}

// check the androids who need maintenance
void maintenanceA(Farm &f){
  for(size_t i=0;i<f.androids.size();i++){
  	if(f.androids[i].status==ST_MAINTENANCE1){
  		f.androids[i].status=ST_IDLE;
  		f.androids[i].hoursWorked=0;
  	}
    if(f.androids[i].status==ST_MAINTENANCE0)
    	f.androids[i].status=ST_MAINTENANCE1;
  }
}

// clear the farm
void clearFarm(Farm &farm){
	for(size_t i=0;i<farm.fields.size();i++)
		farm.fields[i].androids.clear();
  farm.fields.clear();
  farm.androids.clear();
}

// collects the farm
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
    andr=collectField(farm.fields[i]);                                                 //put into another vector the vector returned from collectfarm
    for(size_t j=0;j<andr.size();j++)
      farm.androids.push_back(andr[j]);                                              //fill farm.androids vector with the androids recollected
    andr.clear();                                                                   //clear auxiliar vector
  }
  printFarm(farm);
  if(hour==10)
    maintenanceA(farm);                                                         //    execute maintenanceA to put if the hour == 10 the androids to the
  if(hour<DAILY_WORKING_HOURS)                                                 //     correspondient state
    hour++;                                                                   //      working day ++ normally
  else                                                                       //
    hour=1;                                                                 //        restart the working day
}

void processProducts(Farm &f,string products){
  string nombrec="";
  string numerop="";

  for(size_t i=0;i<products.size();i++){
    if(products[i]==':'){                                                                   //find after : the products to recollect
      while(products[i]!='"' && i<products.size()){
        if(products[i]>47 && products[i]<58)                   
          numerop=numerop+products[i];                                                    //extracts the number of products
        i++;
      }
      int product=atoi(numerop.c_str());                                               //transform the number to int
      if(!equalityFarmName(nombrec,f)){                                               //check if the name of the field is correct and add the products
         if(product==0)
           error(ERR_WRONG_PRODUCTS);
        f.fields[positionOfField(nombrec,f)].products += product;                  //add the products
      }
      else
        error(ERR_WRONG_FIELD);
      numerop="";
    }
    if(products[i]=='"'){
      nombrec="";
      i++;
      while(products[i]!='"'){
        nombrec=nombrec+products[i];                                     //extracts the name of the field after "
        i++;
      }
    }
  }
}

void startWorkingHour(Farm &f,int &hour){

  if(hour==1){
  if(atLeastOne(f)){                                                //check that there are more than 1 field in the farm vector
    string option="";
    cout << STARTWH;
        getline(cin,option);
        cin.clear();
        processProducts(f,option);                              //process the string
     }
     else
      error(ERR_NO_FIELDS);
   }
    collectFarm(f,hour);                                    //collect the farm
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

// converts string to char
void stringToChar(char c[],string s){
	for(int j=0;j<MAXNAME-1;j++)
		c[j]=s[j];
	c[MAXNAME-1]='\0';
}

// asks for the filename, then opens the file and writes farm data. If the
// file can't be opened returns false, otherwise returns true
bool writeFarmData(const Farm &farm,int nextSerialNumber,int hour){
  bool result=true;
  FarmBin fa;AndroidBin al;FieldBin fl;                                                                               //declare of bin variables
  cout << FILENAME;
  string filename;
  getline(cin,filename);cin.clear();                                                                                //obtain the filename from the user
  
  if(filename=="")error(ERR_OPEN_FILE);                                                                            //extra comprobation
  ofstream fichesc(filename.c_str(),ios::binary);                                                                 //declaration to write a binary file
  if(fichesc.is_open()){                                                                                         //open the file
  	stringToChar(fa.name,farm.name);   fa.nextSerialNumber=nextSerialNumber;                                    //
    fa.hour=hour;                      fa.numFields=farm.fields.size();                                        //write farm
  	fichesc.write((char *)&fa,sizeof(FarmBin));                                                               //
  	for(size_t i=0;i<farm.fields.size();i++){
  		stringToChar(fl.name,farm.fields[i].name);   fl.products=farm.fields[i].products;                                     //
        fl.hoursLeft=farm.fields[i].hoursLeft;       fl.numAndroids=farm.fields[i].androids.size();                        //write field
        fichesc.write((char *)&fl,sizeof(FieldBin));                                                                      //
        for(size_t j=0;j<farm.fields[i].androids.size();j++){
        	stringToChar(al.model,farm.fields[i].androids[j].model);   al.speed=farm.fields[i].androids[j].speed;               //
            al.serialNumber=farm.fields[i].androids[j].serialNumber;   al.status=farm.fields[i].androids[j].status;          //write 
            al.hoursWorked=farm.fields[i].androids[j].hoursWorked;                                                          //   androids
            fichesc.write((char *)&al,sizeof(AndroidBin));                                                                 //
        }
    }
    for(size_t i=0;i<farm.androids.size();i++){
      	stringToChar(al.model,farm.androids[i].model);  al.speed=farm.androids[i].speed;                               //
        al.serialNumber=farm.androids[i].serialNumber;  al.status=farm.androids[i].status;                            //write
        al.hoursWorked=farm.androids[i].hoursWorked;                                                                 //   androids
        fichesc.write((char *)&al,sizeof(AndroidBin));                                                              //
    }
    fichesc.close();                                                                                               //close file
  }
  else{
  	error(ERR_OPEN_FILE);result=false;
  }
  return(result);
}

// asks for the filename, then opens the file and reads farm data. If the
// file can't be opened returns false, otherwise returns true
bool readFarmData(Farm &farm, int &nextSerialNumber,int &hour){
  bool result=true;
          FarmBin    fl;                                                                                  //
  AndroidBin al;   Android ac;                                                                           // declaration of variables
  FieldBin   fil;  Field   fc;                                                                          //
  string filename;
  cout << FILENAME;
  getline(cin,filename);cin.clear();                                                                 //obtain the filename from the user
  ifstream fichleer;                                                                                //declaration to
  fichleer.open(filename.c_str(),ios::in|ios::binary);                                             //read a binary file
  if(fichleer.is_open()){                                                                         //open the file
  	clearFarm(farm);                                                                             //clear the farm to introduce the new valors
    fichleer.read((char *)&fl,sizeof(FarmBin));                                                 //
    farm.name=fl.name;nextSerialNumber=fl.nextSerialNumber;hour=fl.hour;                       //read farm
    for(size_t i=0;i<fl.numFields;i++){
        fichleer.read((char *)&fil,sizeof(FieldBin));                                         //
        fc.name=fil.name;                   fc.products=fil.products;                        //  read field
        fc.hoursLeft=fil.hoursLeft;                                                         //      and
        farm.fields.push_back(fc);                                                         //write into the farm
        for(size_t j=0;j<fil.numAndroids;j++){
          fichleer.read((char *)&al,sizeof(AndroidBin));                                      //
          ac.model=al.model;                 ac.speed=al.speed;                              //
          ac.serialNumber=al.serialNumber;                                                  //read the androids in the fields
          ac.status=al.status;               ac.hoursWorked=al.hoursWorked;                //
          farm.fields[i].androids.push_back(ac);                                          //
        }
    }
    while(fichleer.read((char *)&al,sizeof(AndroidBin))){
      ac.model=al.model;  ac.speed=al.speed;                                             //
      ac.serialNumber=al.serialNumber;                                                  //read the androids
      ac.status=al.status; ac.hoursWorked=al.hoursWorked;                              // from the field and
      farm.androids.push_back(ac);                                                    //  put into the farm
    }
    fichleer.close();                                                               //close the file
  }
  else{
   error(ERR_OPEN_FILE);result=false;
  }
  return(result);
}

// returns the number of lines from a filename
int numberRow(string filename){
  ifstream arch(filename.c_str(), ifstream::in);
  int lin=0;
  string s;
  if(arch.is_open()){
     while(arch.good()) if(arch.get()=='\n') lin++;
  }
  arch.close();
  return(lin);
}

// remove spaces from the androids file
void removeSpaces(string &s){
	unsigned int cont=0;
	bool encletra=false;
	while(cont<s.size()){
		if(s[cont]!=' ')
			encletra=true;
		if(s[cont]==' ' && !encletra)
		  s.erase(s.begin()+0);
		else
		  cont++;
	}
}

// complement of importAndroids and processArguments
bool importAndroids2(string filename,Farm &farm,int &nextSerialNumber){
	bool result=true;
	int filas,e;
	Android a;string s;
	ifstream andr(filename.c_str(),ifstream::in);                              //declaration to read a filename
	filas=numberRow(filename);                                                //number of rows
	if(andr.is_open()){                                                      //open the file
	 	while(filas>0){                                                       //read the file row by row
	 		andr>>e;                                                           //read the number
	 		getline(andr,s);                                                  //read the model with initial space
	 		removeSpaces(s);                                                 //remove the initial space
	 		a.speed=e;  a.model=s;
	 	    createAndroid2(farm,e,s,nextSerialNumber,false);             //create android
	 		filas--;
	 	}
	 	andr.close();	                                                //close the file
	}
	else{
	 	error(ERR_OPEN_FILE);                                      //error if can't open
	 	result=false;
	} 	
	return(result);
}

// asks for the filename, then opens the file and reads android data. If the
// file can't be opened returns false, otherwise returns true
bool importAndroids(Farm &farm,int &nextSerialNumber){
	bool result=true;
	string filename;
	cout << FILENAME;
	getline(cin,filename);cin.clear();
	result=importAndroids2(filename,farm,nextSerialNumber);
	return(result);
}

// complement of importProducts and processArguments
bool importProducts2(string filename,Farm &farm){
	bool result=true;
	Field f;
	int filas;
	string field;
	ifstream fields(filename.c_str(),ifstream::in);               //declaration to read a filename
	filas=numberRow(filename);                                   //number of rows
	if(fields.is_open()){                                       //open the file
		while(filas>0){
			getline(fields,field);                                //get the line
			processProducts(farm,field);                         //process the string
			filas--;
		}
	fields.close();                                       //close the file
	}
	else{
		error(ERR_OPEN_FILE);
		result=false;
	}
	return(result);
}

// asks for the filename, then opens the file and reads product data. If the
// file can't be opened returns false, otherwise returns true
bool importProducts(Farm &farm){
	bool result=true;
	string filename;
	cout << FILENAME;
	getline(cin,filename);cin.clear();
	result=importProducts2(filename,farm);
	return(result);
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

// returns true if the number is pair otherwise false
bool pairOdd(int number){
	bool result=false;
	if(number%2==0){
		result=true;
	}
	return(result);
}

// necessary comprobations to the arguments
bool checkArg(vector<string> &v){
	bool result=true;
	int conta=0,contp=0,contf=0;
	for(size_t i=0;i<v.size();i++){
		if(v[i]!="-a" && v[i]!="-f" && v[i]!="-p")                                           //     if there aren't any arg -f-a-p false
			result=false;
		if(v[i]=="-a") conta++;                                                            //
		if(v[i]=="-f") contf++;                                                           //       count the args
		if(v[i]=="-p") contp++;                                                          //
	}
	if(conta>1||contp>1)                                                             //          check if there are more than 1 -p-a arg
		result=false;                                                                 //
	return(result);
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
			if(pairOdd(i))                                                                      //
				vp.push_back(x);                                                                 //   fill pair vector and odd vector with the arguments
		    else                                                                            //    in these positions
		    	vi.push_back(x);                                                             //
	    }
	}
	if(!checkArg(vi))                                                                 //       check the odd arguments with all the steps
		error(ERR_ARGS);
	else{
		if(vp.size()!=vi.size())                                                      //
			error(ERR_ARGS);                                                           //          check if the number of arguments are distinct
		else{
			result=true;
			for(size_t i=0;i<vi.size();i++){
				if(vi[i]=="-f")                                                      //
					fiel.push_back(vp[i]);                                            //            fill field vector with all the fields in the args
			}
			for(size_t j=0;j<fiel.size();j++)
				createFields(farm,fiel[j]);                                      //               create them
			for(size_t i=0;i<vi.size();i++){
				if(vi[i]=="-a")
					importAndroids2(vp[i],farm,nextSerialNumber);               //                 import androids with -a option
				if(vi[i]=="-p")                                              //
					importProducts2(vp[i],farm);                              //                   import products with -p option
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
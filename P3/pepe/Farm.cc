#include "Farm.h"

const string& Farm::getName() const {
	return name;
}

void Farm::distributeAndroids() {
}

void Farm::collect(int& hour) {
}

unsigned int Farm::getNumAndroids() const {
	return numAndroids;
}

Farm::Farm(string name) {
	this->name=name;
	this->numAndroids=0;
}

unsigned int Farm::numFields() const {
	unsigned int result=0;
	result=fields.size();
	return(result);
}

void Farm::createField(string fieldName) {
	Field f1(fieldName);
	fields.push_back(f1);
}

void Farm::createAndroid(int speed, string model) {
}

void Farm::processProducts(string products) {
}

void Farm::startWorkingHour(int& hour) {
}

ostream& operator<<(ostream&s,const Farm &f1){
	s<<"Farm: "<<f1.name<<endl;
	for(int i=0;i<1;i++)
     s<< f1.fields[i];

    return s;
}

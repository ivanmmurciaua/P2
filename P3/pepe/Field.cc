/*
 * Field.cc
 *
 *  Created on: 13 may. 2017
 *      Author: Usuario
 */

#include "Field.h"

Field::Field(string name) {
	this->hoursLeft=10;
	this->name=name;
	this->products=0;
}

int Field::getHoursLeft() const {
	return hoursLeft;
}

const string& Field::getName() const {
	return name;
}

int Field::getProducts() const {
	return products;
}

void Field::setProducts(int products) {
	this->products = products;
}

//unsigned int Field::numAndroids() const{};

void Field::addProducts(int products){};

bool Field::needsDroids() const{return true;};

void Field::addDroid(Android * newAndroid){};

//void Field::collect();

ostream& operator<<(ostream &s,const Field &f1){
	s<<"Field: "<<f1.name<<"("<<f1.products<<" "<<f1.hoursLeft<<")";
					/*for(i=0;i<1;i++){
						os<<*f.androids[i];
					}*/
					return s;
};



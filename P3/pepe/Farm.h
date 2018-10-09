#include <iostream>
#include <vector>
using namespace std;

#include "Field.h"

#ifndef FARM_H_
#define FARM_H_

class Farm {
  protected:
	static const int MAXANDROIDS=30;
	string name;
	unsigned int numAndroids;
	vector <Field> fields;
//------METHODS-------//
	void distributeAndroids();
	void collect(int &hour);
  public:
	Farm(string name);
	const string& getName() const;
	unsigned int getNumAndroids() const;
	unsigned int numFields() const;
	void createField(string fieldName="");
	void createAndroid(int speed=-1, string model="");
	void processProducts(string products);
	void startWorkingHour(int &hour);
	friend ostream& operator<<(ostream&s,const Farm &f1);
	//-------------------
};

#endif /* FARM_H_ */

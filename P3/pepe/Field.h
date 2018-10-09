#include <iostream>
using namespace std;

#include "Android.h"

#ifndef FIELD_H_
#define FIELD_H_

class Field {
protected:
	string name;
	int products;
	int hoursLeft;
	int droidsCapacity() const;
public:
	Field(string name);
	int getHoursLeft() const;
	const string& getName() const;
	int getProducts() const;
	void setProducts(int products);
	unsigned int numAndroids() const;
	void addProducts(int products);
	bool needsDroids() const;
	void addDroid(Android * newAndroid);
	void collect();
	friend ostream& operator<<(ostream&s,const Field &f1);
};

#endif /* FIELD_H_ */

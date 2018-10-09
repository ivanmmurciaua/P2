#include <iostream>
using namespace std;

#ifndef ANDROID_H_
#define ANDROID_H_

enum Status {
  ST_WORKING,
  ST_IDLE,
  ST_MAINTENANCE0,
  ST_MAINTENANCE1
};

class Android {
  protected:
	string model;
	int speed;
	int serialNumber;
	int hoursWorked;
	static int nextSerialNumber;
	Status status;
	bool assigned;
  public:
	//------------------------------METHODS--------------------------//
	Android();
	Android(string model,int speed);
	bool isAssigned() const;
	void setAssigned(bool assigned);
	int getHoursWorked() const;
	const string& getModel() const;
	int getSerialNumber() const;
	int getSpeed() const;
	Status getStatus() const;
	void setStatus(Status status);
	bool isIdle() const;
	void oneMoreHour();
	bool isMaintenanceTime();
	friend ostream& operator<<(ostream&s,const Android &a1);
	void resetHoursWorked();
	//friend ostream& operator<<(ostream &s, const Android &a); .h
	//ostream& operator<<(ostream &s,const Android &a) .cc
};

#endif /* ANDROID_H_ */

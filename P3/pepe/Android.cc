#include "Android.h"


int Android::nextSerialNumber=100;

bool Android::isAssigned() const {
	return assigned;
}

void Android::setAssigned(bool assigned) {
	this->assigned = assigned;
}

int Android::getHoursWorked() const {
	return hoursWorked;
}

const string& Android::getModel() const {
	return model;
}

int Android::getSerialNumber() const {
	return serialNumber;
}

int Android::getSpeed() const {
	return speed;
}

Status Android::getStatus() const {
	return status;
}

void Android::setStatus(Status status) {
	this->status = status;
}

Android::Android() {
	this->model="Antonio";
	this->assigned=0;
	this->hoursWorked=0;
	this->serialNumber=nextSerialNumber;
	this->nextSerialNumber++;
	this->status=ST_IDLE;
	this->speed=-1;
}



bool Android::isIdle() const {
	if(this->status==ST_IDLE)
		return(true);
	else
		return(false);
}

void Android::oneMoreHour() {
	this->hoursWorked++;
}

Android::Android(string model, int speed) {
	this->model=model;
	this->assigned=0;
	this->hoursWorked=0;
	this->serialNumber=nextSerialNumber;
	this->nextSerialNumber++;
	this->status=ST_IDLE;
	this->speed=speed;
}

//bool Android::isMaintenanceTime() {
//}

ostream& operator<<(ostream &s,const Android &a1){
		s<<"["<<a1.model<<" sn="<<a1.serialNumber<<" s="<<a1.speed<<" hw="<<a1.hoursWorked<<" st="<<a1.status<<" a="<<a1.assigned<<"]" << endl;
		return s;
}

void Android::resetHoursWorked() {
}

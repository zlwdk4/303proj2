#pragma once
#include <string>
using namespace std;
class Employee
{
public:
	Employee(string nameOfPerson) {
		name = nameOfPerson;
		retainingTime = 0;
		waitingTime = 0;
	}
	string getName() {
		return name;
	}
	int getRetainingTime() {
		return retainingTime;
	}
	int getWaitingTime() {
		return waitingTime;
	}
	void setName(string nameOfPerson) { 
		name = nameOfPerson;
	}
	void setRetainingTime(int time) {
		retainingTime = time;
	}
	void setWaitingTime(int time) { 
		waitingTime = time; 
	}
	bool operator<(Employee rhs) const
	{
		if ((waitingTime - retainingTime) < (rhs.waitingTime - rhs.retainingTime))
			return true;
		else return false;
	}
	
private:
	string name;
	int retainingTime;
	int waitingTime;


};
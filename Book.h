#pragma once
#include <string>
#include "Date.h"
#include "PriorityQueue.h"
#include "Employee.h"
using namespace std;
class Book
{
public:
	Book (string nameOfBook){
		name = nameOfBook;
		archived = false;
	}
	string getName() { 
		return name;
	}
	Date getCircStartDate() {
		return circStartDate;
	}
	Date getCircEndDate() {
		return circEndDate;
	}
	Date getLastPassedDate() {
		return lastPassedDate;
	}
	int getNumEmployees() {
		return numEmployees;
	}
	void setName(string nameOfBook) { 
		name = nameOfBook;
	}
	void setCircStartDate(Date date) {
		circStartDate = date;
	}
	void setCircEndDate(Date date) {
		circEndDate = date;
	}
	void setLastPassedDate(Date theDate){
		lastPassedDate = theDate;
	}
	void addEmployeeToQueue(Employee employeeToBeAdded) {
		EmpQue.push(employeeToBeAdded);
		numEmployees++;
	}
	void removeTopEmployee() {
		EmpQue.pop();
		numEmployees--;
	}
	Employee& getNextEmployee() {
		if (EmpQue.empty())
		{
			Employee nullEmployee("null");
			return nullEmployee;
		}
		return EmpQue.top();
	}
	bool operator==(Book rhs) {
		if (name == rhs.name)
			return true;
		else return false;
	}
private:
	int numEmployees;
	string name;
	Date circStartDate;
	Date circEndDate;
	PriorityQueue<Employee> EmpQue;
	Date lastPassedDate;
	bool archived;


};
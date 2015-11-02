#pragma once
#include <list>
#include "Book.h"
#include "Employee.h"
#include "Date.h"
#include <string>

using namespace std;
class Library
{
public:
	void addBook(string bookName);
	void addEmployee(string name);
	void circulateBook(string title, Date circDate);
	void passToNextEmployee(string title, Date passDate);
private:
	list<Book> toBeCirc;
	list<Book> archived;
	list<Employee> empList;

};
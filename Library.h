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
	list<Book> toBeCirc; ////!!!!!!!!!!!moved here for testing

private:

	list<Book> archived;
	list<Employee> empList; //books and employees should be pointers...

};
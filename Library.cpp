#include "Library.h"
#include <cctype>
//when a book gets added, it gets added to the to-be-circulated-list (toBeCirc).
//Also, every person in the employee list (empList) that has been added so far gets added to this book's que
void Library::addBook(string bookName)
{
	//add the book to the list of books
	Book bookToAdd = Book(bookName);

	toBeCirc.push_back(bookToAdd);

	//if there are no employees, just return.
	if (empList.empty())
		return;
	//otherewise add each employee to that book's queue
	else
	{
		list<Employee>::iterator iter = empList.begin();
		for (iter; iter != empList.end(); ++iter)
		{
			bookToAdd.addEmployeeToQueue(*iter);
		}
	}
}
//When an employee gets added, they get added to the employee list (empList).
//Also, this employee gets added to the queue of each book in the to be circulated list of book (toBeCirc)
void Library::addEmployee(string name)
{
	//add the employee to the list
	Employee employeeToAdd(name);
	empList.push_front(employeeToAdd);

	//if the list of books to be circulated is empty, just return since there are no books for this employee to be added to
	if (toBeCirc.empty())
		return;
	//otherwise, add the employee to each book list
	else
	{
		//iterate through each book
		list<Book>::iterator iter = toBeCirc.begin();
		for (iter; iter != toBeCirc.end(); ++iter)
		{
			//add the employee to the current book
			iter->addEmployeeToQueue(employeeToAdd);
		}
	}
}
//If this function is called, we want to take the book that is called and give it to the first person in line for the book
//We want to also mark the start of the circulation date (circDate) so we know how many days that the person has been in
//possesion of the book and how long the next person has had to wait for the book. 
void Library::circulateBook(string title, Date circDate)
{
	//add the book if there are no books to be circulated
	if (toBeCirc.size() == 0)
	{
		addBook(title);
	}
	list<Book>::iterator curBook = toBeCirc.begin();
	while (curBook != toBeCirc.end() && curBook->getName() != title)
	{
		++curBook;
	}
	//if the iterator has gone through the whole list and hasn't found the book, add it to the list of books to be circulated
	if (curBook == toBeCirc.end())
	{
		addBook(title);
		*curBook = toBeCirc.back();
	}
	//Now give the book it's circulation date
	curBook->setCircStartDate(circDate);
	curBook->setLastPassedDate(circDate);
	
	
}
//give the book to the next person in line
void Library::passToNextEmployee(string title, Date passDate)
{
	//search through the books and find the right one
	list<Book>::iterator curBook = toBeCirc.begin();
	while (curBook != toBeCirc.end() && curBook->getName() != title)
	{
		++curBook;
	}

	//if the iterator has gone through the whole list and hasn't found the book, return because the book isn't in circulation
	if (curBook == toBeCirc.end())
	{
		return;
	}

	//get the first person on the queue and give them a retaining time of the last pass date minus the current pass date
	Employee firstInLine = curBook->getNextEmployee();
	int retainTime = (passDate - (curBook->getLastPassedDate()));
	firstInLine.setRetainingTime(retainTime);

	//Save the person's waiting time
	int waitTime = firstInLine.getWaitingTime();

	//Pop them from the queue
	curBook->removeTopEmployee();

	//If there is not someone else in line, move the book into the archived list
	if ((curBook->getNumEmployees() == 0))
	{
		curBook->setCircEndDate(passDate);
		archived.push_front(*curBook);
		toBeCirc.remove(*curBook);
	}

	//If there is someone else in line, then give them a wait time equal to the previous person's retaining time
	else
	{
		int nextWait = retainTime + waitTime;
		curBook->getNextEmployee().setWaitingTime(nextWait);
		//save current passed date
		curBook->setLastPassedDate(passDate);
	}

}
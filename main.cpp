#include <iostream>
#include "Date.h"
#include "Library.h"
using namespace std;

int main()
{

	Library library;
	library.addBook("Software Engineering");
	library.addBook("Chemistry");
	library.addEmployee("Adam");
	library.addEmployee("Sam");
	library.addEmployee("Ann");
	//initally books are added to the to-be-circulated list of books. Not archived.
	library.circulateBook("Chemistry", Date(2015, 3, 1, DateFormat::US));
	library.circulateBook("Software Engineering", Date(2015, 4, 1, DateFormat::US));
	library.passToNextEmployee("Chemistry", Date(2015, 3, 5, DateFormat::US)); 
	library.passToNextEmployee("Chemistry", Date(2015, 3, 7, DateFormat::US));
	library.passToNextEmployee("Chemistry", Date(2015, 3, 15, DateFormat::US)); //at this point in time,the system will archive the chemistry book.
	library.passToNextEmployee("Software Engineering", Date(2015, 4, 5, DateFormat::US));
	library.passToNextEmployee("Software Engineering", Date(2015, 4, 10, DateFormat::US));
	library.passToNextEmployee("Software Engineering", Date(2015, 4, 15, DateFormat::US));



	system("pause");
	return 0;
}
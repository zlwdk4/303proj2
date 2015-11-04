
#include <list>
#include "Book.h"
#include "Employee.h"
#include "Date.h"
#include "Library.h"
#include <string>
#include <cstdlib>



using namespace std;


string randString(int len)
{
	string t = "";
	for (int i = 0;i<len;i++)
	{
		switch (rand() % 3)
		{
		case 0:
			t += ('0' + rand() % 10);
			break;
		case 1:
			t += ('A' + rand() % 26);
			break;
		case 2:
			t += ('a' + rand() % 26);
			break;
		}
	}
	return t;
}

void circRand(Library &library, string book) {

	int y, m, d;
	y = rand() % 2;
	if (y == 0)
		y = 2015;
	else
		y = 2016;
	m = rand() % 12;
	m++;

	d = 1;

	Date rDate(y, m, d, DateFormat::US);
	rDate.add_days(rand() % 31);

	library.circulateBook(book, rDate);


}

void randPass(Library &library, list<Book>::iterator ibook) {
	Book book = *ibook;
	int randDays = rand() % 13;
	randDays++;

	Date newDate;
	newDate = book.getLastPassedDate();
	newDate.add_days(randDays);

	library.passToNextEmployee(book.getName(), newDate);

}
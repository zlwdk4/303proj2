#include <iostream>
#include "Date.h"
#include "Library.h"
#include "Testing.h"


using namespace std;


int main()
{

	Library library;
	for (int i = 0; i < 333; i++) {
		string rs = randString(10);
		library.addBook(rs);
	}

	for (int i = 0; i < 23; i++) {
		string re = randString(8);
		library.addEmployee(re);
	}

	list<Book>::iterator iter = library.toBeCirc.begin();
	while (iter != library.toBeCirc.end()) {
		circRand(library, iter->getName());
		++iter;
	}

	while (library.toBeCirc.size() != 0) {
		iter = library.toBeCirc.begin();
		int randInc = rand() % library.toBeCirc.size();
		while (randInc != 0) {
			iter++;
			randInc--;
		}
		randPass(library, iter);

	}

	




	system("pause");
	return 0;
}
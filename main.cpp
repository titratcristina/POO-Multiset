#include <iostream>
#include <cassert>
#include "Multiset.h"

using namespace std;

void multisetTests() {
	Multiset<int> M, N;

	M.insert(1);
	M.insert(1);
	M.insert(1);
	M.insert(2);
	M.insert(3);
	M.insert(4);

	assert(M.find(2) == 1);        	// verific dacă multisetul conține valoarea 2
	assert(M.find(5) == 0);        	// verific dacă multisetul nu conține valoarea 5
	assert(M.count(1) == 3);        // verific dacă numărul aparițiilor valorii 1 este 3

	M.remove(1);                // se sterge ultima valoare din multiset a numărului 1
	assert(M.count(1) == 2);        // verific dacă numărul aparițiilor valorii 1 după ștergere este 2

}

int main() {
	multisetTests();
	cout << "Testele au trecut!" << endl;
	return 0;
}

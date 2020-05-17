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

	M.remove(1);            	// se sterge ultima valoare din multiset a numărului 1
	assert(M.count(1) == 2);        // verific dacă numărul aparițiilor valorii 1 după ștergere este 2

	M.removeAll(1);          	// se sterg toate aparitiile lui 1
	assert(M.count(1) == 0);        // verific dacă numărul aparițiilor valorii 1 după ștergerea totală este 2

	assert(M.getDistinct() == 3);  	// 3 elemente distincte

	Multiset<int> C(M);            	// constructor de copiere
	assert(C.find(2) == 1 && C.find(3) == 1 && C.find(4) == 1); // verific ca elementele din C să fie cele din M

	N = M;                         	// copiez elementele din M in N
	assert(N.find(2) == 1 && N.find(3) == 1 && N.find(4) == 1); // verific ca elementele din N să fie cele din M

	N.insert(5);            	// inserez valori duplicate în multiset
	N.insert(5);
	assert(N.count(5) == 2);        // verific dacă numărul aparițiilor valorii 5 este 3

	Multiset<double> D;

	D.insert(1.54);
	D.insert(2.54);
	D.insert(3.34);
	D.insert(4.46);

	assert(D.find(3.34) == 1);

	cout << D; 						// testare cout

}

int main() {
	multisetTests();
	cout << "Testele au trecut!" << endl;
	return 0;
}

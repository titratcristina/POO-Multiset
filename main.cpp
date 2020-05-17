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
}

int main() {
	multisetTests();
	cout << "Testele au trecut!" << endl;
	return 0;
}

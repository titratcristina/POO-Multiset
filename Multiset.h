//
// Created by Cristina Titrat on 17/05/2020.
//

#ifndef POO_MULTISET_MULTISET_H
#define POO_MULTISET_MULTISET_H

#include <iostream>
#include "Comparator.h"

using namespace std;

template<typename T, typename F = Comparator<T>>
class Multiset {
	int distinctSize;        // numărul elementelor distincte
	int size;                // numărul tuturor elementelor

	struct Node {
		T info;
		int n = 0;
		Node *next;
		Node *prev;
	};

	Node *head;

public:
	Multiset();                                	// constructor fără parametrii care inițializează un multiset gol
	Multiset(const Multiset &);                	// constructor de copiere
	Multiset &operator=(const Multiset &);     	// operatorul de atribuire
	void insert(const T &value);                // metodă pentru adăugarea unui element în multiset
	void remove(const T &value);                // metodă pentru ștergerea unui element din multiset (se șterge prima apariție)
	int count(const T &value) const;            // metodă care întoarce numărul de apariții ale unui element;
	bool find(const T &value) const;            // metodă care verifică dacă un element se află în multiset;
	void removeAll(const T &value);            	// metodă care elimină toate aparițiile unui element din multiset;
	int getDistinct() const;                    // metodă care întoarce numărul de elemente distincte din multiset;
	friend ostream &operator<<(ostream &, Multiset<T> const &); // supraîncărcarea operatorului de afișare;
	~Multiset();                                // destructor
};

#endif //POO_MULTISET_MULTISET_H

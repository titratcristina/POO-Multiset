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

// constructor fără parametrii care inițializează un multiset gol
template<class T, class F>
Multiset<T, F>::Multiset() {
	distinctSize = 0;            // numărul elementelor distincte este 0
	size = 0;                    // numărul tuturor elementelor este 0
	head = new Node;
	head->next = head;
	head->prev = head;
}

// constructor de copiere
template<class T, class F>
Multiset<T, F>::Multiset(const Multiset &object) {
	if (this != &object) {
		size = object.size;
		distinctSize = object.distinctSize;

		head = new Node;
		head->next = head;
		head->prev = head;

		Node *p = head;
		Node *q = object.head->next;

		while (q != object.head) {
			p->next = new Node;

			p->next->info = q->info;
			p->next->n = q->n;
			p->next->prev = p;

			q = q->next;
			p = p->next;
		}
		p->next = head;
		head->prev = p;
	}
}

// operatorul de atribuire
template<class T, class F>
Multiset<T, F> &Multiset<T, F>::operator=(const Multiset &object) {
	if (this != &object) {
		Node *mp = head->next;
		while (mp != head) {
			head->next = mp->next;
			delete mp;
			mp = head->next;
		}
		delete head;

		size = object.size;
		distinctSize = object.distinctSize;

		head = new Node;
		head->next = head;
		head->prev = head;

		Node *p = head;
		Node *q = object.head->next;

		while (q != object.head) {
			p->next = new Node;

			p->next->info = q->info;
			p->next->n = q->n;
			p->next->prev = p;

			q = q->next;
			p = p->next;
		}
		p->next = head;
		head->prev = p;
	}
	return *this;
}

#endif //POO_MULTISET_MULTISET_H

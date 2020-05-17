//
// Created by Cristina Titrat on 17/05/2020.
//

#ifndef POO_MULTISET_COMPARATOR_H
#define POO_MULTISET_COMPARATOR_H

template<class T>
class Comparator {
public:
	static bool equal(T, T);
};

template<class T>
bool Comparator<T>::equal(T a, T b) {
	return (a - int(a) == b - int(b));
}

#endif //POO_MULTISET_COMPARATOR_H

#include <iostream>
#include "Collection.h"

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector : public Collection<T> {
public:
	T get(int index) {
		return mGet(index);
	}

	//Note: this removes ONLY THE FIRST OCCURRENCE OF "obj"
	//bool remove(T obj);
};

#endif
/** Set class, inherits from Collection
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
**
**		Set is identical to Collection (and so internally stores elements
**	using a dynamically sized array) except for the fact that it will not
**	store duplicates of an elements. In all other ways it may as well be
**	an instantiable version of the Collection class.
**
**		Note that, even though items in the Set are stored in the order
**	in which they are added, the user of the set is unable to see that
**	order (in accordance with the properties of a mathematical set)
**
*/

#include <iostream>
#include "Collection.h"

#ifndef SET_H
#define SET_H

template <class T>
class Set : public Collection<T> {
public:
	//overriden from parent, since elements in a set are unique
	void add(T obj) {
		//add the obj iff it does not already exist in the set
		if (!contains(obj)) {
			Collection::add(obj);
		}
	}
};

#endif
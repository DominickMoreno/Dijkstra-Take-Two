/** Container class, similar to the Collections interface in Java.
**
**	Author: Dominick Moreno
**	Project: Dijkstra Take Two
**
**		Collection is dynamically sized, similar to the std::vector class in the
**	STL. However it is also abstract, so it cannot be instantiated. Also note
**	that all members defined here are made private - child classes (such as Set or
**	Vector) cannot access them directly. Child classes of Collection are to use
**	protected and public methods in order to access the encapsulated data.
**
**		Note the data is stored internally using an array that is dynamically 
**	allocated. If it becomes full it simply creates a larger array, and copies all
**	of the data from the old one into the new one, keeping track of the size
**	appropriately.
**
**		Has a strange bug - if you instantiate a(n empty) child class of Collection,
**	e.g. it will call the default constructor of the class it contains. In
**	particular this is a problem with a Vector<Node>, where it will call the Node
**	default constructor 64 times (the size of a data_chunk). 
**
*/

#ifndef COLLECTION_H
#define COLLECTION_H

template <class T>
class Collection {
public:
	static const int DATA_CHUNK_SIZE = 64;

	Collection<T>() {
		initializationAllocation();
	};

	~Collection<T>() {
		delete[] data;
		data = NULL;
	}

	//Adds the object to the collection, allocating memory appropriately.
	//O(1) if not allocating more memory, O(n) if allocating more memory
	//	so O(n)
	virtual void add(T obj) {
		if (size == (numDataChunksUsed * DATA_CHUNK_SIZE)) {
			additionalAllocation();
		}

		size++;
		data[size - 1] = obj;
	}

	//removes the object from the collection. O(n)
	virtual bool remove(T obj) {
		for (int i = 0; i < size; i++) {
			if (data[i] == obj) {
				for (int j = i; j < size; j++) {
					data[j] = data[j + 1];
				}

				size--;
				return true;
			}
		}
		return false;
	}

	//returns the size of the collection. O(1)
	virtual int getSize() {
		return size;
	}

	//resets the collection object, freeing all internal memory. O(1)
	virtual void clear() {
		delete[] data;
		initializationAllocation();
	}

	//returns true iff the object is in the collection. O(n)
	virtual bool contains(T obj) {
		for (int i = 0; i < size; i++) {
			if (data[i] == obj) {
				return true;
			}
		}
		return false;
	}

	virtual void replace(T obj, int index) {
		if (index < size) {
			data[index] = obj;
		}
	}

protected:
	virtual T mGet(int indx) {
		return data[indx];
	}
private:
	int size;
	int numDataChunksUsed;
	T* data = NULL;

	//allocates the initial data chunk
	void initializationAllocation() {
		size = 0;
		numDataChunksUsed = 1;
		data = new T[DATA_CHUNK_SIZE];
	}

	//allocates all data chunks after the first
	void additionalAllocation() {

		numDataChunksUsed++;
		T* newData = new T[(DATA_CHUNK_SIZE * numDataChunksUsed)];

		//copy the old data into our new buffer
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}

		//clean up old resources
		delete[] data;
		data = NULL;

		data = newData;
	}
};

#endif

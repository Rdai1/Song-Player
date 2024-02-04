
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream&, Array<V>&);

	public:

		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T&);
		// T& get(T& index);
		int getSize() const;
		bool isFull() const;
		T& operator[](int);
		T& operator[](int) const;
		void operator+=(T&);
		void operator-=(T&);
		void clear();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
ostream& operator<<(ostream& out, Array<T>& list)
{
  out << "Printing Elementss: " << endl;
  for (int i = 0; i < list.getSize(); ++i){
	out << list[i]->print() << endl;
  }
  return out;
}

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
	// cout << " BB " << endl;
}

template <class T>
void Array<T>::add(T& t){
	if (size >= MAX_ARRAY)   return;
  	elements[size++] = t;
	cout<< "The current size: " << size << endl;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARRAY;
}

// template <class T>
// T& Array<T>::get(T& index){
// 	if (index < 0 || index >= size) {
// 		cerr<<"Array index out of bounds"<<endl;
// 		exit(1);
// 	}
// 	return elements[index];
// }

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= size){
		cerr << "INDEX IS OUT OF BOUNDS" << endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= size){
		cerr << "INDEX IS OUT OF BOUNDS" << endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
void Array<T>::operator+=(T& element){
	// cout<< "The current size: " << size << endl;

	if (size >= MAX_ARRAY)   return;
  	elements[size++] = element;
	// cout<< "The current size: " << size << endl;
}

template <class T>
void Array<T>::operator-=(T& element){
	int index = 0;

	while (index < size && element != elements[index]){
		++index;
	}

	if (index == size) return;

	while (index < size-1){
		elements[index] = elements[index +1];
		++index;
	}

	--size;
}

template <class T>
void Array<T>::clear(){
	for (int i = this->size-1; i >= 0; --i){
		// elements -= elements[i];
		elements[i] = NULL;
	}
	this->size = 0;
}

#endif
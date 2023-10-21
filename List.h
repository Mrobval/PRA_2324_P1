#include <ostream>
#ifndef LIST_H
#define LIST_H
template <typename T>

class List{
	public: 
		//Se iguala a 0 porque es un método puro y genérico
		virtual void insert(int pos, T e) = 0;
		virtual void append(T e) = 0;
		virtual void prepend(T e) = 0;
		virtual T remove(int pos) = 0;
		virtual T get(int pos) = 0;
		virtual int search (T e) = 0;
		virtual bool empty() const = 0;
		virtual int size() const = 0;
};	
#endif

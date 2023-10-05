#include <ostream>
#ifndef LIST_H
#define LIST_H
template <typename T>

class List{
	public: 
		//Se iguala a 0 porque es un método puro y genérico
		virtual void insert(int pos, T e) const = 0;
		virtual void apend(T e) const = 0;
		virtual void prepend(T e) const = 0;
		virtual T remove(int pos) const = 0;
		virtual T get(int pos) const = 0;
		virtual int search (T e) const = 0;
		virtual bool empty() const = 0;
		virtual int size() const = 0;
};	
#endif

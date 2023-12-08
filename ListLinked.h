#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>*first;
	int n;

    public:

	LitLinked(){
		first = nullptr;
		n = 0;
	};
	~ListLinked(){
		while (first != nullptr){
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
	};
	T operator[](int pos){
	};
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	};

	void insert(int pos, T e) override{
	};
	void append(T e) override{
	};
	void prepend(T e)  override{
	};
	T remove(int pos) override{
	};
	T get(int pos) override{
	};
	int search (T e) override{
	};
	bool empty() const override{
	};
	int size() const override{
	};

}

#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>*first;
	int n;

    public:
	ListLinked(){
		first = nullptr;
		n = 0;
	};
	~ListLinked(){
		Node<T>* aux = first;
		while (aux != nullptr){
			Node<T>* d = aux;
			aux = aux->next;
			delete d;
		}
		first = nullptr;
		n = 0;
	};
	T operator[](int pos){
		if (pos < 0 || pos > n-1){
			throw std::out_of_range("La posición no es válida");
		}
		Node<T>* aux = first;
		for (int i=0; i < pos && aux != nullptr; i++){
			aux = aux->next;
		}
		return aux->data;
	};
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		Node<T>* aux = list.first;
		while (aux != nullptr){
			out << aux->data << " " << std::endl;
			aux = aux->next;
		}
		return out;
	};

	void insert(int pos, T e) override{
		if( pos < 0 || pos > n){
                       	throw std::out_of_range("La posicion no es valida");
               	}
		if (pos == 0){
			first = new Node<T>(e,first);
			n++;
		}
		else {
			Node<T>* aux = first;
			for (int i=0; aux!= nullptr && i < pos-1; i++){
				aux = aux->next;
			}
			if (aux != nullptr) {
				aux->next = new Node<T>(e, aux->next);
				n++;
			}
		}
	};
	void append(T e) override{
		insert(size(), e);
	};
	void prepend(T e) override{
		insert(0, e);
	};
	T remove(int pos) override{
		if (pos < 0 || pos > n-1){
			throw std::out_of_range("La posición no es válida");
		}
		Node<T>* aux = first;
		Node<T>* PrevAux = nullptr;
		for (int i=0; aux != nullptr && i < pos; i++){
			PrevAux = aux;
			aux = aux->next;
		}
		if (aux != nullptr){
			if (aux == first){
				first = first->next;
			}
			else{
				PrevAux->next = aux->next;
			}
			T elem = aux->data;
			delete aux;
			n--;
			return elem;
		}
		else{
			throw std::out_of_range("La posición no es válida");
		}
	};
	T get(int pos) override{
		if(pos <  0 || pos > n-1){
        	        throw std::out_of_range("La posición no es válida");
               	}
		Node<T>* aux = first;
		for (int i=0; aux != nullptr && i < pos; i++){
			aux = aux->next;
		}
		T elem = aux->data;
		return elem;
	};
	int search (T e) override{
		Node<T>* aux = first;
		int i=0;
		while (aux != nullptr && aux->data != e){
			aux = aux->next;
			i++;
		}
		if (aux != nullptr){
			return i;
		}
		else{
			return -1;
		}
	};
	bool empty() const override{
		return size() == 0;
	};
	int size() const override{
		return n;
	};

};

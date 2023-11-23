#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;

	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux = first;
			while (aux != nullptr){
				Node<T>* eliminar = first;
				first = first -> next;
				aux = aux -> next;
				delete eliminar;
			}
			first = nullptr;
			n = 0;
		}

		T operator[](int pos){
			if(pos <  0 || pos > n-1){
                        	throw std::out_of_range("La posicion no es valida");
               		}
			Node<T>*aux = first;
                        int i = 0;
                        while (aux != nullptr && i < pos){
                                aux = aux -> next;
                                i++;
                        }
                        T elem = aux->data;
                        return elem;
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>*aux = list.first;
			while(aux != nullptr){
				out << aux->data<< " "<<std::endl;
				aux = aux -> next;
			}
			return out;
		}
	    
		
		//añadimos los métodos de List.h
		void insert(int pos, T e) override final{
			if( pos < 0 || pos > n){
                        	throw std::out_of_range("La posicion no es valida");
               		 }
			
			if (pos == 0){
				first = new Node<T>(e,first);
				n++;
			}
			else {
				Node<T> * prev = first;
				int i = 0;
				while ( prev!= nullptr && i < pos-1){
					prev = prev->next;
					i++;
				}
				if(prev != nullptr) {//la posicion existe
					prev->next = new Node<T>(e, prev->next);
					n++;
				}
			}
		}

		void append(T e) override final {
			Node<T>* aux = first;
			int i = 0;
			while (aux != nullptr && i < n-1){
				aux = aux->next;
				i++;
			}
			aux->next = new Node<T>(e,nullptr);
			n++;
	   	}

		void prepend(T e) override final {
			 first= new Node<T>(e, first);
			 n++;
		}

		T remove(int pos) override final {
			if(pos <  0 || pos > n-1){
                                throw std::out_of_range("La posicion no es valida");
                        }
			Node<T>*prev = nullptr;
			Node<T>*aux = first;
			int i = 0;
			while (aux!= nullptr && i<pos){
				prev = aux;
				aux = aux->next;
				i++;
			}
			if (aux != nullptr){
				if (aux == first){ //primera posicion
					first = first ->next;
				}
				else {
					prev->next = aux->next;
				}
				T elem = aux->data;
				delete aux;
				n--;
				return elem;
	    		}
		}
            
		T get(int pos) override final {
			if(pos <  0 || pos > n-1){
                                throw std::out_of_range("La posicion no es valida");
               		}
			
			Node<T>*aux = first;
			int i = 0;
			while (aux != nullptr && i < pos){
				aux = aux -> next;
				i++;
		 	}
			T elem = aux->data;
			return elem;			
		}

            	int search(T e) override final {
			Node<T>*aux = first;
			int i = 0;
			while (aux!=nullptr && aux-> data != e){
				aux = aux -> next;
				i++;
			}
			if ( aux != nullptr){ //lo ha encontrado
				return i;
			}
			else{
				return -1;
			}
		}

		bool empty() override final {
			return n==0;
		}
            
		int size() override final {
			return n;
		}

};

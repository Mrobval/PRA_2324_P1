#include <ostream>
#include "List.h"
#include <stdexcept>

#define NUM_INICIAL 10

template<typename T>

class ListArray : public List<T> {
        private:
                T* arr;
                int max;
                int n;
                static const int MINISIZE = 2;
		void resize(int new_size){
			//No redimensionar a un tamaño menor al mínimo
			if (new_size < MINISIZE){
				return;
			}
			
			T* new_arr = new T[new_size];

			if (new_size <= size()){
				for (int i=0; i < new_size; i++){
					new_arr[i] = arr[i];
				}

			} else if (new_size > max){
				for(int i=0; i < size(); i++){
					new_arr[i] = arr[i];
				}
			}

			delete[] arr;
			arr = new_arr;
			max = new_size;
		};
        public:
                ListArray(){
			max = MINISIZE;
			n = 0;
			arr = new T[NUM_INICIAL];
		};
                ~ListArray(){
			delete[] arr;
		};
                T operator[] (int pos) const{
			if (pos < 0 || pos > size()){
				throw std::out_of_range("Posición no válida");
			}
			return arr[pos];
		};
                friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			if(list.size() == 0){
				out << "List => [";
			} else{
				out << "List => [" << std::endl;
				for (int i = 0; i < list.size(); i++){
					out << " "<< list[i] << std::endl;
				}
			}
			out << "]"; 
			return out;
		};
                void insert(int pos, T e) override{
			if (pos < 0 || pos > size()){
				throw std::out_of_range("Posición no válida");
			}
			
			if( size() == max){
				//Implementar redimension del array cuando size = max
				resize(max+5);
			}
			for (int i = size(); i>pos; i--){
				arr[i] = arr[i-1];
			}
			arr[pos] = e;

			n++;
		};
                void append(T e) override{
			insert(size(), e);
		};
                void prepend(T e)  override{
			insert(0, e);
		};
                T remove(int pos) override{
			if (pos < 0 || pos > size()-1){
                                throw std::out_of_range("Posición no válida");
			}
			T ElementoEliminado = arr[pos];
			for (int i = pos; i < size()-1; i++){
                               	arr[i] = arr[i+1];
                       	}
			n--;

			if (size() <= max - 10){
				resize(max-5);
			}
                        return ElementoEliminado;
		};
                T get(int pos) override{
			if (pos < 0 || pos > size()-1){
				throw std::out_of_range("Posición no válida");
			}
			return arr[pos];
		};
                int search (T e) override{
			for (int i=0; i < size(); i++){
				if(e == arr[i]){
					return i;
				}
			}
			return -1;
		};
                bool empty() const override{
			//De esta forma, si size = cero devuelve true y si es mayor a cero devuelve false
			return size() == 0; 
		};
                int size() const override{
			return n;
		};

};

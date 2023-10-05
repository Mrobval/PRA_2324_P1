#include <ostream>
#include "List.h"

template<T>

class ListArray : public List<T> {
        private:
                T* arr;
                int max;
                int n;
                static const int MINISIZE;
        public:
                ListArray();
                ~ListArray();
                T operator[] (int pos);
                friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list);
                void resize(int new_size);
                void insert(int pos, T e) override;
                void apend(T e) override;
                void prepend(T e) override;
                T remove(int pos) override;
                T get(int pos) override;
                int search (T e) override;
                bool empety() override;
                int size() override;

}

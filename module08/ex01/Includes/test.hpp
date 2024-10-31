#include <iostream>

template<typename T>
class MyArray
{
     private:
        T* data;
        size_t size;
    public:
        MyArray(size_t size) : size(size)
        {
            data = new T[size];
        }

        ~MyArray() {
            delete[] data;
        }

        T& operator[](size_t index) {
            return data[index];
        }

        size_t getSize() const {
            return size;
        }

        class Iterator {
            private:
                T* ptr;

            public:
                Iterator(T* ptr) : ptr(ptr) {}
                T& operator*() {
                    return *ptr;
                }

                Iterator& operator++() { // Pré-incrément
                    ++ptr;
                    return *this;
                }

                bool operator!=(const Iterator& other) {
                    return ptr != other.ptr;
                }

        };

        Iterator begin() {
            return Iterator(data); // Retourne un itérateur sur le début
        }

        Iterator end() {
            return Iterator(data + size); // Retourne un itérateur à la fin
        }   
};
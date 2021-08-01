#include <iostream>

template <typename T>
class Vector {
    private:
        T* arr;
        int capacity;
        int size;

    public:
        Vector() : capacity{1}, size{0} {
            arr = new T[1];
        }
        ~Vector() {
            delete[] arr;
        }
        void push_back(int data) {
            if(size == capacity) {
                T *temp = new T[capacity*2];
                for(int i=0; i<capacity; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
                capacity *= 2;
            }
            arr[size] = data;
            size++;
        }

        void pop_back() {
            size--;
        }
        T at(int index) {
            if(index < size)
            return arr[index];
        }

        void print() {
            for(int i=0; i<size; i++) {
                std::cout<<arr[i]<<" ";
            }
        }
};

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.print();
    return 0;
}
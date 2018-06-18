//
// Created by pranshu on 6/12/18.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H
#include <string.h>
#include <stdexcept>

template<class T>
class Stack {
private:
    T* internal_array;
    int capacity;
    int size;

public:
    Stack(int in_size) {
        in_size = (in_size > 0) ? in_size : 1;
        internal_array = new T[in_size];
        capacity = 0;
        size = in_size;
    }

    ~Stack() {
        delete[] internal_array;
    }

    void push(const T& inObj) {
        if (capacity < size) {
            internal_array[capacity] = inObj;
            capacity++;
        } else {
            //increase size by 1.5 and copy from one array to other
            size *= 2;
            T* new_arr = new T[size];
            size_t num = size * sizeof(T);
            memcpy(new_arr, internal_array, num);
            delete[] internal_array;
            internal_array = new_arr;
            internal_array[capacity] = inObj;
            printArr(new_arr, size);
            capacity++;
        }
    }

    T& pop(void) {
        if (capacity != 0) {
            return internal_array[--capacity];
        } else {
            throw std::runtime_error(std::string("Stack is empty!"));
        }
    }

    void printArr(const T* arr, int size) {
        std::cout << "[ ";
        for (int i =0; i < size; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << " ]" << std::endl;
    }
};

#endif //DATASTRUCTURES_STACK_H

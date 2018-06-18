//
// Created by pranshu on 6/13/18.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H
#include <stdexcept>
#include <cmath>
#include <iostream>

/*
 * Queue implemented with a circular buffer
 */

template<class T>
class Queue {
private:
    T* internal_array;
    int capacity;
    int size;
    int first;
    int last;

    void resize() {
        T* new_arr = new T[size*2];
        int index = 0;
        //copying elements to new array
        int prevIndex = (first == 0) ? (size - 1) : (first - 1);
        while (first != prevIndex) {
            new_arr[index] = internal_array[first];
            first = (first + 1) % size;
            index++;
        }
        //take care of last element
        new_arr[index] = internal_array[first];

        //handle old array
        delete[] internal_array;
        internal_array = new_arr;

        //double size
        size *= 2;

        //reset indexes
        first = 0;
        last = index + 1;
    }

public:
    Queue(int in_size) {
        in_size = (in_size > 10) ? in_size : 10;
        internal_array = new T[in_size];
        capacity = 0;
        size = in_size;
        first = 0;
        last = 0;
    }

    ~Queue() {
        delete[] internal_array;
    }

    void enqueue(const T inObj) {
        if (capacity < size) {
            internal_array[last] = inObj;
            last = (last + 1) % size;
        } else {
            resize();
            internal_array[last] = inObj;
            last++;
        }
        capacity++;
    }

    T dequeue() {
        int temp;
        if (capacity == 0) {
            throw std::runtime_error(std::string("Queue is empty!"));
        } else {
            capacity--;
            temp = first;
            first = (first + 1) % size;
            return internal_array[temp];
        }
    }


    void printArr() {
        std::cout << "[ ";
        for (int i =0; i < size; i++) {
            std::cout << internal_array[i] << ", ";
        }
        std::cout << " ]" << std::endl;
    }


};




#endif //DATASTRUCTURES_QUEUE_H

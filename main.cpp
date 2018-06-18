#include <iostream>
#include <string.h>
#include "stack.h"
#include "queue.h"


int main() {
    Queue<int> myQ(5);
    for(int i=0; i < 30; i++) {
        myQ.enqueue(i);
        myQ.printArr();
    }
    for(int i=0; i < 30; i++) {
        myQ.dequeue();
        myQ.printArr();

    }
    for(int i=30; i >= 0; i--) {
        myQ.enqueue(i);
        myQ.printArr();

    }
    for(int i=0; i < 31; i++) {
        std::cout << myQ.dequeue() << std::endl;

    }


    return 0;

}
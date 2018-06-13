#include <iostream>
#include <string.h>
#include "stack.h"



int main() {
    Stack<int> myStack(0);
    myStack.push(5);
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    std::cout << myStack.capacity << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << myStack.pop() << std::endl;
    return 0;

}
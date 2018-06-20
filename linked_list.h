//
// Created by pranshu on 6/19/18.
//

#ifndef DATASTRUCTURES_LINKED_LIST_H
#define DATASTRUCTURES_LINKED_LIST_H
template<class T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(T data) {
            this->data = data;
        }
    };
    Node* head;
    Node* tail;
    int size;

    Node* makeNode(T data) {
        Node* newNode = new Node(data);
        newNode->next = nullptr;
        return newNode;
    }

    void destroyNode();


public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push(T data) {
        if (head == nullptr) {
            head = makeNode(data);
            tail = head;
        } else {
            Node* holder = head;
            head = makeNode(data);
            head->next = holder;
        }
        size++;
    }

    //if return by reference, the reference is destroyed when the
    //node is removed later on, since the node itself is destroyed and
    //the node contains the data
    T pop() {
        T data;
        if (size == 0) {
            //throw exception
        } else if (size == 1) {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            data = head->data;
            Node *former = head;
            head = head->next;
            delete former;
        }
        size--;
        return data;
    }



};


#endif //DATASTRUCTURES_LINKED_LIST_H

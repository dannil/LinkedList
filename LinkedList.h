#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.h"

using namespace std;

template<typename T>
class Node;

template<typename T>
class LinkedList {

    private:
        Node<T> *sentinel;

    public:
        LinkedList<T>();
        ~LinkedList<T>();
        //Node<T>* getCurrent();
        void addFront(const T data);
        void addBack(const T data);
        T popFront();
        T popBack();
        bool isEmpty() const;
        Node<T>* getFirst() const;
        Node<T>* getLast() const;
        bool Check(int count);
};

template<typename T>
LinkedList<T>::LinkedList() {
    // Sentinel node
    this->sentinel = new Node<T>();
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (!isEmpty()) {
        delete sentinel->next;
    }
    delete sentinel;
}

/*template<typename T>
Node<T>* LinkedList<T>::getCurrent() {
    return this->current;
}*/

template<typename T>
void LinkedList<T>::addFront(const T data) {
    sentinel->insertAfter(data);
    //new Node<T>(data, current, current->next);
}

template<typename T>
void LinkedList<T>::addBack(const T data) {
    sentinel->insertBefore(data);
    //new Node<T>(data, current->previous, current);
}

template<typename T>
T LinkedList<T>::popFront() {
//    if (isEmpty()) {
//        throw std::out_of_range("LinkedList is empty");
//    }
    T data = sentinel->next->data;
    delete sentinel->next;
    return data;
}

template<typename T>
T LinkedList<T>::popBack() {
//    if (isEmpty()) {
//        throw std::out_of_range("LinkedList is empty");
//    }
    T data = sentinel->previous->data;
    delete sentinel->previous;
    return data;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    if (sentinel == sentinel->next) {
        return true;
    }
    return false;
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() const {
    return sentinel->next;
}

template<typename T>
Node<T>* LinkedList<T>::getLast() const {
    return sentinel->previous;
}

template<typename T>
bool LinkedList<T>::Check(int count) {
    if (count == 0 ^ (this->sentinel == this->sentinel->next)) {
        return false;
    }
    if (this->getFirst() != this->sentinel->next) {
        return (this->getLast() != this->sentinel->previous && count == 0);
    }
    if (this->getLast() != this->sentinel->previous && count == 0) {
        return false;
    }
    
    Node<T>* node = this->getFirst();
    while (count > 0) {
        count--;
        
        node = node->next;
    }
    return (node == this->sentinel && count == 0);
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, LinkedList<T>& list) {
    std::string s;
    
    // Not empty
    if (!list.isEmpty()) {
        s += "[";
        Node<T>* node = list.getFirst();
        while (node != list.getLast()) {
            s += std::to_string(node->getData()) + ", ";
            node = node->getNext();
        }
        s += std::to_string(list.getLast().getData()) + "]";
    } else {
        s = "[]";
    }
    
    return stream << s;
}

#endif
#ifndef LL_SIMPLE_H
#define LL_SIMPLE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLSimple {
    private:
    
        struct Node {
            T data;
            Node* next;
        };
        Node* head = NULL;

        int numberOfElements = 0;

        void insertAfter(Node* ptr, T data);
        T deleteAfter(Node* ptr);

    public:
        LLSimple();
        LLSimple(std::initializer_list<T> list);
        void insertAtFirst(T data);
        void insertAtLast(T data);
        void insertAfter(T node, T data);
        void insertBefore(T node, T data);
        void insertAtMid(T node);
        void deleteList();
        T deleteFirst();
        T deleteLast();
        T deleteBefore(T node);
        T deleteAfter(T node);
        T deleteMid();
        T deleteNode(T node);
        bool singleSearchFor(T data);
        int multiSearchFor(T data);

        // Getters and Setters
        void setList(std::initializer_list<T> list);
        std::string getListAsString();
        int getElementCount();

};

#include "../src/ll_simple.tpp"

#endif

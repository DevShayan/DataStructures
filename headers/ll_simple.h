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

        void insertAfter(Node* ptr, T data);
        T deleteAfter(Node* ptr);

    public:
        LLSimple();
        LLSimple(std::initializer_list<T> list);
        void insertAtFirst(T data);
        void insertAtLast(T data);
        void insertAfter(T node, T data);
        void insertBefore(T node, T data);
        T deleteAtFirst();
        T deleteAtLast();
        T deleteBefore(T node);
        T deleteAfter(T node);
        T deleteMid();
        T deleteNode(T node);

        // Getters and Setters
        void setList(std::initializer_list<T> list);
        std::string getListAsString();

        // Misc
};

#include "../src/ll_simple.tpp"

#endif

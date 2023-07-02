#ifndef LL_DOUBLE_H
#define LL_DOUBLE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLDouble {
    private:
    
        struct Node {
            T data;
            Node* next;
			Node* prev;
        };
        Node* head = NULL;
        int numberOfElements = 0;

        void insertAfter(Node* ptr, T data);
        T deleteAfter(Node* ptr);

    public:
        LLDouble();
        LLDouble(std::initializer_list<T> list);
        void insertAtFirst(T data);
        void insertAtLast(T data);
        void insertAtMid(T data);
        void insertAfter(T node, T data);
        void insertBefore(T node, T data);
        T deleteFirst();
        T deleteLast();
        T deleteBefore(T node);
        T deleteAfter(T node);
        T deleteMid();
        T deleteNode(T node);
        void deleteList();
        bool singleSearchFor(T data);
        int multiSearchFor(T data);

        // Getters and Setters
        void setList(std::initializer_list<T> list);
        std::string getListAsString();
        int getElementCount();

        // Misc
};

#include "../src/ll_double.tpp"

#endif

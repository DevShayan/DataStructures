#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLStack {
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* head;
        Node* tail;
        int numberOfElements = 0;

    public:
        LLStack();
        LLStack(std::initializer_list<T> list);
        void push(T data);
        T pop();
        void deleteStack();

        // getters and setters
        void setList(std::initializer_list<T> list);
        std::string getStackAsString();
        int getElementCount();
};

#include "../src/ll_stack.tpp"

#endif
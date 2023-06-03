#ifndef LL_DOUBLE_STACK_H
#define LL_DOUBLE_STACK_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLDoubleStack {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;
        };
        Node* top = NULL;
        int numberOfElements = 0;

    public:
        LLDoubleStack();
        LLDoubleStack(std::initializer_list<T> list);
        void push(T data);
        T pop();
        void deleteStack();

        // getters and setters
        void setList(std::initializer_list<T> list);
        std::string getStackAsString();
        int getElementCount();
};

#include "../src/ll_double_stack.tpp"

#endif

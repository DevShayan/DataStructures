#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <initializer_list>

template <typename T>
class ArrayStack {
    private:
        const static int lb = 0;

        T* stack = NULL;
        int numberOfElements = 0;
        int stackSize = 0;
		int top = -1;


    public:
        ArrayStack();
        ArrayStack(int size);
        ArrayStack(std::initializer_list<T> list);
        ArrayStack(int size, std::initializer_list<T> list);
        void push(T value);
        T pop();

        // Getters and Setters
        void setStack(int size);
        void setStack(std::initializer_list<T> list);
        void setStack(int size, std::initializer_list<T> list);
        int getElementCount();
        T getElementAtTop();
        int getSize();
        std::string getStackAsString();

        // Misc
        void clearStack();
        void deleteStack();
};

#include "../src/array_stack.tpp"

#endif
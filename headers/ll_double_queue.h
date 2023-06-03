#ifndef LL_DOUBLE_QUEUE_H
#define LL_DOUBLE_QUEUE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLDoubleQue {
    private:
    
        struct Node {
            T data;
            Node* next;
			Node* prev;
        };
        Node* front = NULL;
        Node* rear = NULL;
        int numberOfElements = 0;

    public:
        LLDoubleQue();
        LLDoubleQue(std::initializer_list<T> list);
        void enQueue(T data);
        T deQueue();
        void deleteQueue();

        // Getters and Setters
        void setQueue(std::initializer_list<T> list);
        std::string getQueueAsString();
        int getElementCount();
};

#include "../src/ll_double_queue.tpp"

#endif

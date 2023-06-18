#ifndef QUE_H
#define QUE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLQueue {
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* front = NULL;
        Node* rear = NULL;
        int numberOfElements = 0;

    public:
        LLQueue();
        LLQueue(std::initializer_list<T> list);
        void enQueue(T data);
        T deQueue();
        void deleteQueue();

        // Getters and setters
        void setQueue(std::initializer_list<T> list);
        std::string getQueueAsString();
        int getElementCount();
};

#include "../src/ll_queue.tpp"

#endif
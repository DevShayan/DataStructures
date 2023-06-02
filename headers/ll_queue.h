#ifndef QUE_H
#define QUE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class LLQueue {
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node* head = NULL;
        Node* tail = NULL;
        int numberOfElements = 0;

    public:
        LLQueue();
        LLQueue(std::initializer_list<T> list);
        void enQueue(int data);
        T deQueue();
        void deleteQueue();

        // Getters and setters
        void setQueue(std::initializer_list<T> list);
        std::string getQueueAsString();
        int getElementCount();
};

#include "../src/ll_queue.tpp"

#endif
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class ArrayQueue {
    private:
        const static int lb = 0;

        T* queue = NULL;
        int numberOfElements = 0;
        int queueSize = 0;
		int front = -1;
		int rear = -1;

        void deleteQueue();

    public:
        ArrayQueue();
        ArrayQueue(int size);
        ArrayQueue(std::initializer_list<T> list);
        ArrayQueue(int size, std::initializer_list<T> list);
        void push(T value);
        T pop();

        // Getters and Setters
        void setQueue(int size);
        void setQueue(std::initializer_list<T> list);
        void setQueue(int size, std::initializer_list<T> list);
        int getElementCount();
        T getElementAtFront();
        T getElementAtBack();
        int getSize();
        std::string getQueueAsString();

        // Misc
        void clearQueue();
};

#include "../src/array_queue.tpp"

#endif
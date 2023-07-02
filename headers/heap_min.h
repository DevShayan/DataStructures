#ifndef HEAP_MIN_H
#define HEAP_MIN_H

#include <iostream>
#include <initializer_list>
#include <math.h>
#include <vector>

template <typename T>
class HeapMin {
    private:
        std::vector<T> heapMin;

        void balanceUpward(int leafIndex);
        void balanceDownward(int rootIndex);
        int getParentIndex(int index);
        int getLeftChildIndex(int index);
        int getRightChildIndex(int index);
        bool isLeaf(int index);

    public:
        HeapMin();
        HeapMin(std::initializer_list<T> list);
        void insert(T data);
        T removeMin();
        void deleteHeap();
        int singleSearchFor(T data);
        int multiSearchFor(T data);

        // getters and setters
        void setHeap(std::initializer_list<T> list);
        std::string getHeapAsString();
        int getSize();
        int getMinValue();

};

#include "../src/heap_min.tpp"

#endif
#ifndef ARRAY_SIMPLE_H
#define ARRAY_SIMPLE_H

#include <iostream>
#include <initializer_list>

template <typename T>
class ArraySimple {
    private:
        const static int lb = 0;

        T* arr = NULL;
        int numberOfElements = 0;
        int arraySize = 0;

        void deleteArray();
        void mergeSort_recursive(int low, int high);
        void merge(int low, int mid, int high);
        int partition(int low, int high);
        void quickSort_recursive(int low, int high);

    public:
        ArraySimple();
        ArraySimple(int size);
        ArraySimple(std::initializer_list<T> list);
        ArraySimple(int size, std::initializer_list<T> list);
        void push(T value, int index);
        T pop(int index);
        int singleLinearSearch(T value);
        int multiLinearSearch(T value);
        int singleBinarySearch(T value);
        int multiBinarySearch(T value);
        void bubbleSort(bool sortAscending);
        void selectionSort(bool sortAscending);
        void insertionSort(bool sortAscending);
        void shellSort(bool sortAscending);
        void mergeTwoArrays(ArraySimple arrA, ArraySimple arrB, bool sortAscending);
        void mergeSort(bool sortAscending);
        void quickSort(bool sortAscending);

        // Getters and Setters
        void setArray(int size);
        void setArray(std::initializer_list<T> list);
        void setArray(int size, std::initializer_list<T> list);
        int getElementCount();
        int getElementAt(int index);
        int getSize();
        std::string getArrayAsString();

        // Misc
        void clearArray();
};

#include "../src/array_simple.tpp"

#endif
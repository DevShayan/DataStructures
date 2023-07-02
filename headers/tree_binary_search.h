#ifndef TREE_BINARY_SEARCH_H
#define TREE_BINARY_SEARCH_H

#include <iostream>
#include <initializer_list>
#include <math.h>
#include "ll_queue.h"

template <typename T>
class TreeBinarySearch {
    private:
        struct Node {
            T data;
            Node* left;
            Node* right;
        };
        int numberOfElements = 0;
        Node* root = NULL;

        void insertRecurrsive(Node* ptr, Node* n, T data);
        void inOrderTraversal(Node* ptr, std::string& treeAsString);
        void preOrderTraversal(Node* ptr, std::string& treeAsString);
        void postOrderTraversal(Node* ptr, std::string& treeAsString);
        std::string breadthFirstTraversal(std::string& treeAsString);

        void print2DTree(Node* ptr, int spaces);
        void deleteTreeRec(Node* ptr);
        Node* removeRec(Node* ptr, T data);
        Node* getMinNode(Node* ptr);
        bool singleSearch(Node* ptr, T data);

    public:
        static const int IN_ORDER = 0;
        static const int PRE_ORDER = 1;
        static const int POST_ORDER = 2;
        static const int BREADTH_FIRST = 3;
        
        TreeBinarySearch();
        TreeBinarySearch(std::initializer_list<T> list);
        void insert(T data);
        T remove(T data);
        void deleteTree();
        bool singleSearchFor(T data);

        // getters and setters
        void setTree(std::initializer_list<T> list);
        std::string getTreeAsString(int order);
        int getElementCount();
        int getMaxWidth();
        int getMinValue();

};

#include "../src/tree_binary_search.tpp"

#endif
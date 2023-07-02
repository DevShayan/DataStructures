/*
This is a temporary file and must be removed in future.
*/

#ifndef TREE_BINARY_H
#define TREE_BINARY_H

#include <iostream>
#include <initializer_list>
#include <math.h>
#include "ll_queue.h"

template <typename T>
class TreeBinary {
    private:
        struct Node {
            T data;
            Node* left;
            Node* right;
        };
        int numberOfElements = 0;
        Node* root = NULL;

        void createTreeRec(Node* ptr);
        void inOrderTraversal(Node* ptr, std::string& treeAsString);
        void preOrderTraversal(Node* ptr, std::string& treeAsString);
        void postOrderTraversal(Node* ptr, std::string& treeAsString);
        std::string breadthFirstTraversal(std::string& treeAsString);

        void deleteTreeRec(Node* ptr);
        Node* removeRec(Node* ptr, T data);
        Node* getMinNode(Node* ptr);
        int getHeightOfNode(Node* ptr);
        bool singleSearch(Node* ptr, T data);

    public:
        static const int IN_ORDER = 0;
        static const int PRE_ORDER = 1;
        static const int POST_ORDER = 2;
        static const int BREADTH_FIRST = 3;
        
        TreeBinary();
        void createTree();
        T remove(T data);
        void deleteTree();
        bool singleSearchFor(T data);

        // getters and setters
        std::string getTreeAsString(int order);
        int getElementCount();
        int getMaxWidth();
        int getMinValue();
        int getHeight();

};

#include "../src/tree_binary.tpp"

#endif
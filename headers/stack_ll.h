#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>

class StackLL {
    public:
      
        struct Node {
            int data;
            Node* next;
        };
        Node* head;
        Node* tail;
        Node* tmp;

        StackLL();
        void pushNode(int data);
        void popNode();
        void printStack();
};




#endif
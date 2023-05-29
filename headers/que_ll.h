#ifndef QUE_H
#define QUE_H

#include <iostream>

class QueLL {

    public:
        struct Node {
            int data;
            Node* next;
        };
        Node* head = NULL;
        Node* tail = NULL;
        Node* tmp = NULL;
        Node* del = NULL;

        QueLL();
        void pushNode(int data);
        void popNode();
        void printQue();
};




#endif
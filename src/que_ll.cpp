#include "../headers/que_ll.h"

QueLL::QueLL() {
    //
}

void QueLL::pushNode(int data) {

    
    Node* n = new Node();
    n->data = data;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        tail = n;
    }
    else {
        tail->next = n;
        tail = n;
    }

    n = NULL;
    delete n;
}

void QueLL::popNode() {
    del = head;

    if (head == NULL) {
        std::cout << "Cannot pop from empty que!";
    }
    else if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
        del->next = NULL;
    }
    delete del;
    del = NULL;
}

void QueLL::printQue() {
    if (head == NULL) {
        std::cout << "Que is empty.\n";
        return;
    }

    tmp = head;

    while (tmp != NULL) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}


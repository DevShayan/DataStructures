#include "../headers/stack_ll.h"

StackLL::StackLL() {
    //
}

void StackLL::pushNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;

    if (start == NULL) {
        start = n;
        tail = n;
    }
    else {
        tail->next = n;
        tail = tail->next;
    }

    n = NULL;
    delete n;
}

void StackLL::popNode() {
    if (head == NULL) {
        std::cout << "Cannot pop from empty stack!";
    }
    else {
        Node* del = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
            delete del;
        }
        else {

            while (del->next != tail) {
                del = del->next;
            }

            tail = del;
            del = del->next;
            tail->next = NULL;
            delete del;
        }
    }
}

void StackLL::printStack() {
    tmp = head;
    while (tmp != NULL) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}




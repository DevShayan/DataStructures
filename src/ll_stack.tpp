#include "../headers/ll_stack.h"

template <typename T>
LLStack<T>::LLStack() {
    //
}

template <typename T>
LLStack<T>::LLStack(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template <typename T>
void LLStack<T>::push(T data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;

    if (head == NULL) {
        head = tail = n;
    }
    else {
        tail->next = n;
        tail = tail->next;
    }

    numberOfElements++;
}

template <typename T>
T LLStack<T>::pop() {
    if (head == NULL) {
        throw "Cannot pop from empty stack!";
    }
    Node* del = head;
    T returnValue;

    if (head == tail) {
        head = NULL;
        tail = NULL;
        returnValue = del->data;
        delete del;
        return returnValue;
    }

    while (del->next != tail) {
        del = del->next;
    }

    tail = del;
    del = del->next;
    tail->next = NULL;
    returnValue = del->data;
    delete del;

    numberOfElements--;
    return returnValue;
}

template<typename T>
void LLStack<T>::deleteStack() {
	if (head == NULL)
		throw "Cannot delete empty list!";

	Node* tmp = head;
	while (tmp != NULL) {
		pop();
        tmp = head;
	}
	numberOfElements = 0;
}

// Getters and setters

template<typename T>
void LLStack<T>::setList(std::initializer_list<T> list) {
	deleteList();
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
std::string LLStack<T>::getStackAsString() {
	Node* tmp = head;
	std::string returnValue = "";

	if (head == NULL) {
		return "[ ]";
	}

	returnValue += "[";

	while (tmp != NULL) {
		if (tmp->next == NULL) {
			returnValue += std::to_string(tmp->data);
		}
		else
			returnValue += std::to_string(tmp->data)+", ";
		tmp = tmp->next;
	}
	
	return returnValue+"]";
}

template <typename T>
int LLStack<T>::getElementCount() {
    return numberOfElements;
}



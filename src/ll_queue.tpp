#include "../headers/ll_queue.h"

template <typename T>
LLQueue<T>::LLQueue() {
    //
}

template<typename T>
LLQueue<T>::LLQueue(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template <typename T>
void LLQueue<T>::enQueue(int data) {
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
    numberOfElements++;
}

template <typename T>
T LLQueue<T>::deQueue() {
    if (head == NULL) {
        throw "Cannot pop from empty que!";
    }

    T returnValue;
    Node* del = head;

    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
        del->next = NULL;
    }
    returnValue = del->data;
    delete del;

    numberOfElements--;
    return returnValue;
}

template<typename T>
void LLQueue<T>::deleteQueue() {
	if (head == NULL)
		throw "Cannot delete empty list!";

	Node* tmp = head;
	while (tmp != NULL) {
		deQueue();
		tmp = head;
	}
	numberOfElements = 0;
}

// Getters and setters

template<typename T>
void LLQueue<T>::setQueue(std::initializer_list<T> list) {
	deleteQueue();
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
std::string LLQueue<T>::getQueueAsString() {
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

template<typename T>
int LLQueue<T>::getElementCount() {
	return numberOfElements;
}
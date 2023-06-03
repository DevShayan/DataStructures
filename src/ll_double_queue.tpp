#ifndef LL_DOUBLE_QUEUE_TPP
#define LL_DOUBLE_QUEUE_TPP

template <typename T>
LLDoubleQue<T>::LLDoubleQue() {
    //
}

template<typename T>
LLDoubleQue<T>::LLDoubleQue(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		enQueue(element);
	}
}

template <typename T>
void LLDoubleQue<T>::enQueue(T data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
	n->prev = NULL;

    if (front == NULL) {
        front = rear = n;
    }
    else {
        rear->next = n;
		n->prev = rear;
        rear = n;
    }
    numberOfElements++;
}

template <typename T>
T LLDoubleQue<T>::deQueue() {
    if (front == NULL)
        throw "Cannot dequeue from empty queue!";

    Node* del = front;

    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
		front->prev = NULL;
    }

    T returnValue = del->data;
    delete del;

    numberOfElements--;
    return returnValue;
}

template<typename T>
void LLDoubleQue<T>::deleteQueue() {
	if (front == NULL)
		throw "Cannot delete empty queue!";

	Node* tmp = front;
	while (tmp != NULL) {
		deQueue();
		tmp = front;
	}
	numberOfElements = 0;
}

// Getters and setters

template<typename T>
void LLDoubleQue<T>::setQueue(std::initializer_list<T> list) {
	deleteQueue();
	numberOfElements = list.size();
	for (const auto& element : list) {
		enQueue(element);
	}
}

template<typename T>
std::string LLDoubleQue<T>::getQueueAsString() {
	Node* tmp = front;
	std::string returnValue = "";

	if (front == NULL) {
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
int LLDoubleQue<T>::getElementCount() {
	return numberOfElements;
}


#endif
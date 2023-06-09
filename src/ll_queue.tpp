#ifndef LL_QUEUE_TPP
#define LL_QUEUE_TPP

template <typename T>
LLQueue<T>::LLQueue() {
    //
}

template<typename T>
LLQueue<T>::LLQueue(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		enQueue(element);
	}
}

template <typename T>
void LLQueue<T>::enQueue(T data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;

    if (front == NULL) {
        front = rear = n;
    }
    else {
        rear->next = n;
        rear = n;
    }
    numberOfElements++;
}

template <typename T>
T LLQueue<T>::deQueue() {
    if (front == NULL)
        throw "Cannot dequeue from empty queue!";

    Node* del = front;

    if (front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }

    T returnValue = del->data;
    delete del;

    numberOfElements--;
    return returnValue;
}

template<typename T>
void LLQueue<T>::deleteQueue() {
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
void LLQueue<T>::setQueue(std::initializer_list<T> list) {
	deleteQueue();
	numberOfElements = list.size();
	for (const auto& element : list) {
		enQueue(element);
	}
}

template<typename T>
std::string LLQueue<T>::getQueueAsString() {
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
int LLQueue<T>::getElementCount() {
	return numberOfElements;
}


#endif
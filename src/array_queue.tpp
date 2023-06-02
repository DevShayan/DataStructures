#ifndef ARRAY_QUEUE_TPP
#define ARRAY_QUEUE_TPP

template <typename T>
ArrayQueue<T>::ArrayQueue() {
	//
}


template <typename T>
ArrayQueue<T>::ArrayQueue(int size) {
    numberOfElements = 0;
    queueSize = size;
    queue = new T[queueSize];

}


template <typename T>
ArrayQueue<T>::ArrayQueue(std::initializer_list<T> list) {
    queueSize = numberOfElements = list.size();
    queue = new T[queueSize];

    int index = 0;
    for (T x : list) {
        queue[index] = x;
        index++;
    }
	front = lb;
	rear = numberOfElements-1;
}


template <typename T>
ArrayQueue<T>::ArrayQueue(int size, std::initializer_list<T> list) {
    numberOfElements = list.size();
    queueSize = size;

    if (numberOfElements > queueSize) {
        throw "number of elements exeeded the size of queue!";
    }

    queue = new T[queueSize];
    int index = 0;

    for (T x : list) {
        queue[index] = x;
        index++;
    }
	front = lb;
	rear = numberOfElements-1;
}


template <typename T>
void ArrayQueue<T>::enQueue(T value) {
    if ((rear+1)%queueSize == front) {
        throw "Cannot insert in full queue!";
    }

	if (front == -1)
		front = rear = lb;
	else
		rear = (rear+1)%queueSize;

	queue[rear] = value;
    numberOfElements++;

}


template <typename T>
T ArrayQueue<T>::deQueue() {
    if (front == -1) {
        throw "Cannot delete from empty queue!";
    }

    T returnValue = queue[front];

	if (front == rear) {
		front = rear = -1;
	} else {
		front = (front+1)%queueSize;
	}

    numberOfElements--;
    return returnValue;
}

// Getters and Setters

template <typename T>
void ArrayQueue<T>::setQueue(int size) {
    if (queue != NULL) deleteQueue();

    numberOfElements = 0;
    queueSize = size;
    
    queue = new T[queueSize];
	front = rear = -1;
}

template <typename T>
void ArrayQueue<T>::setQueue(std::initializer_list<T> list) {
    if (queue != NULL) deleteQueue();

    queueSize = numberOfElements = list.size();
    
    queue = new T[queueSize];
    int index = 0;

    for (T x : list) {
        queue[index] = x;
        index++;
    }
	front = lb;
	rear = numberOfElements-1;
}

template <typename T>
void ArrayQueue<T>::setQueue(int size, std::initializer_list<T> list) {
    if (queue != NULL) deleteQueue();

    numberOfElements = list.size();
    queueSize = size;

    if (numberOfElements > queueSize) {
        throw "number of elements should not exeed the size of queue!";
    }
    
    queue = new T[queueSize];
    int index = 0;

    for (T x : list) {
        queue[index] = x;
        index++;
    }
	front = lb;
	rear = numberOfElements-1;
}

template <typename T>
int ArrayQueue<T>::getElementCount() {
    return numberOfElements;
}

template <typename T>
T ArrayQueue<T>::getElementAtFront() {
    if (front == -1) {
		throw "Queue is empty.";
	}

	return queue[front];
}

template <typename T>
T ArrayQueue<T>::getElementAtBack() {
    if (front == -1) {
		throw "Queue is empty.";
	}

	return queue[rear];
}

template <typename T>
int ArrayQueue<T>::getSize() {
    return queueSize;
}

template <typename T>
std::string ArrayQueue<T>::getQueueAsString() {

    if (front == -1) {
        return "[ ]";
    }
	
    std::string returnValue = "";

	int loopCount = numberOfElements;
    for (int x=front; loopCount > 0; x = (x+1)%queueSize, loopCount--) {
        if (x == front) {
            returnValue += "[ ";
        }

        if (x == rear) {
            returnValue += std::to_string(queue[x])+" ]";
        } else {
            returnValue += std::to_string(queue[x])+", ";
        }
    }
    return returnValue;
}

// Misc

template <typename T>
void ArrayQueue<T>::deleteQueue() {
    delete queue;
    queue = NULL;
    numberOfElements = 0;
    queueSize = 0;
}

template <typename T>
void ArrayQueue<T>::clearQueue() {
    numberOfElements = 0;
    front = rear = -1;
}


#endif

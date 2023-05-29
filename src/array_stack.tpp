#ifndef ARRAY_STACK_TPP
#define ARRAY_STACK_TPP

template <typename T>
ArrayStack<T>::ArrayStack() {
	//
}


template <typename T>
ArrayStack<T>::ArrayStack(int size) {
    numberOfElements = 0;
    stackSize = size;
    stack = new T[stackSize];

}


template <typename T>
ArrayStack<T>::ArrayStack(std::initializer_list<T> list) {
    stackSize = numberOfElements = list.size();
    stack = new T[stackSize];

    int index = 0;
    for (T x : list) {
        stack[index] = x;
        index++;
    }
	top = numberOfElements+lb-1;
}


template <typename T>
ArrayStack<T>::ArrayStack(int size, std::initializer_list<T> list) {
    numberOfElements = list.size();
    stackSize = size;

    if (numberOfElements > stackSize) {
        throw "number of elements exeeded the size of stack!";
    }

    stack = new T[stackSize];
    int index = 0;

    for (T x : list) {
        stack[index] = x;
        index++;
    }
	top = numberOfElements+lb-1;
}


template <typename T>
void ArrayStack<T>::push(T value) {
    if (top == stackSize+lb-1) {
        throw "Cannot push in full stack!";
    }

	stack[++top] = value;
    numberOfElements++;

}


template <typename T>
T ArrayStack<T>::pop() {
    if (top == lb-1) {
        throw "Cannot delete from empty stack!";
    }

    return stack[top--];
}

// Getters and Setters

template <typename T>
void ArrayStack<T>::setStack(int size) {
    if (stack != NULL) deleteStack();

    numberOfElements = 0;
    stackSize = size;
    
    stack = new T[stackSize];
	top = -1;
}

template <typename T>
void ArrayStack<T>::setStack(std::initializer_list<T> list) {
    if (stack != NULL) deleteStack();

    stackSize = numberOfElements = list.size();
    
    stack = new T[stackSize];
    int index = 0;

    for (T x : list) {
        stack[index] = x;
        index++;
    }
	top = numberOfElements-1;
}

template <typename T>
void ArrayStack<T>::setStack(int size, std::initializer_list<T> list) {
    if (stack != NULL) deleteStack();

    numberOfElements = list.size();
    stackSize = size;

    if (numberOfElements > stackSize) {
        throw "number of elements should not exeed the size of array!";
    }
    
    stack = new T[stackSize];
    int index = 0;

    for (T x : list) {
        stack[index] = x;
        index++;
    }
	top = numberOfElements-1;
}

template <typename T>
int ArrayStack<T>::getElementCount() {
    return numberOfElements;
}

template <typename T>
T ArrayStack<T>::getElementAtTop() {
    if (top == -1) {
		throw "Stack is empty.";
	}

	return stack[top];
}

template <typename T>
int ArrayStack<T>::getSize() {
    return stackSize;
}

template <typename T>
std::string ArrayStack<T>::getStackAsString() {

    if (top == -1) {
        return "[ ]";
    }
	
    std::string returnValue = "";

    for (int x=lb; x <= top; x++) {
        if (x == lb) {
            returnValue += "[ ";
        }

        if (x == top) {
            returnValue += std::to_string(stack[x])+" ]";
        } else {
            returnValue += std::to_string(stack[x])+", ";
        }
    }
    return returnValue;
}

// Misc

template <typename T>
void ArrayStack<T>::deleteStack() {
    delete stack;
    stack = NULL;
    numberOfElements = 0;
    stackSize = 0;
}

template <typename T>
void ArrayStack<T>::clearStack() {
    numberOfElements = 0;
	top = -1;
}


#endif

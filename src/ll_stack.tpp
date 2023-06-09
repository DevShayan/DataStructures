#ifndef LL_STACK_TPP
#define LL_STACK_TPP

template <typename T>
LLStack<T>::LLStack() {
    //
}

template <typename T>
LLStack<T>::LLStack(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		push(element);
	}
}

template <typename T>
void LLStack<T>::push(T data) {
    Node* n = new Node();
    n->data = data;
    n->next = top;

    top = n;
    numberOfElements++;
}

template <typename T>
T LLStack<T>::pop() {
    if (top == NULL)
        throw "Cannot pop from empty stack!";

    Node* del = top;

    top = top->next;
    T returnValue = del->data;
    delete del;

    numberOfElements--;
    return returnValue;
}

template<typename T>
void LLStack<T>::deleteStack() {
	if (top == NULL)
		throw "Cannot delete empty list!";

	Node* tmp = top;
	while (tmp != NULL) {
		pop();
        tmp = top;
	}
	numberOfElements = 0;
}

// Getters and setters

template<typename T>
void LLStack<T>::setList(std::initializer_list<T> list) {
	deleteStack();
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
std::string LLStack<T>::getStackAsString() {
	Node* tmp = top;
	std::string returnValue = "";

	if (top == NULL) {
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

#endif

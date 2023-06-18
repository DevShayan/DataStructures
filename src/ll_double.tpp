#ifndef LL_DOUBLE_TPP
#define LL_DOUBLE_TPP

template<typename T>
LLDouble<T>::LLDouble() {
	//
}

template<typename T>
LLDouble<T>::LLDouble(std::initializer_list<T> list) {
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
void LLDouble<T>::insertAtFirst(T data) {
	Node* n = new Node();
	n->data = data;
	n->next = head;
	n->prev = NULL;

	if (head != NULL) {
		head->prev = n;
	}
	head = n;
	numberOfElements++;
}

template<typename T>
void LLDouble<T>::insertAtLast(T data) {
	Node* n = new Node();
	n->data = data;
	n->next = NULL;
	n->prev = NULL;

	if (head == NULL) {
		head = n;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		n->prev = tmp;
		tmp->next = n;
	}
	numberOfElements++;
}

template<typename T>
void LLDouble<T>::insertAfter(T node, T data) {
	Node* tmp = head;

	while (tmp != NULL && tmp->data != node)
		tmp = tmp->next;

	if (tmp == NULL)
		throw "Node not found in linked list!";

	insertAfter(tmp, data);

}

template<typename T>
void LLDouble<T>::insertBefore(T node, T data) {
	if (head == NULL)
		throw "List is empty.";

	if (head->data == node) {
		insertAtFirst(data);
		return;
	}

	Node* tmp = head;
	while (tmp->next != NULL && tmp->next->data != node) {
		tmp = tmp->next;
	}

	if (tmp->next == NULL) 
		throw "Node not found in linked list!";

	insertAfter(tmp, data);
}

template<typename T>
T LLDouble<T>::deleteFirst() {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* del = head;
	head = head->next;

	T returnValue = del->data;
	delete del;

	numberOfElements--;
	return returnValue;
}

template<typename T>
T LLDouble<T>::deleteLast() {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* tmp = head;

	if (head->next == NULL)
		return deleteFirst();

	while (tmp->next->next != NULL)
		tmp = tmp->next;

	return deleteAfter(tmp);
}

template<typename T>
T LLDouble<T>::deleteAfter(T node) {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* tmp = head;
	while (tmp != NULL && tmp->data != node)
		tmp = tmp->next;

	if (tmp == NULL)
		throw "Node not found in list.";
	if (tmp->next == NULL)
		throw "Cannot delete after last node.";

	return deleteAfter(tmp);
}

template<typename T>
T LLDouble<T>::deleteBefore(T node) {
	if (head == NULL)
		throw "Cannot delete from empty list!";
	if (head->data == node)
		throw "Cannot delete before first node.";
	
	Node* tmp = head;

	if (tmp->next->data == node)
		return deleteFirst();

	while (tmp->next->next != NULL && tmp->next->next->data != node)
		tmp = tmp->next;

	if (tmp->next->next == NULL)
		throw "Node not found in list.";

	return deleteAfter(tmp);
}

template<typename T>
T LLDouble<T>::deleteMid() {
	if (head == NULL)
		throw "Cannot delete from empty list.s";

	if (head->next == NULL)
		return deleteFirst();

	Node* tmp = head;
	int count = 0;

	while (tmp != NULL) {
		count++;
		tmp = tmp->next;
	}

	tmp = head;
	int mid = (count/2)+1;

	for (int x=0; x<mid-2; x++)
		tmp = tmp->next;
		
	return deleteAfter(tmp);
}

template<typename T>
T LLDouble<T>::deleteNode(T node) {

	if (head == NULL)
		throw "Cannot delete from empty list.";

	Node* tmp = head;

	if (head->data == node) {
		return deleteFirst();
	}
	
	while (tmp->next != NULL && tmp->next->data != node) {
		tmp = tmp->next;
	}

	if (tmp->next == NULL)
		throw "Node not found in list.";

	return deleteAfter(tmp);
}

template<typename T>
void LLDouble<T>::deleteList() {
	if (head == NULL)
		throw "Cannot delete empty list!";

	Node* tmp = head;
	while (tmp != NULL) {
		deleteFirst();
		tmp = head;
	}
	numberOfElements = 0;
}

// Getters and Setters

template<typename T>
void LLDouble<T>::setList(std::initializer_list<T> list) {
	deleteList();
	numberOfElements = list.size();
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
std::string LLDouble<T>::getListAsString() {
	Node* tmp = head;
	std::string returnValue = "";

	if (head == NULL) {
		return "[ ]";
	}

	returnValue += "[ ";

	while (tmp != NULL) {
		if (tmp->next == NULL) {
			returnValue += std::to_string(tmp->data);
		}
		else
			returnValue += std::to_string(tmp->data)+", ";
		tmp = tmp->next;
	}

	return returnValue+" ]";
	
}

template<typename T>
int LLDouble<T>::getElementCount() {
	return numberOfElements;
}

// private

template<typename T>
void LLDouble<T>::insertAfter(Node* ptr, T data) {
	Node* n = new Node();
	n->data = data;

	n->next = ptr->next;
	n->prev = ptr;
	ptr->next = n;
	n->next->prev = n;
	numberOfElements++;
}

template<typename T>
T LLDouble<T>::deleteAfter(Node* ptr) {
	Node* del = ptr->next;
	ptr->next = ptr->next->next;
	if (ptr->next != NULL) {
		ptr->next->prev = ptr->next->prev->prev;
	}
	T returnValue = del->data;
	delete del;

	numberOfElements--;
	return returnValue;
}

#endif
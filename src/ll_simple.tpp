#ifndef LL_SIMPLE_TPP
#define LL_SIMPLE_TPP

template<typename T>
LLSimple<T>::LLSimple() {
	//
}

template<typename T>
LLSimple<T>::LLSimple(std::initializer_list<T> list) {
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
void LLSimple<T>::insertAtFirst(T data) {
	Node* n = new Node();
	n->data = data;
	n->next = NULL;

	if (head == NULL) {
		head = n;
	}
	else {
		n->next = head;
		head = n;
	}
}

template<typename T>
void LLSimple<T>::insertAtLast(T data) {
	Node* n = new Node();
	n->data = data;
	n->next = NULL;

	if (head == NULL) {
		head = n;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		tmp->next = n;
	}
}

template<typename T>
void LLSimple<T>::insertAfter(T node, T data) {
	Node* tmp = head;

	while (tmp != NULL && tmp->data != node)
		tmp = tmp->next;

	if (tmp == NULL)
		throw "Node not found in linked list!";

	insertAfter(tmp, data);

}

template<typename T>
void LLSimple<T>::insertBefore(T node, T data) {
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
T LLSimple<T>::deleteAtFirst() {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* del = head;
	head = head->next;

	T returnValue = del->data;
	delete del;
	return returnValue;
}

template<typename T>
T LLSimple<T>::deleteAtLast() {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* tmp = head;

	if (head->next == NULL)
		return deleteAtFirst();

	while (tmp->next->next != NULL)
		tmp = tmp->next;

	return deleteAfter(tmp);
}

template<typename T>
T LLSimple<T>::deleteAfter(T node) {
	if (head == NULL)
		throw "Cannot delete from empty list!";

	Node* tmp = head;
	while (tmp != NULL && tmp->data != node)
		tmp = tmp->next;

	if (tmp->next == NULL)
		throw "Cannot delete after last node.";
	if (tmp == NULL)
		throw "Node not found in list.";

	return deleteAfter(tmp);
}

template<typename T>
T LLSimple<T>::deleteBefore(T node) {
	if (head == NULL)
		throw "Cannot delete from empty list!";
	if (head->data == node)
		throw "Cannot delete before first node.";
	
	Node* tmp = head;

	if (tmp->next->data == node)
		return deleteAtFirst();

	while (tmp->next->next != NULL && tmp->next->next->data != node)
		tmp = tmp->next;

	if (tmp->next->next == NULL)
		throw "Node not found in list.";

	return deleteAfter(tmp);
}

template<typename T>
T LLSimple<T>::deleteMid() {
	if (head == NULL)
		throw "Cannot delete from empty list.s";

	if (head->next == NULL)
		return deleteAtFirst();

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
T LLSimple<T>::deleteNode(T node) {

	if (head == NULL)
		throw "Cannot delete from empty list.s";

	Node* tmp = head;

	if (head->data == node) {
		return deleteAtFirst();
	}
	
	while (tmp->next != NULL && tmp->next->data != node) {
		tmp = tmp->next;
	}

	if (tmp->next == NULL)
		throw "Node not found in list.";

	return deleteAfter(tmp);
}

// Getters and Setters

template<typename T>
void LLSimple<T>::setList(std::initializer_list<T> list) {
	for (const auto& element : list) {
		insertAtLast(element);
	}
}

template<typename T>
std::string LLSimple<T>::getListAsString() {
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

// private

template<typename T>
void LLSimple<T>::insertAfter(Node* ptr, T data) {
	Node* n = new Node();
	n->data = data;

	n->next = ptr->next;
	ptr->next = n;
}

template<typename T>
T LLSimple<T>::deleteAfter(Node* ptr) {
	Node* del = ptr->next;
	ptr->next = ptr->next->next;
	T returnValue = del->data;
	delete del;
	return returnValue;
}

#endif
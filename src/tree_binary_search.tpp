#ifndef TREE_BINARY_SEARCH_TPP
#define TREE_BINARY_SEARCH_TPP

template <typename T>
TreeBinarySearch<T>::TreeBinarySearch() {}

template <typename T>
TreeBinarySearch<T>::TreeBinarySearch(std::initializer_list<T> list) {
	for (const T& element : list) {
		insert(element);
	}
	numberOfElements = list.size();
}

template <typename T>
void TreeBinarySearch<T>::insert(T data) {
	Node* n = new Node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	if (root == NULL) {
		root = n;
		return;
	}

	insertRecurrsive(root, n, data);
	numberOfElements++;

}

template <typename T>
T TreeBinarySearch<T>::remove(T data) {
	removeRec(root, data);
	return data;
}


template <typename T>
void TreeBinarySearch<T>::deleteTree() {
	deleteTreeRec(root);
	root = NULL;
}

// Getters and Setters

template <typename T>
void TreeBinarySearch<T>::setTree(std::initializer_list<T> list) {
	deleteTree();
	for (const T& element : list) {
		insert(element);
	}
	numberOfElements = list.size();
}

template <typename T>
std::string TreeBinarySearch<T>::getTreeAsString(int order) {
	//┌ ┘ └ ┐ ─
	if (root == NULL) {
		return "[ ]";
	}

	std::string treeAsString = "[";
	if (order == TreeBinarySearch<T>::IN_ORDER) {
		inOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinarySearch<T>::PRE_ORDER) {
		preOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinarySearch<T>::POST_ORDER) {
		postOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinarySearch<T>::BREADTH_FIRST) {
		breadthFirstTraversal(treeAsString);
		return treeAsString;
	}
	else {
		throw "Invalid order! Expected 0, 1 or 2.";
	}
	
}

template <typename T>
int TreeBinarySearch<T>::getElementCount() {
	return numberOfElements;
}

template <typename T>
int TreeBinarySearch<T>::getMaxWidth() {
	if (root == NULL) return 0;

	int heightL = 0;
	int heightR = 0;

	Node* tmp = root;
	while (tmp->left != NULL) {
		heightL++;
		tmp = tmp->left;
	}

	tmp = root;
	while (tmp->right != NULL) {
		heightR++;
		tmp = tmp->right;
	}

	if (heightL > heightR) {
		return pow(2, heightR);
	} else {
		return pow(2, heightL);
	}
	
}

template <typename T>
int TreeBinarySearch<T>::getMinValue() {
	Node* tmp = getMinNode(root);
	return tmp->data;
}

// private

template <typename T>
void TreeBinarySearch<T>::insertRecurrsive(Node* ptr, Node* n, T data) {
	if (data < ptr->data) {
		if (ptr->left != NULL)
			insertRecurrsive(ptr->left, n, data);
		else
			ptr->left = n;
	}
	else {
		if (ptr->right != NULL)
			insertRecurrsive(ptr->right, n, data);
		else
			ptr->right = n;
	}
}

template <typename T>
void TreeBinarySearch<T>::inOrderTraversal(Node* ptr, std::string& treeAsString) {
	if (ptr->left != NULL) {
		inOrderTraversal(ptr->left, treeAsString);
	}
	treeAsString += std::to_string(ptr->data) + ", ";
	if (ptr->right != NULL) {
		inOrderTraversal(ptr->right, treeAsString);
	}
}

template <typename T>
void TreeBinarySearch<T>::preOrderTraversal(Node* ptr, std::string& treeAsString) {
	treeAsString += std::to_string(ptr->data) + ", ";
	if (ptr->left != NULL) {
		preOrderTraversal(ptr->left, treeAsString);
	}
	if (ptr->right != NULL) {
		preOrderTraversal(ptr->right, treeAsString);
	}
}

template <typename T>
void TreeBinarySearch<T>::postOrderTraversal(Node* ptr, std::string& treeAsString) {
	if (ptr->left != NULL) {
		postOrderTraversal(ptr->left, treeAsString);
	}
	if (ptr->right != NULL) {
		postOrderTraversal(ptr->right, treeAsString);
	}
	treeAsString += std::to_string(ptr->data) + ", ";
}

template <typename T>
std::string TreeBinarySearch<T>::breadthFirstTraversal(std::string& treeAsString) {
	LLQueue<Node*> que;
	LLQueue<T> results;
	Node* removed;

	que.enQueue(root);
	
	while (que.getElementCount() > 0) {
		removed = que.deQueue();
		results.enQueue(removed->data);
		
		if (removed->left != NULL)
			que.enQueue(removed->left);
		if (removed->right != NULL)
			que.enQueue(removed->right);
	}

	treeAsString = results.getQueueAsString();
	return treeAsString;
}

template <typename T>
void TreeBinarySearch<T>::deleteTreeRec(Node* ptr) {
	if (ptr == NULL) return;
	
	deleteTreeRec(ptr->left);
	deleteTreeRec(ptr->right);

	delete ptr;
	numberOfElements--;
}

template <typename T>
typename TreeBinarySearch<T>::Node* TreeBinarySearch<T>::removeRec(Node* ptr, T data) {
	// some problem in this function
	if (ptr == NULL)
		return NULL;

	if (data < ptr->data) {
		ptr->left = removeRec(ptr->left, data);
		return ptr;
	}
	else if (data > ptr->data){
		ptr->right = removeRec(ptr->right, data);
		return ptr;
	}
	else if (ptr->right == NULL && ptr->left == NULL) {
		if (ptr == root)
			root = NULL;
		delete ptr;
		return NULL;
	}
	else if (ptr->right != NULL && ptr->left != NULL) {
		Node* min = getMinNode(ptr->right);
		ptr->data = min->data;
		ptr->right = removeRec(ptr->right, ptr->data);
		return ptr;
	}
	else {
		Node* child = (ptr->left != NULL) ? ptr->left : ptr->right;
		if (ptr == root)
			root = NULL;
		delete ptr;
		return child;
	}

}

template <typename T>
typename TreeBinarySearch<T>::Node* TreeBinarySearch<T>::getMinNode(Node* ptr) {
	Node* min = NULL;

	if (ptr->left != NULL) {
		min = getMinNode(ptr->left);
	}
	if (ptr->right != NULL) {
		min = getMinNode(ptr->right);
	}

	if (min == NULL) {
		return ptr;
	}
	else {
		return (ptr->data < min->data) ? ptr : min;
	}
}

#endif

/*

Example 1:
      5
 ┌───┘ └────┐
 2         11
  └─┐   ┌─┘  └──┐
    3   9      30
            ┌─┘
           13
             └──┐
               18

Example 2:
         5
    ┌───┘ └────┐
    2         11
 ┌─┘ └─┐   ┌─┘  └──┐
 1     3   9      30
               ┌─┘  
              13    
                └──┐
                  18

Example 3:
      5
    ┌┘ └─┐
    2   11


Special characters used: ┌ ┘ └ ┐ ─

*/
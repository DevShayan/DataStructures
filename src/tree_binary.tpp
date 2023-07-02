/*
This is a temporary file and must be removed in future.
*/

#ifndef TREE_BINARY_TPP
#define TREE_BINARY_TPP

template <typename T>
TreeBinary<T>::TreeBinary() {}


template <typename T>
void TreeBinary<T>::createTree() {
	root = new Node();
	createTreeRec(root);

}

template <typename T>
T TreeBinary<T>::remove(T data) {
	if (root == NULL)
		throw "Cannot delete from empty tree!";
	removeRec(root, data);
	return data;
}


template <typename T>
void TreeBinary<T>::deleteTree() {
	deleteTreeRec(root);
	root = NULL;
}

template <typename T>
bool TreeBinary<T>::singleSearchFor(T data) {
	return singleSearch(root, data);
}

template <typename T>
bool TreeBinary<T>::singleSearch(Node* ptr, T data) {
	if (ptr == NULL)
		return false;

	if (ptr->data == data)
		return true;

	return singleSearch(ptr->left, data) || singleSearch(ptr->right, data);
}

// Getters and Setters

template <typename T>
std::string TreeBinary<T>::getTreeAsString(int order) {
	//┌ ┘ └ ┐ ─
	if (root == NULL) {
		return "[ ]";
	}

	std::string treeAsString = "[";
	if (order == TreeBinary<T>::IN_ORDER) {
		inOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinary<T>::PRE_ORDER) {
		preOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinary<T>::POST_ORDER) {
		postOrderTraversal(root, treeAsString);
		return treeAsString.erase(treeAsString.size() - 2)+"]";
	}
	else if (order == TreeBinary<T>::BREADTH_FIRST) {
		breadthFirstTraversal(treeAsString);
		return treeAsString;
	}
	else {
		throw "Invalid order! Expected 0, 1 or 2.";
	}
	
}

template <typename T>
int TreeBinary<T>::getElementCount() {
	return numberOfElements;
}

template <typename T>
int TreeBinary<T>::getMaxWidth() {
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
int TreeBinary<T>::getMinValue() {
	Node* tmp = getMinNode(root);
	return tmp->data;
}

template <typename T>
int TreeBinary<T>::getHeight() {
	return getHeightOfNode(root);
}

// private

template <typename T>
void TreeBinary<T>::createTreeRec(Node* ptr) {
	int item;
	char opLeft, opRight;
	std::cout << "Enter value to insert in tree: ";
	std::cin >> item;

	ptr->data = item;

	std::cout << "Enter left child of " << ptr->data << "? <y/n> : ";
	std::cin >> opLeft;

	if (opLeft == 'y') {
		ptr->left = new Node();
		createTreeRec(ptr->left);
	}
	else {
		ptr->left == NULL;
	}

	std::cout << "Enter right child of " << ptr->data << "? <y/n> : ";
	std::cin >> opRight;

	if (opRight == 'y') {
		ptr->right = new Node();
		createTreeRec(ptr->right);
	}
	else {
		ptr->right == NULL;
	}
}

template <typename T>
void TreeBinary<T>::inOrderTraversal(Node* ptr, std::string& treeAsString) {
	if (ptr->left != NULL) {
		inOrderTraversal(ptr->left, treeAsString);
	}
	treeAsString += std::to_string(ptr->data) + ", ";
	if (ptr->right != NULL) {
		inOrderTraversal(ptr->right, treeAsString);
	}
}

template <typename T>
void TreeBinary<T>::preOrderTraversal(Node* ptr, std::string& treeAsString) {
	treeAsString += std::to_string(ptr->data) + ", ";
	if (ptr->left != NULL) {
		preOrderTraversal(ptr->left, treeAsString);
	}
	if (ptr->right != NULL) {
		preOrderTraversal(ptr->right, treeAsString);
	}
}

template <typename T>
void TreeBinary<T>::postOrderTraversal(Node* ptr, std::string& treeAsString) {
	if (ptr->left != NULL) {
		postOrderTraversal(ptr->left, treeAsString);
	}
	if (ptr->right != NULL) {
		postOrderTraversal(ptr->right, treeAsString);
	}
	treeAsString += std::to_string(ptr->data) + ", ";
}

template <typename T>
std::string TreeBinary<T>::breadthFirstTraversal(std::string& treeAsString) {
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
void TreeBinary<T>::deleteTreeRec(Node* ptr) {
	if (ptr == NULL) return;
	
	deleteTreeRec(ptr->left);
	deleteTreeRec(ptr->right);

	delete ptr;
	numberOfElements--;
}

template <typename T>
typename TreeBinary<T>::Node* TreeBinary<T>::removeRec(Node* ptr, T data) {
	if (ptr == NULL)
		return NULL;

	ptr->left = removeRec(ptr->left, data);
	ptr->right = removeRec(ptr->right, data);


	if (ptr->data == data) {
		if (ptr->right == NULL && ptr->left == NULL) {
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
			delete ptr;
			return child;
		}
	}
	else {
		return ptr;
	}
}

template <typename T>
typename TreeBinary<T>::Node* TreeBinary<T>::getMinNode(Node* ptr) {
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

template <typename T>
int TreeBinary<T>::getHeightOfNode(Node* ptr) {
	if (ptr == NULL)
		return 0;
	else if (ptr->left == NULL && ptr->right == NULL)
		return 1;

	return std::max(getHeightOfNode(ptr->left), getHeightOfNode(ptr->right)) + 1;
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
#ifndef TREE_BINARY_TPP
#define TREE_BINARY_TPP

// #define COUNT 10

template <typename T>
TreeBinary<T>::TreeBinary() {}

template <typename T>
TreeBinary<T>::TreeBinary(std::initializer_list<T> list) {
	for (const T& element : list) {
		insert(element);
	}
}

template <typename T>
void TreeBinary<T>::insert(T data) {
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

// template <typename T>
// T TreeBinary<T>::remove(T data) {
// 	Node* tmp = root;

// 	if (root == NULL)
// 		throw "Cannot delete empty list!";

// 	while (tmp != NULL) {
// 		deleteFirst();
// 		tmp = root;
// 	}
// 	numberOfElements = 0;
// }

// template <typename T>
// void TreeBinary<T>::print2DTree(Node* root, int space) {
//     // Base case
//     if (root == NULL)
//         return;

// 	int count = 10;
//     // Increase distance between levels
//     space += count;

//     // Process right child first
//     print2DTree(root->right, space);

//     // Print current node after space count
//     std::cout << std::endl;
//     for (int i = count; i < space; i++)
//         std::cout << " ";
//     std::cout << root->data << "\n";

//     // Process left child
//     print2DTree(root->left, space);
// }


// template <typename T>
// void TreeBinary<T>::print2D() {
//     // Pass initial space count as 0
//     print2DTree(root, 0);
// }

template <typename T>
void TreeBinary<T>::deleteTree() {
	deleteTreeRec(root);
	root = NULL;
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

// private

template <typename T>
void TreeBinary<T>::insertRecurrsive(Node* ptr, Node* n, T data) {
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

	que.enQueue(root);
	breadthFirstTraversalRec(que, results);

	treeAsString = results.getQueueAsString();
	return treeAsString;
}

template <typename T>
void TreeBinary<T>::breadthFirstTraversalRec(LLQueue<Node*>& que, LLQueue<T>& results) {
	if (que.getElementCount() == 0) return;

	Node* removed = que.deQueue();
	results.enQueue(removed->data);
	
	if (removed->left != NULL)
		que.enQueue(removed->left);
	if (removed->right != NULL)
		que.enQueue(removed->right);
	
	breadthFirstTraversalRec(que, results);
}

template <typename T>
void TreeBinary<T>::deleteTreeRec(Node* ptr) {
	if (ptr == NULL) return;
	
	deleteTreeRec(ptr->left);
	deleteTreeRec(ptr->right);

	delete ptr;
	numberOfElements--;
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
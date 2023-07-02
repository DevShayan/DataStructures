#ifndef HEAP_MIN_TPP
#define HEAP_MIN_TPP

template <typename T>
HeapMin<T>::HeapMin() {}

template <typename T>
HeapMin<T>::HeapMin(std::initializer_list<T> list) {
	for (const T& element : list) {
		heapMin.push_back(element);
		balanceUpward();
	}
}

template <typename T>
void HeapMin<T>::insert(T data) {
	heapMin.push_back(data);
	balanceUpward(heapMin.size() - 1);
}

template <typename T>
T HeapMin<T>::removeMin() {
	if (heapMin.size() < 1)
		throw "Cannot delete from empty Heap!";
	
	T returnValue = heapMin[0];
	heapMin[0] = heapMin.back();
	heapMin.pop_back();

	balanceDownward(0);
	return returnValue;
}

template <typename T>
void HeapMin<T>::deleteHeap() {
	heapMin.clear();
}

template <typename T>
int HeapMin<T>::singleSearchFor(T data) {
	for (int x=0; x<getSize(); x++) {
		if (heapMin[x] == data) {
			return x;
		}
	}
	return -1;
}

template <typename T>
int HeapMin<T>::multiSearchFor(T data) {
	int count = 0;

	for (int x=0; x<getSize(); x++) {
		if (heapMin[x] == data) {
			count++;
		}
	}
	return count;
}

// Getters and Setters

template <typename T>
void HeapMin<T>::setHeap(std::initializer_list<T> list) {
	deleteHeap();
	for (const T& element : list) {
		heapMin.push_back(element);
		balanceUpward();
	}
}

template <typename T>
std::string HeapMin<T>::getHeapAsString() {
    if (getSize() == 0) return "[ ]";

    std::string returnValue = "";

	for (int x=0; x<getSize(); x++) {
		if (x == 0) {
			returnValue += "[ ";
		}
		
		if (x == getSize()-1) {
			returnValue += std::to_string(heapMin[x])+" ]";
		}
		else {
			returnValue += std::to_string(heapMin[x])+", ";
		}
	}
    return returnValue;
}

template <typename T>
int HeapMin<T>::getSize() {
	return heapMin.size();
}

template <typename T>
int HeapMin<T>::getMinValue() {
	if (heapMin.size() < 1)
		throw "Heap is empty!";

	return heapMin[0];
}

// Private

template <typename T>
void HeapMin<T>::balanceUpward(int leafIndex) {
	if (leafIndex == 0) return;

	int parentIndex = getParentIndex(leafIndex);

	if (heapMin[parentIndex] < heapMin[leafIndex])
		return;

	T tmp = heapMin[parentIndex];
	heapMin[parentIndex] = heapMin[leafIndex];
	heapMin[leafIndex] = tmp;

	balanceUpward(parentIndex);
}

template <typename T>
void HeapMin<T>::balanceDownward(int rootIndex) {
	if (getSize() < 1) return;

	int leftCIndex = getLeftChildIndex(rootIndex);
	int rightCIndex = getRightChildIndex(rootIndex);
	int smallestIndex = rootIndex;

	if (leftCIndex < getSize() && heapMin[leftCIndex] < heapMin[smallestIndex])
		smallestIndex = leftCIndex;

	if (rightCIndex < getSize() && heapMin[rightCIndex] < heapMin[smallestIndex])
		smallestIndex = rightCIndex;

	if (smallestIndex == rootIndex) return;

	T tmp = heapMin[rootIndex];
	heapMin[rootIndex] = heapMin[smallestIndex];
	heapMin[smallestIndex] = tmp;

	balanceDownward(smallestIndex);

}

template <typename T>
int HeapMin<T>::getParentIndex(int index) {
	return (index-1)/2;
}

template <typename T>
int HeapMin<T>::getLeftChildIndex(int index) {
	return (index*2)+1;
}

template <typename T>
int HeapMin<T>::getRightChildIndex(int index) {
	return (index*2)+2;
}

template <typename T>
bool HeapMin<T>::isLeaf(int index) {
	return index >= (heapMin.size()/2);
}





#endif

#ifndef HEAP_MAX_TPP
#define HEAP_MAX_TPP

template <typename T>
HeapMax<T>::HeapMax() {}

template <typename T>
HeapMax<T>::HeapMax(std::initializer_list<T> list) {
	for (const T& element : list) {
		heapMax.push_back(element);
		balanceUpward();
	}
}

template <typename T>
void HeapMax<T>::insert(T data) {
	heapMax.push_back(data);
	balanceUpward(heapMax.size() - 1);
}

template <typename T>
T HeapMax<T>::removeMin() {
	if (heapMax.size() < 1)
		throw "Cannot delete from empty Heap!";
	
	T returnValue = heapMax[0];
	heapMax[0] = heapMax.back();
	heapMax.pop_back();

	balanceDownward(0);
	return returnValue;
}

template <typename T>
void HeapMax<T>::deleteHeap() {
	heapMax.clear();
}

template <typename T>
int HeapMax<T>::singleSearchFor(T data) {
	for (int x=0; x<getSize(); x++) {
		if (heapMax[x] == data) {
			return x;
		}
	}
	return -1;
}

template <typename T>
int HeapMax<T>::multiSearchFor(T data) {
	int count = 0;

	for (int x=0; x<getSize(); x++) {
		if (heapMax[x] == data) {
			count++;
		}
	}
	return count;
}

// Getters and Setters

template <typename T>
void HeapMax<T>::setHeap(std::initializer_list<T> list) {
	deleteHeap();
	for (const T& element : list) {
		heapMax.push_back(element);
		balanceUpward();
	}
}

template <typename T>
std::string HeapMax<T>::getHeapAsString() {
    if (getSize() == 0) return "[ ]";

    std::string returnValue = "";

    for (int x=0; x<getSize(); x++) {
        if (x == 0) {
            returnValue += "[ ";
        }
        
        if (x == getSize()-1) {
            returnValue += std::to_string(heapMax[x])+" ]";
        }
        else {
            returnValue += std::to_string(heapMax[x])+", ";
        }
    }
    return returnValue;
}

template <typename T>
int HeapMax<T>::getSize() {
	return heapMax.size();
}

template <typename T>
int HeapMax<T>::getMinValue() {
	if (heapMax.size() < 1)
		throw "Heap is empty!";

	return heapMax[0];
}

// Private

template <typename T>
void HeapMax<T>::balanceUpward(int leafIndex) {
	if (leafIndex == 0) return;
	
	int parentIndex = getParentIndex(leafIndex);

	if (heapMax[parentIndex] > heapMax[leafIndex])
		return;

	T tmp = heapMax[parentIndex];
	heapMax[parentIndex] = heapMax[leafIndex];
	heapMax[leafIndex] = tmp;

	balanceUpward(parentIndex);
}

template <typename T>
void HeapMax<T>::balanceDownward(int rootIndex) {
	if (getSize() < 1) return;

	int leftCIndex = getLeftChildIndex(rootIndex);
	int rightCIndex = getRightChildIndex(rootIndex);
	int largestIndex = rootIndex;

	if (leftCIndex < getSize() && heapMax[leftCIndex] > heapMax[largestIndex])
		largestIndex = leftCIndex;

	if (rightCIndex < getSize() && heapMax[rightCIndex] > heapMax[largestIndex])
		largestIndex = rightCIndex;

	if (largestIndex == rootIndex) return;

	T tmp = heapMax[rootIndex];
	heapMax[rootIndex] = heapMax[largestIndex];
	heapMax[largestIndex] = tmp;

	balanceDownward(largestIndex);

}

template <typename T>
int HeapMax<T>::getParentIndex(int index) {
	return (index-1)/2;
}

template <typename T>
int HeapMax<T>::getLeftChildIndex(int index) {
	return (index*2)+1;
}

template <typename T>
int HeapMax<T>::getRightChildIndex(int index) {
	return (index*2)+2;
}

template <typename T>
bool HeapMax<T>::isLeaf(int index) {
	return index >= (heapMax.size()/2);
}





#endif

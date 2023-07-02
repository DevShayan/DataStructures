#ifndef ARRAY_SIMPLE_TPP
#define ARRAY_SIMPLE_TPP

template <typename T>
ArraySimple<T>::ArraySimple() {
    //
}


template <typename T>
ArraySimple<T>::ArraySimple(int size) {
    numberOfElements = 0;
    arraySize = size;
    arr = new T[arraySize];

}


template <typename T>
ArraySimple<T>::ArraySimple(std::initializer_list<T> list) {
    arraySize = numberOfElements = list.size();
    arr = new T[arraySize];
    int index = 0;

    for (T x : list) {
        arr[index] = x;
        index++;
    }

}


template <typename T>
ArraySimple<T>::ArraySimple(int size, std::initializer_list<T> list) {
    numberOfElements = list.size();
    arraySize = size;

    if (numberOfElements > arraySize) {
        throw "number of elements should not exeed the size of array!";
    }

    arr = new T[arraySize];
    int index = 0;

    for (T x : list) {
        arr[index] = x;
        index++;
    }

}


template <typename T>
void ArraySimple<T>::insert(T value, int index) {
    if (numberOfElements == arraySize)
        throw "Cannot insert in full array!\n";
    if (index < lb || index > numberOfElements+lb)
        throw "Invalid index";

    for (int x=numberOfElements+lb-1; x>=index; x--) {
        arr[x+1] = arr[x];
    }
    arr[index] = value;
    numberOfElements++;
}


template <typename T>
T ArraySimple<T>::remove(int index) {
    if (numberOfElements == 0) {
        throw "Cannot delete from empty array!";
    }

    if (index < lb || index > numberOfElements+lb-1) {
        throw "Invalid index";
    }

    T returnValue = arr[index];
    for (int x=index+1; x<numberOfElements+lb; x++) {
        arr[x-1] = arr[x];
    }
    numberOfElements--;

    return returnValue;
}


template <typename T>
int ArraySimple<T>::singleLinearSearch(T value) {

    for (int x=0; x<numberOfElements+lb; x++) {
        if (value == arr[x]) {
            return x;
        }
    }
    return -1;
}


template <typename T>
int ArraySimple<T>::multiLinearSearch(T value) {
    int count = 0;

    for (int x=0; x<numberOfElements+lb; x++) {
        if (value == arr[x]) {
            count++;
        }
    }
    return count;
}


template <typename T>
int ArraySimple<T>::singleBinarySearch(T value) {
    bubbleSort(true);

    if (numberOfElements == 0) {
        throw "Cannot sort array with no elements!";
    }

    int low = lb;
    int high = numberOfElements+lb-1;
    int mid;

    for (int x=0; low<=high; x++) {
        mid = (low+high) / 2;

        if (arr[mid] == value) {
            return mid;
        }
        if (value < arr[mid]) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}


template <typename T>
int ArraySimple<T>::multiBinarySearch(T value) {
    bubbleSort(true);

    if (numberOfElements == 0) {
        throw "Cannot sort array with no elements!";
    }

    int low = lb;
    int high = numberOfElements+lb-1;
    int midIndex;
    int count = 0;

    for (int x=0; low<=high; x++) {
        midIndex = (low+high) / 2;

        if (arr[midIndex] == value) {

            for (int y=midIndex; arr[y] == value; y++) {
                count++;
            }
            for (int y=midIndex-1; arr[y] == value; y--) {
                count++;
            }
            
            return count;
        }
        if (value < arr[midIndex]) {
            high = midIndex-1;
        }
        else {
            low = midIndex+1;
        }
    }
    return count;
}

template <typename T>
void ArraySimple<T>::bubbleSort(bool sortAscending) {
    int last = numberOfElements+lb-1;

    for (int x=lb; x<numberOfElements+lb-1; x++, last--) {
        for (int y=lb; y<last; y++) {
            if ((sortAscending && arr[y] > arr[y+1]) || (!sortAscending && arr[y] < arr[y+1])) {
                T tmp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = tmp;
            }
        }
    }
}

template <typename T>
void ArraySimple<T>::selectionSort(bool sortAscending) {
    int minIndex = lb;
    int startIndex = lb+1;

    for (int x=0; x<numberOfElements-1; x++, startIndex++, minIndex=startIndex-1) {
        for (int y=startIndex; y<numberOfElements+lb; y++) {
            if ((sortAscending && arr[y] < arr[minIndex]) || (!sortAscending && arr[y] > arr[minIndex])) {
                minIndex = y;
            }
        }
        if (minIndex != startIndex-1) {
            T tmp = arr[startIndex-1];
            arr[startIndex-1] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

template <typename T>
void ArraySimple<T>::insertionSort(bool sortAscending) {
    int endIndex = lb+1;
    int min;

    for (int x=lb; x<numberOfElements+lb-1; x++, endIndex++) {
        min = arr[endIndex];

        int y = endIndex - 1;
        while ((sortAscending && y >= lb && arr[y] > min) || (!sortAscending && y >= lb && arr[y] < min)) {
            arr[y+1] = arr[y];
            y--;
        }
        y++;
        
        arr[y] = min;
    }
}

template <typename T>
void ArraySimple<T>::shellSort(bool sortAscending) {
    int gap = numberOfElements/2;
    int min;

    while (gap != 0) {
        for (int endIndex=lb+gap; endIndex<numberOfElements+lb; endIndex++) {
            min = arr[endIndex];

            int y = endIndex - gap;
            while ((sortAscending && y >= lb && arr[y] > min) || (!sortAscending && y >= lb && arr[y] < min)) {
                arr[y + gap] = arr[y];
                y -= gap;
            }
            y += gap;

            arr[y] = min;
        }

        gap /= 2;
    }
}

template <typename T>
void ArraySimple<T>::mergeTwoArrays(ArraySimple arrA, ArraySimple arrB, bool sortAscending) {
    if (arrA.getSize() == 0 || arrB.getSize() == 0)
        throw "Array in parameter cannot be empty!";

    arrA.selectionSort(sortAscending);
    arrB.selectionSort(sortAscending);

    int indexA = lb;
    int indexB = lb;
    int indexArr = lb;

    setArray(arrA.getSize() + arrB.getSize());
    
    while (indexA < arrA.getElementCount()+lb && indexB < arrB.getElementCount()+lb) {
        if (arrA.getElementAt(indexA) < arrB.getElementAt(indexB)) {
            arr[indexArr] = arrA.getElementAt(indexA);
            indexA++;
        }
        else {
            arr[indexArr] = arrB.getElementAt(indexB);
            indexB++;
        }
        indexArr++;
    }

    while (indexA < arrA.getElementCount()+lb) {
        arr[indexArr] = arrA.getElementAt(indexA);
        indexArr++;
        indexA++;
    }

    while (indexB < arrB.getElementCount()+lb) {
        arr[indexArr] = arrB.getElementAt(indexB);
        indexArr++;
        indexB++;
    }

    numberOfElements = indexArr;
}

template <typename T>
void ArraySimple<T>::merge(bool sortAscending, int low, int mid, int high) {
    int arrTmp[high-low+1];

    int lPtr = low;
    int rPtr = mid + 1;
    int arrPtr = lb;

    while(lPtr <= mid && rPtr <= high) {
        if ((sortAscending && arr[lPtr] < arr[rPtr]) || (!sortAscending && arr[lPtr] > arr[rPtr]))
            arrTmp[arrPtr++] = arr[lPtr++];
        else
            arrTmp[arrPtr++] = arr[rPtr++];
    }

    while(lPtr <= mid) {
        arrTmp[arrPtr++] = arr[lPtr++];
    }

    while (rPtr <= high) {
        arrTmp[arrPtr++] = arr[rPtr++];
    }

    for (int x=low; x<=high; x++) {
        arr[x] = arrTmp[x-low];
    }
}

template <typename T>
void ArraySimple<T>::mergeSort_recursive(bool sortAscending, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort_recursive(sortAscending, low, mid);
    mergeSort_recursive(sortAscending, mid+1, high);
    merge(sortAscending, low, mid, high);
}

template <typename T>
void ArraySimple<T>::mergeSort(bool sortAscending) {
    mergeSort_recursive(sortAscending, lb, numberOfElements+lb-1);
}

template <typename T>
int ArraySimple<T>::partition(bool sortAscending, int low, int high) {
    int pivotIndex = high;
    int i = low - 1;
    for (int x=low; x<high; x++) {
        if ((sortAscending && arr[x] <= arr[pivotIndex]) || (!sortAscending && arr[x] >= arr[pivotIndex])) {
            i++;
            T tmp = arr[x];
            arr[x] = arr[i];
            arr[i] = tmp;
        }
    }
    T tmp = arr[i+1];
    arr[i+1] = arr[pivotIndex];
    arr[pivotIndex] = tmp;

    return i+1;
}

template <typename T>
void ArraySimple<T>::quickSort_recursive(bool sortAscending, int low, int high) {
    if (low >= high) return;

    int pivot = partition(sortAscending, low, high);
    quickSort_recursive(sortAscending, low, pivot-1);
    quickSort_recursive(sortAscending, pivot+1, high);
}

template <typename T>
void ArraySimple<T>::quickSort(bool sortAscending) {
    quickSort_recursive(sortAscending, lb, numberOfElements+lb-1);
}



// Getters and Setters

template <typename T>
void ArraySimple<T>::setArray(int size) {
    if (arr != NULL) deleteArray();

    numberOfElements = 0;
    arraySize = size;
    
    arr = new T[arraySize];

}


template <typename T>
void ArraySimple<T>::setArray(std::initializer_list<T> list) {
    if (arr != NULL) deleteArray();

    numberOfElements = list.size();
    arraySize = numberOfElements;
    
    arr = new T[arraySize];
    int index = 0;

    for (T x : list) {
        arr[index] = x;
        index++;
    }

}


template <typename T>
void ArraySimple<T>::setArray(int size, std::initializer_list<T> list) {
    if (arr != NULL) deleteArray();

    numberOfElements = list.size();
    arraySize = size;

    if (numberOfElements > arraySize) {
        throw "number of elements should not exeed the size of array!";
    }
    
    arr = new T[arraySize];
    int index = 0;

    for (T x : list) {
        arr[index] = x;
        index++;
    }

}

template <typename T>
int ArraySimple<T>::getElementCount() {
    return numberOfElements;
}

template <typename T>
int ArraySimple<T>::getElementAt(int index) {
    if (index < lb || index > arraySize-1)
        throw "Index is out of bound!";
    if (index > numberOfElements+lb-1)
        return 0;

    return arr[index];
}

template <typename T>
int ArraySimple<T>::getSize() {
    return arraySize;
}

template <typename T>
std::string ArraySimple<T>::getArrayAsString() {

    if (numberOfElements == 0) {
        return "[ ]";
    }
    std::string returnValue = "";

    for (int x=lb; x<numberOfElements+lb; x++) {
        if (x == 0) {
            returnValue += "[ ";
        }
        
        if (x == numberOfElements+lb-1) {
            returnValue += std::to_string(arr[x])+" ]";
        }
        else {
            returnValue += std::to_string(arr[x])+", ";
        }
    }
    return returnValue;
}

// Misc

template <typename T>
void ArraySimple<T>::deleteArray() {
    delete arr;
    arr = NULL;
    numberOfElements = 0;
    arraySize = 0;
}

template <typename T>
void ArraySimple<T>::clearArray() {
    for (int x=0; x<arraySize; x++) {
        arr[x] = 0;
    }
    numberOfElements = 0;
}


#endif

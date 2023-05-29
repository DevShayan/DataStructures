#include "tui.h"

void TUI::array() {
    printTopInfo("ARRAY", arr.getArrayAsString().c_str());
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }
    arr.setArray(size);

    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY", arr.getArrayAsString().c_str());
        std::cout << "1. Insert\n"
                  << "2. Delete\n"
                  << "3. Search\n"
                  << "4. Sort\n"
                  << "X. Back\n\n"
                  << "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                insertion();
                break;
            case '2':
                deletion();
                break;
            case '3':
                search();
                break;
            case '4':
                sort();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::insertion() {
    printTopInfo("ARRAY -> INSERT", arr.getArrayAsString().c_str());
    std::cout << "Enter value to insert: ";
    std::cin >> input;
    std::cout << "Enter position of insertion: ";
    std::cin >> index;

    try {
        arr.push(input, index);
    }
    catch (const char* e) {
        std::string error = std::string("Exception: ") + e;
        invalidInput(error.c_str());
    }
}

void TUI::deletion() {
    printTopInfo("ARRAY -> DELETE", arr.getArrayAsString().c_str());
    std::cout << "Enter position of deletion: ";
    std::cin >> index;

    try {
        arr.pop(index);
    }
    catch (const char* e) {
        std::string error = std::string("Exception: ") + e;
        invalidInput(error.c_str());
    }
}

void TUI::search() {
    printTopInfo("ARRAY -> SEARCH", arr.getArrayAsString().c_str());
    std::cout << "1. Single Search\n";
    std::cout << "2. Multi Search\n";
    std::cout << "X. Back\n\n";
    std::cout << "Select an operation: ";
    std::cin >> selection;

    if (selection == 'x' || selection == 'X') return;

    if (selection == '1') {
		singleSearch();
    }
    else if (selection == '2') {
        multiSearch();
    }
    system(pause);
}

char TUI::searchingMenu() {
    std::cout << "1. Linear Search\n";
    std::cout << "2. Binary Search\n";
    std::cout << "X. Back\n\n";
    std::cout << "Select an operation: ";
    std::cin >> selection;
    return selection;
}

void TUI::singleSearch() {
    printTopInfo("ARRAY -> SEARCH -> SINGLE SEARCH", arr.getArrayAsString().c_str());
    selection = searchingMenu();

    if (selection == 'x' || selection == 'X') return;

    std::cout << "Enter value to search in array: ";
    std::cin >> input;

    int foundIndex;
    
    if (selection == '1')
        foundIndex = arr.singleLinearSearch(input);
    else if (selection == '2')
        foundIndex = arr.singleBinarySearch(input);

    if (foundIndex == -1) {
        std::cout << input << " not found.\n";
    }
    else {
        std::cout << input << " found at index " << foundIndex << '\n';
    }
    system(pause);
}

void TUI::multiSearch() {
    printTopInfo("ARRAY -> SEARCH -> MULTI SEARCH", arr.getArrayAsString().c_str());
    selection = searchingMenu();

    if (selection == 'x' || selection == 'X') return;

    std::cout << "Enter value to search in array: ";
    std::cin >> input;

    int count;

    if (selection == '1')
        std::cout << input << " is " << arr.multiLinearSearch(input) << " times in array.\n";
    else if (selection == '2')
        std::cout << input << " is " << arr.multiBinarySearch(input) << " times in array.\n";

}

void TUI::sort() {
    printTopInfo("ARRAY -> SORT", arr.getArrayAsString().c_str());
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Shell Sort\n";
    std::cout << "5. Merge Sort\n";
    std::cout << "6. Quick Sort\n";
    std::cout << "X. Back\n\n";
    std::cout << "Select an operation: ";
    std::cin >> selection;

    if (selection == 'x' || selection == 'X') return;

    char sortAscending;

    std::cout << "Sort ascending? [y/n]: ";
    std::cin >> sortAscending;


    if (selection == '1')
        arr.bubbleSort(sortAscending != 'n');
    else if (selection == '2')
        arr.selectionSort(sortAscending != 'n');
    else if (selection == '3')
        arr.insertionSort(sortAscending != 'n');
    else if (selection == '4')
        arr.shellSort(sortAscending != 'n');
    else if (selection == '5')
        arr.mergeSort(sortAscending != 'n');
    else if (selection == '6')
        arr.quickSort(sortAscending != 'n');
    else
        invalidInput("Invalid input!");
}



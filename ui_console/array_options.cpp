#include "tui.h"
#include <cstdlib>
#include <ctime>

void TUI::array() {
    if (arr.getSize() == 0)
        newArray();

    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY", arr.getArrayAsString().c_str(), NULL);
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. Search\n"
                << "4. Sort\n"
                << "5. Merging\n"
                << "6. New array\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
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
            case '5':
                merging();
                break;
            case '6':
                newArray();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                std::cout << selection << ' ';
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::insertion() {
    printTopInfo("ARRAY -> INSERT", arr.getArrayAsString().c_str(), NULL);
    std::cout << "Enter value to insert: ";
    std::cin >> input;
    std::cout << "Enter position of insertion: ";
    std::cin >> input2;

    try { arr.insert(input, input2); }
    catch (const char* e) {
        std::string error = std::string("Exception: ") + e;
        invalidInput(error.c_str());
    }
}

void TUI::deletion() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY -> DELETE", arr.getArrayAsString().c_str(), NULL);
        std::cout << "1. Full array\n"
                << "2. One value\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                try { arr.clearArray(); }
                catch (const char* e) {
                    std::string error = std::string("Exception: ")+e;
                    invalidInput(error.c_str());
                }
                break;
            case '2':
                deletionItem();
                break;
            case 'x': case 'X':
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::deletionItem() {
    printTopInfo("ARRAY -> DELETE -> ONE VALUE", arr.getArrayAsString().c_str(), NULL);
    std::cout << "Enter position of deletion: ";
    std::cin >> input;

    try {
        arr.remove(input);
    }
    catch (const char* e) {
        std::string error = std::string("Exception: ") + e;
        invalidInput(error.c_str());
    }
}

void TUI::search() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY -> SEARCH", arr.getArrayAsString().c_str(), NULL);
        std::cout << "1. Single Search\n"
                << "2. Multi Search\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        if (selection == 'x' || selection == 'X') return;

        if (selection == '1') {
            singleSearch();
        }
        else if (selection == '2') {
            multiSearch();
        }
    }
}

char TUI::searchingMenu() {
    std::cout << "1. Linear Search\n"
            << "2. Binary Search\n\n"
            << magenta << "X. Back\n\n" << clearTextColor
            << "Select an operation: ";
    std::cin >> selection;
    return selection;
}

void TUI::singleSearch() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY -> SEARCH -> SINGLE SEARCH", arr.getArrayAsString().c_str(), NULL);
        selection = searchingMenu();

        if (selection == 'x' || selection == 'X') return;

        int foundIndex;
        
        if (selection == '1') {
            printTopInfo("ARRAY -> SEARCH -> SINGLE SEARCH --> LINEAR SEARCH", arr.getArrayAsString().c_str(), NULL);
            std::cout << "Enter value to search in array: ";
            std::cin >> input;
            foundIndex = arr.singleLinearSearch(input);
        }
        else if (selection == '2') {
            printTopInfo("ARRAY -> SEARCH -> SINGLE SEARCH --> BINARY SEARCH", arr.getArrayAsString().c_str(), NULL);
            std::cout << "Enter value to search in array: ";
            std::cin >> input;
            foundIndex = arr.singleBinarySearch(input);
        }

        if (foundIndex == -1) {
            std::cout << input << " not found.\n";
        }
        else {
            std::cout << input << " found at index " << foundIndex << '\n';
        }
        system(pause);
    }
}

void TUI::multiSearch() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY -> SEARCH -> MULTI SEARCH", arr.getArrayAsString().c_str(), NULL);
        selection = searchingMenu();

        if (selection == 'x' || selection == 'X') return;

        if (selection == '1') {
            printTopInfo("ARRAY -> SEARCH -> MULTI SEARCH -> LINEAR SEARCH", arr.getArrayAsString().c_str(), NULL);
            std::cout << "Enter value to search in array: ";
            std::cin >> input;
            std::cout << input << " is " << arr.multiLinearSearch(input) << " times in array.\n";
        }
        else if (selection == '2') {
            printTopInfo("ARRAY -> SEARCH -> MULTI SEARCH -> BINARY SEARCH", arr.getArrayAsString().c_str(), NULL);
            std::cout << "Enter value to search in array: ";
            std::cin >> input;
            std::cout << input << " is " << arr.multiBinarySearch(input) << " times in array.\n";
        }
        system(pause);
    }
}

void TUI::sort() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("ARRAY -> SORT", arr.getArrayAsString().c_str(), NULL);
        std::cout << "1. Bubble Sort\n"
                    << "2. Selection Sort\n"
                    << "3. Insertion Sort\n"
                    << "4. Shell Sort\n"
                    << "5. Merge Sort\n"
                    << "6. Quick Sort\n\n"
                    << magenta << "X. Back\n\n" << clearTextColor
                    << "Select an operation: ";
        std::cin >> selection;

        if (selection == 'x' || selection == 'X') return;

        char sortAscending;

        switch (selection) {
            case '1':
                printTopInfo("ARRAY -> SORT -> BUBBLE SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.bubbleSort(sortAscending != 'n');
                break;

            case '2':
                printTopInfo("ARRAY -> SORT -> SELECTION SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.selectionSort(sortAscending != 'n');
                break;

            case '3':
                printTopInfo("ARRAY -> SORT -> INSERTION SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.insertionSort(sortAscending != 'n');
                break;

            case '4':
                printTopInfo("ARRAY -> SORT -> SHELL SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.shellSort(sortAscending != 'n');
                break;

            case '5':
                printTopInfo("ARRAY -> SORT -> MERGE SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.mergeSort(sortAscending != 'n');
                break;

            case '6':
                printTopInfo("ARRAY -> SORT -> QUICK SORT", arr.getArrayAsString().c_str(), NULL);
                std::cout << "Sort ascending? [y/n]: ";
                std::cin >> sortAscending;
                arr.quickSort(sortAscending != 'n');
                break;

            default:
                invalidInput("Invalid input!");

        }
    }
}

void TUI::newArray() {
    printTopInfo("ARRAY -> NEW ARRAY", "-", NULL);
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("ARRAY -> NEW ARRAY", "-", NULL);
    std::cout << "Initialize array with random values? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

    arr.setArray(size);
    
    if (initialize == 'y') {
        srand(time(0));
        for (int x=0; x<size; x++) {
            arr.insert(rand()%100, x);
        }
    }
}

void TUI::merging() {
    ArraySimple<int> arr1, arr2;

    std::string arrays = "Array 1: " + arr1.getArrayAsString() + "\nArray 2: " + arr2.getArrayAsString();
    printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
    std::cout << "Enter size of array 1: ";
    std::cin >> size;

    if (size < 1 && size > 100) {
        std::cout << "Size must be in the range 1-100.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
    std::cout << "Initialize array 1 with random values? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        merging();
        return;
    }

    arr1.setArray(size);
    
    if (initialize == 'y') {
        srand(time(0));
        for (int x=0; x<size; x++) {
            arr1.insert(rand()%100, x);
        }
    }
    else {
        for (int x=0; x<size; x++) {
            arrays = "Array 1: " + arr1.getArrayAsString() + "\nArray 2: " + arr2.getArrayAsString();
            printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
            std::cout << "Enter value in array 1 at 'index " << x << "': ";
            std::cin >> input;
            arr1.insert(input, x);
        }
    }

    arrays = "Array 1: " + arr1.getArrayAsString() + "\nArray 2: " + arr2.getArrayAsString();
    printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
    std::cout << "Enter size of array 2: ";
    std::cin >> size;

    if (size < 1 && size > 100) {
        std::cout << "Size must be in the range 1-100.\n";
        return;
    }

    initialize = '|';

    printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
    std::cout << "Initialize array 2 with random values? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        merging();
        return;
    }

    arr2.setArray(size);
    
    if (initialize == 'y') {
        srand(time(0));
        for (int x=0; x<size; x++) {
            arr2.insert(rand()%100, x);
        }
    }
    else {
        for (int x=0; x<size; x++) {
            arrays = "Array 1: " + arr1.getArrayAsString() + "\nArray 2: " + arr2.getArrayAsString();
            printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);
            std::cout << "Enter value in array 2 at 'index " << x << "': ";
            std::cin >> input;
            arr2.insert(input, x);
        }
    }

    arr.mergeTwoArrays(arr1, arr2, true);

    arrays = "Array 1: " + arr1.getArrayAsString() + "\nArray 2: " + arr2.getArrayAsString();
    printTopInfo("ARRAY -> MERGING", arrays.c_str(), NULL);

    std::cout << "Values merged in main array.\nPress any key to continue...\n";
    system(pause);
}




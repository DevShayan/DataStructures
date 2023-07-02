#include "tui.h"

void TUI::heapMenu() {
	while (selection != 'x' || selection != 'X') {
        printTopInfo("HEAP", "-", NULL);
		std::cout << "1. Min Heap\n"
				<< "2. Max heap\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                heapX(heapMin);
                break;
            case '2':
                heapX(heapMax);
                break;
            case 'x': case 'X':
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

template <typename T>
void TUI::heapX(T& heap) {
	if (heap.getSize() == 0) {
		newHeap(heap);
	}
	std::string headingName;

	if (typeid(heap) == typeid(heapMin)) {
		headingName = "HEAP -> MIN HEAP";
	}
	else if (typeid(heap) == typeid(heapMax)) {
		headingName = "HEAP -> MAX HEAP";
	}

    while (selection != 'x' || selection != 'X') {
        printTopInfo(headingName.c_str(), heap.getHeapAsString().c_str(), NULL);
		std::cout << "1. Insert\n"
				<< "2. Delete\n"
				<< "3. Search\n"
				<< "4. New heap\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                heapInsert(heap);
                break;
            case '2':
				try {
					if (typeid(heap) == typeid(heapMin))
						heapMin.removeMin();
					else if (typeid(heap) == typeid(heapMax))
						heapMax.removeMin();
				} catch (const char* e) {
					std::string error = std::string("Exception: ")+e;
					invalidInput(error.c_str());
				}
                break;
            case '3':
                heapSearch(heap);
                break;
            case '4':
                newHeap(heap);
                break;
            case 'x': case 'X':
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

template <typename T>
void TUI::heapInsert(T& heap) {
	std::string headingName, str;

	if (typeid(heap) == typeid(heapMin)) {
		headingName = "HEAP -> MIN HEAP -> INSERT";
	}
	else if (typeid(heap) == typeid(heapMax)) {
		headingName = "HEAP -> MAX HEAP -> INSERT";
	}

	printTopInfo(headingName.c_str(), heap.getHeapAsString().c_str(), NULL);
	std::cout << "Enter value to insert in heap: ";
	std::cin >> input;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		invalidInput("Invalid Input!");
		return;
	}

	if (typeid(heap) == typeid(heapMin)) {
		heapMin.insert(input);
	}
	else if (typeid(heap) == typeid(heapMax)) {
		heapMax.insert(input);
	}
}


template <typename T>
void TUI::heapSearch(T& heap) {
	std::string headingName, headingName2;

	if (typeid(heap) == typeid(heapMin))
		headingName = "HEAP -> MIN HEAP -> SEARCH";
	else if (typeid(heap) == typeid(heapMax))
		headingName = "HEAP -> MAX HEAP -> SEARCH";

    while (selection != 'x' || selection != 'X') {
        printTopInfo(headingName.c_str(), heap.getHeapAsString().c_str(), NULL);
		std::cout << "1. Single Search\n"
				<< "2. Multi Search\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

		if (selection == '1' || selection == '2') {
			if (selection == '1' && typeid(heap) == typeid(heapMin))
				headingName2 = "HEAP -> MIN HEAP -> SEARCH -> SINGLE SEARCH";

			else if (selection == '1' && typeid(heap) == typeid(heapMax))
				headingName2 = "HEAP -> MAX HEAP -> SEARCH -> SINGLE SEARCH";

			else if (selection == '2' && typeid(heap) == typeid(heapMin))
				headingName2 = "HEAP -> MIN HEAP -> SEARCH -> MULTI SEARCH";

			else if (selection == '2' && typeid(heap) == typeid(heapMax))
				headingName2 = "HEAP -> MAX HEAP -> SEARCH -> MULTI SEARCH";

			printTopInfo(headingName2.c_str(), heap.getHeapAsString().c_str(), NULL);
			std::cout << "Enter value to search in heap: ";
			std::cin >> input;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				invalidInput("Invalid Input!");
				return;
			}
		}

		int index;
        switch (selection) {
            case '1':
				index = heap.singleSearchFor(input);

				if (index == -1)
					std::cout << input << " not found in heap.\n";
				else
					std::cout << input << " found at index '" << index << "' in heap.\n";
				break;

            case '2':
				std::cout << input << " found '" << heap.multiSearchFor(input) << " times' in heap.\n";
                break;

            case 'x': case 'X':
                return;

            default:
                invalidInput("Invalid selection!");
        }
		system(pause);
    }
}


template <typename T>
void TUI::newHeap(T& heap) {
    char initialize = '|';
	std::string headingName;

	if (typeid(heap) == typeid(heapMin)) {
		headingName = "HEAP -> MIN HEAP -> NEW HEAP";
	}
	else if (typeid(heap) == typeid(heapMax)) {
		headingName = "HEAP -> MAX HEAP -> NEW HEAP";
	}

    printTopInfo(headingName.c_str(), "-", NULL);
    std::cout << "Initialize heap with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (heap.getSize() != 0) {
    	heap.deleteHeap();
	}

    if (initialize == 'y') {
		size = 0;
		while (size > 100 || size < 1) {
			printTopInfo(headingName.c_str(), "-", NULL);
			std::cout << "How many nodes should we generate?: ";
			std::cin >> size;

			if (size < 1 || size > 100) {
				invalidInput("Random nodes must be in the range [1-100].");
			}
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            heap.insert(rand()%100);
        }
    }
}





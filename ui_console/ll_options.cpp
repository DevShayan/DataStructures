#include "tui.h"

void TUI::linkedListMenu() {
	while (selection != 'x' || selection != 'X') {
        printTopInfo("LINKED LIST", "-", NULL);
		std::cout << "1. Single\n"
				<< "2. Double\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                linkedList(ll);
                break;
            case '2':
                linkedList(dll);
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

template <typename T>
void TUI::linkedList(T& list) {
	if (list.getElementCount() == 0) {
		newList(list);
	}
	std::string listName;

	if (typeid(list) == typeid(ll)) {
		listName = "LINKED LIST -> SINGLE";
	}
	else if (typeid(list) == typeid(dll)) {
		listName = "LINKED LIST -> DOUBLE";
	}

    while (selection != 'x' || selection != 'X') {
        printTopInfo(listName.c_str(), list.getListAsString().c_str(), NULL);
		std::cout << "1. Insert\n"
				<< "2. Delete\n"
				<< "3. Search\n"
				<< "4. New list\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                llInsert(list);
                break;
            case '2':
                llDelete(list);
                break;
            case '3':
                llSearch(list);
                break;
            case '4':
                newList(list);
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

template <typename T>
void TUI::llInsert(T& list) {
	std::string listName, str;

	if (typeid(list) == typeid(ll)) {
		listName = "LINKED LIST -> SINGLE -> INSERT";
	}
	else if (typeid(list) == typeid(dll)) {
		listName = "LINKED LIST -> DOUBLE -> INSERT";
	}

    while (selection != 'x' || selection != 'X') {
        printTopInfo(listName.c_str(), list.getListAsString().c_str(), NULL);
		std::cout << "1. At first\n"
				<< "2. At last\n"
				<< "3. Before node\n"
				<< "4. After node\n"
				<< "5. At Mid\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

		try {
			switch (selection) {
				case '1':
					str = listName + " -> AR FIRST";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter value to insert: ";
					std::cin >> input;
					list.insertAtFirst(input);
					break;

				case '2':
					str = listName + " -> AT LAST";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter value to insert: ";
					std::cin >> input;
					list.insertAtLast(input);
					break;

				case '3':
					str = listName + " -> BEFORE NODE";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter node to insert before of: ";
					std::cin >> input;
					std::cout << "Enter value to insert: ";
					std::cin >> input2;
					list.insertBefore(input, input2);
					break;

				case '4':
					str = listName + " -> AFTER NODE";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter node to insert after of: ";
					std::cin >> input;
					std::cout << "Enter value to insert: ";
					std::cin >> input2;
					list.insertAfter(input, input2);
					break;

				case '5':
					str = listName + " -> AT MID";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter value to insert: ";
					std::cin >> input;
					list.insertAtMid(input);
					break;

				case 'x': case 'X':
					system(clear);
					return;

				default:
					invalidInput("Invalid selection!");
			}
		}
		catch (const char* e) {
			std::string error = std::string("Exception: ")+e;
			invalidInput(error.c_str());
		}
    }

}

template <typename T>
void TUI::llDelete(T& list) {
	std::string listName, str;

	if (typeid(list) == typeid(ll)) {
		listName = "LINKED LIST -> SINGLE -> DELETE";
	}
	else if (typeid(list) == typeid(dll)) {
		listName = "LINKED LIST -> DOUBLE -> DELETE";
	}

    while (selection != 'x' || selection != 'X') {
        printTopInfo(listName.c_str(), list.getListAsString().c_str(), NULL);
		std::cout << "1. First node\n"
				<< "2. Last node\n"
				<< "3. Before node\n"
				<< "4. After node\n"
				<< "5. Middle node\n"
				<< "6. Node\n"
				<< "7. Full list\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

		try {
			switch (selection) {
				case '1':
					list.deleteFirst();
					break;

				case '2':
					list.deleteLast();
					break;

				case '3':
					str = listName + " -> BEFORE NODE";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter node to delete before of: ";
					std::cin >> input;
					list.deleteBefore(input);
					break;

				case '4':
					str = listName + " -> AFTER NODE";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter node to delete after of: ";
					std::cin >> input;
					list.deleteAfter(input);
					break;

				case '5':
					list.deleteMid();
					break;

				case '6':
					str = listName + " -> NODE";
					printTopInfo(str.c_str(), list.getListAsString().c_str(), NULL);
					std::cout << "Enter node to delete: ";
					std::cin >> input;
					list.deleteNode(input);
					break;

				case '7':
					list.deleteList();
					break;

				case 'x': case 'X':
					system(clear);
					return;

				default:
					invalidInput("Invalid selection!");
			}
		}
		catch (const char* e) {
			std::string error = std::string("Exception: ")+e;
			invalidInput(error.c_str());
		}
    }

}

template <typename T>
void TUI::newList(T& list) {
    char initialize = '|';
	std::string listName;

	if (typeid(list) == typeid(ll)) {
		listName = "LINKED LIST -> SINGLE -> NEW LIST";
	}
	else if (typeid(list) == typeid(dll)) {
		listName = "LINKED LIST -> DOUBLE -> NEW LIST";
	}

    printTopInfo(listName.c_str(), "-", NULL);
    std::cout << "Initialize linked list with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (list.getElementCount() != 0) {
    	list.deleteList();
	}

    if (initialize == 'y') {
		printTopInfo(listName.c_str(), "-", NULL);
		std::cout << "How many nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            list.insertAtFirst(rand()%100);
        }
    }
}

template <typename T>
void TUI::llSearch(T& list) {
	std::string headingName, headingName2;

	if (typeid(list) == typeid(ll))
		headingName = "LINKED LIST -> SINLGE -> SEARCH";
	else if (typeid(list) == typeid(dll))
		headingName = "LINKED LIST -> DOUBLE -> SEARCH";

    while (selection != 'x' || selection != 'X') {
        printTopInfo(headingName.c_str(), list.getListAsString().c_str(), NULL);
		std::cout << "1. Single Search\n"
				<< "2. Multi Search\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

		if (selection == '1' || selection == '2') {
			if (selection == '1' && typeid(list) == typeid(ll))
				headingName2 = "LINKED LIST -> SINGLE -> SEARCH -> SINGLE SEARCH";

			else if (selection == '1' && typeid(list) == typeid(dll))
				headingName2 = "LINKED LIST -> DOUBLE -> SEARCH -> SINGLE SEARCH";

			else if (selection == '2' && typeid(list) == typeid(ll))
				headingName2 = "LINKED LIST -> SINGLE -> SEARCH -> MULTI SEARCH";

			else if (selection == '2' && typeid(list) == typeid(dll))
				headingName2 = "LINKED LIST -> DOUBLE -> SEARCH -> MULTI SEARCH";

			printTopInfo(headingName2.c_str(), list.getListAsString().c_str(), NULL);
			std::cout << "Enter value to search in list: ";
			std::cin >> input;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				invalidInput("Invalid Input!");
				return;
			}
		}

        switch (selection) {
            case '1':
				if (list.singleSearchFor(input))
					std::cout << input << " found in list.\n";
				else
					std::cout << input << " not found in list.\n";
				break;

            case '2':
				std::cout << input << " found '" << list.multiSearchFor(input) << " times' in list.\n";
                break;

            case 'x': case 'X':
                return;

            default:
                invalidInput("Invalid selection!");
        }
		system(pause);
    }
}




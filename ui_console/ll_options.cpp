#include "tui.h"

void TUI::linkedList() {
	if (ll.getElementCount() == 0) {
		newList();
	}

    while (selection != 'x' || selection != 'X') {
        printTopInfo("LINKED LIST", ll.getListAsString().c_str());
		std::cout << "1. Insert\n"
				<< "2. Delete\n"
				<< "3. New list\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                llInsert();
                break;
            case '2':
                llDelete();
                break;
            case '3':
                newList();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::llInsert() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("LINKED LIST -> INSERT", ll.getListAsString().c_str());
		std::cout << "1. At first\n"
				<< "2. At last\n"
				<< "3. Before node\n"
				<< "4. After node\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

		try {
			switch (selection) {
				case '1':
					printTopInfo("LINKED LIST -> INSERT -> AT FIRST", ll.getListAsString().c_str());
					std::cout << "Enter value to insert: ";
					std::cin >> input;
					ll.insertAtFirst(input);
					break;

				case '2':
					printTopInfo("LINKED LIST -> INSERT -> AT LAST", ll.getListAsString().c_str());
					std::cout << "Enter value to insert: ";
					std::cin >> input;
					ll.insertAtLast(input);
					break;

				case '3':
					printTopInfo("LINKED LIST -> INSERT -> BEFORE NODE", ll.getListAsString().c_str());
					std::cout << "Enter node to insert before of: ";
					std::cin >> input;
					std::cout << "Enter value to insert: ";
					std::cin >> input2;
					ll.insertBefore(input, input2);
					break;

				case '4':
					printTopInfo("LINKED LIST -> INSERT -> AFTER NODE", ll.getListAsString().c_str());
					std::cout << "Enter node to insert after of: ";
					std::cin >> input;
					std::cout << "Enter value to insert: ";
					std::cin >> input2;
					ll.insertAfter(input, input2);
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

void TUI::llDelete() {
    while (selection != 'x' || selection != 'X') {
        printTopInfo("LINKED LIST -> DELETE", ll.getListAsString().c_str());
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
					ll.deleteFirst();
					break;

				case '2':
					ll.deleteLast();
					break;

				case '3':
					printTopInfo("LINKED LIST -> DELETE -> BEFORE NODE", ll.getListAsString().c_str());
					std::cout << "Enter node to delete before of: ";
					std::cin >> input;
					ll.deleteBefore(input);
					break;

				case '4':
					printTopInfo("LINKED LIST -> DELETE -> AFTER NODE", ll.getListAsString().c_str());
					std::cout << "Enter node to delete after of: ";
					std::cin >> input;
					ll.deleteAfter(input);
					break;

				case '5':
					ll.deleteMid();
					break;

				case '6':
					printTopInfo("LINKED LIST -> DELETE -> NODE", ll.getListAsString().c_str());
					std::cout << "Enter node to delete: ";
					std::cin >> input;
					ll.deleteNode(input);
					break;

				case '7':
					ll.deleteList();
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

void TUI::newList() {
    char initialize = '|';

    printTopInfo("LINKED LIST -> NEW LIST", ll.getListAsString().c_str());
    std::cout << "Initialize linked list with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (ll.getElementCount() != 0) {
    	ll.deleteList();
	}

    if (initialize == 'y') {
		printTopInfo("LINKED LIST -> NEW LIST", ll.getListAsString().c_str());
		std::cout << "How many nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            ll.insertAtFirst(rand()%100);
        }
    }
}


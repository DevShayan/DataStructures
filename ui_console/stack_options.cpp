#include "tui.h"

void TUI::stack() {
	while (selection != 'x' || selection != 'X') {
		printTopInfo("STACK", stack_arr.getStackAsString().c_str());
		std::cout << "1. on Array\n"
				<< "2. on Linked List\n"
				<< "!. on Double Linked List\n"
				<< "X. Back\n\n"
				<< "Select an operation: ";
		std::cin >> selection;

        switch (selection) {
            case '1':
                stackOnArray();
                break;
            case '2':
                stackOnLL();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::stackOnArray() {
    if (stack_arr.getSize() == 0) {
        newStackArr();
    }

    while (selection != 'x' || selection != 'X') {
        system(clear);
		printTopInfo("STACK -> ON ARRAY", stack_arr.getStackAsString().c_str());
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Stack\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    printTopInfo("STACK -> ON ARRAY -> INSERT", stack_arr.getStackAsString().c_str());
                    std::cout << "Enter value to push: ";
                    std::cin >> input;
                    stack_arr.push(input);
                    break;

                case '2':
                    stack_arr.pop();
                    break;

                case '3':
                    newStackArr();
                    break;

                case 'x': case 'X':
                    system(clear);
                    return;

                default:
                    std::cout << selection << '\t';
                    invalidInput("Invalid selection!");
            }
        } catch (const char* e) {
            std::string error = std::string("Exception: ") + e;
            invalidInput(error.c_str());
        }
    }
}

void TUI::newStackArr() {
    printTopInfo("STACK -> ON ARRAY -> NEW STACK", stack_arr.getStackAsString().c_str());
    std::cout << "Enter size of stack: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("STACK -> ON ARRAY -> NEW STACK", stack_arr.getStackAsString().c_str());
    std::cout << "Initialize stack with random values? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

    stack_arr.setStack(size);
    
    if (initialize == 'y') {
        srand(time(0));
        for (int x=0; x<size; x++) {
            stack_arr.push(rand()%100);
        }
    }
}

void TUI::stackOnLL() {
    if (stack_ll.getElementCount() == 0) {
        newStackLL();
    }

    while (selection != 'x' || selection != 'X') {
		printTopInfo("STACK -> ON LINKED LIST", stack_ll.getStackAsString().c_str());
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Stack\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    printTopInfo("STACK -> ON LINKED LIST -> INSERT", stack_ll.getStackAsString().c_str());
                    std::cout << "Enter value to insert: ";
                    std::cin >> input;
                    stack_ll.push(input);
                    break;

                case '2':
                    stack_ll.pop();
                    break;

                case '3':
                    newStackLL();
                    break;

                case 'x': case 'X':
                    system(clear);
                    return;

                default:
                    invalidInput("Invalid selection!");
            }
        }
        catch (const char* e) {
            std::string error = std::string("Exception: ") + e;
            invalidInput(error.c_str());
        }
    }
}

void TUI::newStackLL() {
    char initialize = '|';

    printTopInfo("STACK -> ON LINKED LIST -> NEW STACK", stack_ll.getStackAsString().c_str());
    std::cout << "Initialize stack with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (stack_ll.getElementCount() != 0) {
    	stack_ll.deleteStack();
	}

    if (initialize == 'y') {
		printTopInfo("STACK -> ON LINKED LIST -> NEW STACK", stack_ll.getStackAsString().c_str());
		std::cout << "How many nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            stack_ll.push(rand()%100);
        }
    }
}


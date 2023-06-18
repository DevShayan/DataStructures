#include "tui.h"

void TUI::stackMenu() {
	while (selection != 'x' || selection != 'X') {
		printTopInfo("STACK", "-", NULL);
		std::cout << "1. on Array\n"
				<< "2. on Linked List\n"
				<< "3. on Double Linked List\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
		std::cin >> selection;

        switch (selection) {
            case '1':
                stack(stack_arr);
                break;
            case '2':
                stack(stack_ll);
                break;
            case '3':
                stack(stack_dll);
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
void TUI::stack(T& stack) {
    std::string stackHeading, str;

    if (typeid(stack) == typeid(stack_arr) && stack_arr.getSize() == 0) {
        newStackArr();
    }
    else if (stack.getElementCount() == 0) {
        newStackLL(stack);
    }

    if (typeid(stack) == typeid(stack_arr)) {
        stackHeading = "STACK -> ON ARRAY";
    }
    else if (typeid(stack) == typeid(stack_ll)) {
        stackHeading = "STACK -> ON LINKED LIST";
    }
    else if (typeid(stack) == typeid(stack_dll)) {
        stackHeading = "STACK -> ON DOUBLE LINKED LIST";
    }

    while (selection != 'x' || selection != 'X') {
		printTopInfo(stackHeading.c_str(), stack.getStackAsString().c_str(), NULL);
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Stack\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    str = stackHeading + " -> INSERT";
                    printTopInfo(str.c_str(), stack.getStackAsString().c_str(), NULL);
                    std::cout << "Enter value to insert: ";
                    std::cin >> input;
                    stack.push(input);
                    break;

                case '2':
                    stack.pop();
                    break;

                case '3':
                    if (typeid(stack) == typeid(stack))
                        newStackArr();
                    else
                        newStackLL(stack);
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
    printTopInfo("STACK -> ON ARRAY -> NEW STACK", "-", NULL);
    std::cout << "Enter size of stack: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("STACK -> ON ARRAY -> NEW STACK", "-", NULL);
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

template <typename T>
void TUI::newStackLL(T& stack) {
    char initialize = '|';
    std::string stackHeading;

    if (typeid(stack) == typeid(stack_ll)) {
        stackHeading = "STACK -> ON ARRAY -> NEW STACK";
    }
    else if (typeid(stack) == typeid(stack_dll)) {
        stackHeading = "STACK -> ON DOUBLE LINKED LIST -> NEW STACK";
    }

    printTopInfo(stackHeading.c_str(), "-", NULL);
    std::cout << "Initialize stack with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (stack.getElementCount() != 0) {
    	stack.deleteStack();
	}

    if (initialize == 'y') {
		printTopInfo(stackHeading.c_str(), "-", NULL);
		std::cout << "How many elements/nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random elements/nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            stack.push(rand()%100);
        }
    }
}


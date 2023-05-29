#include "tui.h"

void TUI::stack() {
	printTopInfo("STACK", stack_arr.getStackAsString().c_str());
	std::cout << "Enter size of Stack: ";
    std::cin >> size;

	if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

	while (selection != 'x' || selection != 'X') {
		printTopInfo("STACK", stack_arr.getStackAsString().c_str());
		std::cout << "1. on Array\n"
				<< "!. on Linked List\n"
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
    stack_arr.setStack(size);

    while (selection != 'x' || selection != 'X') {
        system(clear);
		printTopInfo("STACK -> ON ARRAY", stack_arr.getStackAsString().c_str());
        std::cout << "1. Push\n"
                  << "2. Pop\n"
                  << "X. Back\n\n"
                  << "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                push(true);
                break;
            case '2': {
				try{
                	stack_arr.pop();
				} catch (const char* e) {
					std::string error = std::string("Exception: ")+e;
					invalidInput(error.c_str());
				}
                break;
			}
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::stackOnLL() {
    // stack_ll.setStack(size);
	return;

    while (selection != 'x' || selection != 'X') {
		printTopInfo("STACK -> ON ARRAY", stack_arr.getStackAsString().c_str());
        std::cout << "1. Push\n"
                  << "2. Pop\n"
                  << "X. Back\n\n"
                  << "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                push(false);
                break;
            case '2':
                stack_arr.pop();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}



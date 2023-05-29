#include "tui.h"

void TUI::queue() {
	printTopInfo("QUEUE", que_arr.getQueueAsString().c_str());
	std::cout << "Enter size of Queue: ";
    std::cin >> size;

	if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

	while (selection != 'x' || selection != 'X') {
		printTopInfo("QUEUE", que_arr.getQueueAsString().c_str());
		std::cout << "1. on Array\n"
				<< "!. on Linked List\n"
				<< "X. Back\n\n"
				<< "Select an operation: ";
		std::cin >> selection;

        switch (selection) {
            case '1':
                queueOnArray();
                break;
            case '2':
                queueOnLL();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::queueOnArray() {
    que_arr.setQueue(size);

    while (selection != 'x' || selection != 'X') {
        system(clear);
		printTopInfo("QUEUE -> ON ARRAY", que_arr.getQueueAsString().c_str());
        std::cout << "1. Push\n"
                  << "2. Pop\n"
                  << "X. Back\n\n"
                  << "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                push(false);
                break;
            case '2': {
				try{
                	que_arr.pop();
				} catch (const char* e) {
					std::string error = std::string("Exception: ")+e;
					invalidInput(error.c_str());
				}
                break;
			}
            case 'x': case 'X':
                system(clear);
                return;
            default: {
                std::cout << selection << '\t';
                invalidInput("Invalid selection!");
            }
        }
    }
}

void TUI::push(bool isStack) {
	if (isStack) {
		printTopInfo("Stack -> ON ARRAY -> PUSH", stack_arr.getStackAsString().c_str());
		std::cout << "Enter value to push: ";
		std::cin >> input;

		try {
			stack_arr.push(input);
		} catch (const char* e) {
			std::string error = std::string("Exception: ") + e;
			invalidInput(error.c_str());
		}
	}
	else {
		printTopInfo("QUEUE -> ON ARRAY -> PUSH", que_arr.getQueueAsString().c_str());
		std::cout << "Enter value to push: ";
		std::cin >> input;

		try {
			que_arr.push(input);
		} catch (const char* e) {
			std::string error = std::string("Exception: ") + e;
			invalidInput(error.c_str());
		}
	}
}

void TUI::queueOnLL() {
    // que_ll.setQueue(size);
	return;

    while (selection != 'x' || selection != 'X') {
		printTopInfo("QUEUE -> ON ARRAY", que_arr.getQueueAsString().c_str());
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
                que_arr.pop();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}



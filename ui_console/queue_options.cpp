#include "tui.h"

void TUI::queue() {
	while (selection != 'x' || selection != 'X') {
		printTopInfo("QUEUE", que_arr.getQueueAsString().c_str());
		std::cout << "1. on Array\n"
				<< "2. on Linked List\n"
				<< "!. on Double Linked List\n"
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
    if (que_arr.getSize() == 0) {
        newQueArr();
    }

    while (selection != 'x' || selection != 'X') {
        system(clear);
		printTopInfo("QUEUE -> ON ARRAY", que_arr.getQueueAsString().c_str());
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Queue\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    printTopInfo("QUEUE -> ON ARRAY -> INSERT", que_arr.getQueueAsString().c_str());
                    std::cout << "Enter value to push: ";
                    std::cin >> input;
                    que_arr.enQueue(input);
                    break;

                case '2':
                    que_arr.deQueue();
                    break;

                case '3':
                    newQueArr();
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

void TUI::newQueArr() {
    printTopInfo("QUEUE -> ON ARRAY -> NEW QUEUE", que_arr.getQueueAsString().c_str());
    std::cout << "Enter size of queue: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("QUEUE -> ON ARRAY -> NEW QUEUE", que_arr.getQueueAsString().c_str());
    std::cout << "Initialize queue with random values? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

    que_arr.setQueue(size);
    
    if (initialize == 'y') {
        srand(time(0));
        for (int x=0; x<size; x++) {
            que_arr.enQueue(rand()%100);
        }
    }
}

void TUI::queueOnLL() {
    if (que_ll.getElementCount() == 0) {
        newQueLL();
    }

    while (selection != 'x' || selection != 'X') {
		printTopInfo("QUEUE -> ON LINKED LIST", que_ll.getQueueAsString().c_str());
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Queue\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    printTopInfo("QUEUE -> ON LINKED LIST -> INSERT", que_ll.getQueueAsString().c_str());
                    std::cout << "Enter value to insert: ";
                    std::cin >> input;
                    que_ll.enQueue(input);
                    break;

                case '2':
                    que_ll.deQueue();
                    break;

                case '3':
                    newQueLL();
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

void TUI::newQueLL() {
    char initialize = '|';

    printTopInfo("QUEUE -> ON LINKED LIST -> NEW QUEUE", que_ll.getQueueAsString().c_str());
    std::cout << "Initialize queue with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (que_ll.getElementCount() != 0) {
    	que_ll.deleteQueue();
	}

    if (initialize == 'y') {
		printTopInfo("QUEUE -> ON LINKED LIST -> NEW QUEUE", que_ll.getQueueAsString().c_str());
		std::cout << "How many nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            que_ll.enQueue(rand()%100);
        }
    }
}


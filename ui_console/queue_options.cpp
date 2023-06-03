#include "tui.h"

void TUI::queueMenu() {
	while (selection != 'x' || selection != 'X') {
		printTopInfo("QUEUE", que_arr.getQueueAsString().c_str());
		std::cout << "1. on Array\n"
				<< "2. on Linked List\n"
				<< "3. on Double Linked List\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
		std::cin >> selection;

        switch (selection) {
            case '1':
                queue(que_arr);
                break;
            case '2':
                queue(que_ll);
                break;
            case '3':
                queue(que_dll);
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }
    }
}

template <typename O>
void TUI::queue(O& queue) {
    std::string queueHeading, str;

    if (typeid(queue) == typeid(que_arr) && que_arr.getSize() == 0) {
        newQueArr();
    }
    else if (queue.getElementCount() == 0) {
        newQueLL(queue);
    }

    if (typeid(queue) == typeid(que_arr)) {
        queueHeading = "QUEUE -> ON ARRAY";
    }
    else if (typeid(queue) == typeid(que_ll)) {
        queueHeading = "QUEUE -> ON LINKED LIST";
    }
    else if (typeid(queue) == typeid(que_dll)) {
        queueHeading = "QUEUE -> ON DOUBLE LINKED LIST";
    }

    while (selection != 'x' || selection != 'X') {
		printTopInfo(queueHeading.c_str(), queue.getQueueAsString().c_str());
        std::cout << "1. Insert\n"
                << "2. Delete\n"
                << "3. New Queue\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
                << "Select an operation: ";
        std::cin >> selection;

        try {
            switch (selection) {
                case '1':
                    str = queueHeading + " -> INSERT";
                    printTopInfo(str.c_str(), queue.getQueueAsString().c_str());
                    std::cout << "Enter value to push: ";
                    std::cin >> input;
                    queue.enQueue(input);
                    break;

                case '2':
                    queue.deQueue();
                    break;

                case '3':
                    if (typeid(queue) == typeid(queue))
                        newQueArr();
                    else
                        newQueLL(queue);
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
    printTopInfo("QUEUE -> ON ARRAY -> NEW QUEUE", "-");
    std::cout << "Enter size of queue: ";
    std::cin >> size;

    if (size < 1 && size > 1000) {
        std::cout << "Size must be in the range 1-1000.\n";
        return;
    }

    char initialize = '|';

    printTopInfo("QUEUE -> ON ARRAY -> NEW QUEUE", "-");
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

template <typename T>
void TUI::newQueLL(T& queue) {
    char initialize = '|';
    std::string queueHeading;

    if (typeid(queue) == typeid(que_ll)) {
        queueHeading = "QUEUE -> ON ARRAY -> NEW QUEUE";
    }
    else if (typeid(queue) == typeid(que_dll)) {
        queueHeading = "QUEUE -> ON DOUBLE LINKED LIST -> NEW QUEUE";
    }

    printTopInfo(queueHeading.c_str(), "-");
    std::cout << "Initialize queue with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (queue.getElementCount() != 0) {
    	queue.deleteQueue();
	}

    if (initialize == 'y') {
		printTopInfo(queueHeading.c_str(), "-");
		std::cout << "How many elements/nodes should we generate?: ";
    	std::cin >> size;

		if (size < 1 && size > 1000) {
			std::cout << "Random elements/nodes must be in the range 1-1000.\n";
			return;
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            queue.enQueue(rand()%100);
        }
    }
}


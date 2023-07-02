#include "tui.h"

void TUI::BSTMenu() {
	if (treeBinSearch.getElementCount() == 0) {
		newBST();
	}

	while (selection != 'x' || selection != 'X') {
        printTopInfo(
            "BINARY SEARCH TREE",
            treeBinSearch.getTreeAsString(traversal).c_str(),
            NULL
        );

		std::cout << "1. Insert node\n"
				<< "2. Delete\n"
				<< "3. Search\n"
				<< "4. Change traverse method\n"
				<< "5. New Tree\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
				printTopInfo("BINARY SEARCH TREE -> INSERT NODE", "-", NULL);
				std::cout << "Enter value to insert: ";
				std::cin >> input;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					invalidInput("Invalid Input!");
					break;
				}
				treeBinSearch.insert(input);
                break;
				
            case '2':
                std::cout << "Enter value to delete from BS tree: ";
                std::cin >> input;

                try {
                    treeBinSearch.remove(input);
                } catch (const char* e) {
                    std::string error = std::string("Exception: ")+e;
                    invalidInput(error.c_str());
                }
                break;

            case '3':
                BSTSearch();
                break;

            case '4':
                changeTraversalBST();
                break;

            case '5':
                newBST();
                break;

            case 'x': case 'X':
                system(clear);
                return;
                
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::changeTraversalBST() {
	while (selection != 'x' || selection != 'X') {
        printTopInfo (
            "BINARY SEARCH TREE -> CHANGE TRAVERSE METHOD",
            treeBinSearch.getTreeAsString(traversal).c_str(),
            NULL
        );

		std::cout << "1. In-Order Traversal\n"
				<< "2. Pre-Order Traversal\n"
				<< "3. Post-Order Traversal\n"
				<< "4. Breadth-First Traversal\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
				traversal = IN_ORDER;
                break;
				
            case '2':
				traversal = PRE_ORDER;
                break;

            case '3':
				traversal = POST_ORDER;
                break;

            case '4':
				traversal = BREADTH_FIRST;
                break;

            case 'x': case 'X':
                return;
                
            default:
                invalidInput("Invalid selection!");
        }
    }
}


void TUI::newBST() {
    char initialize = '|';

    printTopInfo("BINARY SEARCH TREE -> NEW TREE", "-", NULL);
    std::cout << "Initialize BS tree with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (treeBinSearch.getElementCount() != 0) {
    	treeBinSearch.deleteTree();
	}

    if (initialize == 'y') {
		size = 0;
		while (size > 20 || size < 1) {
			printTopInfo("BINARY SEARCH TREE -> NEW TREE", "-", NULL);
			std::cout << "How many nodes should we generate?: ";
			std::cin >> size;

			if (size < 1 || size > 20) {
				invalidInput("Random nodes must be in the range 1-20.");
			}
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            treeBinSearch.insert(rand()%100);
        }
    }
}

void TUI::BSTSearch() {
    printTopInfo("BINARY SEARCH TREE -> SEARCH", treeBinSearch.getTreeAsString(traversal).c_str(), NULL);
    std::cout << "Enter value to search in binary search tree: ";
    std::cin >> input;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        invalidInput("Invalid Input!");
        return;
    }

    if (treeBinSearch.singleSearchFor(input))
        std::cout << input << " found in binary search tree.\n";
    else
        std::cout << input << " not found in binary search tree.\n";
    system(pause);
}







#include "tui.h"

void TUI::AVLMenu() {
	if (treeAvl.getElementCount() == 0) {
		newAVL();
	}

	while (selection != 'x' || selection != 'X') {
        std::string height = "Height: " + std::to_string(treeAvl.getHeight());
        printTopInfo(
            "AVL BINARY TREE",
            treeAvl.getTreeAsString(traversal).c_str(),
            height.c_str()
        );

		std::cout << "1. Insert node\n"
				<< "2. Delete\n"
				<< "3. Search\n"
				<< "4. Change traverse method\n"
				<< "5. New AVL\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
				printTopInfo("AVL BINARY TREE -> INSERT NODE", "-", NULL);
				std::cout << "Enter value to insert: ";
				std::cin >> input;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					invalidInput("Invalid Input!");
					break;
				}
				treeAvl.insert(input);
                break;
				
            case '2':
                std::cout << "Enter value to delete from BS tree: ";
                std::cin >> input;

                try {
                    treeAvl.remove(input);
                } catch (const char* e) {
                    std::string error = std::string("Exception: ")+e;
                    invalidInput(error.c_str());
                }
                break;

            case '3':
                AVLSearch();
                break;

            case '4':
                changeTraversalAVL();
                break;

            case '5':
                newAVL();
                break;

            case 'x': case 'X':
                system(clear);
                return;
                
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::changeTraversalAVL() {
	while (selection != 'x' || selection != 'X') {
        printTopInfo (
            "AVL BINARY TREE -> CHANGE TRAVERSE METHOD",
            treeAvl.getTreeAsString(traversal).c_str(),
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


void TUI::newAVL() {
    char initialize = '|';

    printTopInfo("AVL BINARY TREE -> NEW TREE", "-", NULL);
    std::cout << "Initialize AVL binary tree with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (treeAvl.getElementCount() != 0) {
    	treeAvl.deleteTree();
	}

    if (initialize == 'y') {
		size = 0;
		while (size > 20 || size < 1) {
			printTopInfo("AVL BINARY TREE -> NEW TREE", "-", NULL);
            std::cout << "size: " << size;
			std::cout << "How many nodes should we generate?: ";
			std::cin >> size;

			if (size < 1 || size > 20) {
				invalidInput("Random nodes must be in the range 1-20.");
			}
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            treeAvl.insert(rand()%100);
        }
    }
}

void TUI::AVLSearch() {
    printTopInfo("AVL BINARY TREE -> SEARCH", treeAvl.getTreeAsString(traversal).c_str(), NULL);
    std::cout << "Enter value to search in AVL binary search tree: ";
    std::cin >> input;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        invalidInput("Invalid Input!");
        return;
    }

    if (treeAvl.singleSearchFor(input))
        std::cout << input << " found in AVL binary search tree.\n";
    else
        std::cout << input << " not found in AVL binary search tree.\n";
    system(pause);
}







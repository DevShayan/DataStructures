#include "tui.h"

void TUI::treeMenu() {
	if (tree.getElementCount() == 0) {
		// newTree();
	}

	while (selection != 'x' || selection != 'X') {
        std::string info = "width: " + std::to_string(tree.getMaxWidth());
        printTopInfo("BINARY TREE",
            tree.getTreeAsString(TreeBinary<int>::IN_ORDER).c_str(),
            info.c_str()
        );
		std::cout << "1. Insert node\n"
				<< "!. Delete\n"
				<< "!. New Tree\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
				printTopInfo("BINARY TREE -> INSERT NODE", "-", NULL);
				std::cout << "Enter value to insert: ";
				std::cin >> input;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					invalidInput("Invalid Input!");
					break;
				}
				tree.insert(input);
                break;
				
            case '2':
                // delete();
                break;

            case '3':
                // newTree();
                break;

            case 'x': case 'X':
                system(clear);
                return;
                
            default:
                invalidInput("Invalid selection!");
        }
    }
}


void TUI::newTree() {
    char initialize = '|';

    printTopInfo("BINARY TREE -> NEW TREE", "-", NULL);
    std::cout << "Initialize binary tree with random nodes? [y/n]: ";
    std::cin >> initialize;

    if (!std::isalpha(initialize)) {
        invalidInput("Invalid input!");
        return;
    }

	if (tree.getElementCount() != 0) {
    	// tree.deleteTree();
	}

    if (initialize == 'y') {
		size = 0;
		while (size > 10 || size < 1) {
			printTopInfo("BINARY TREE -> NEW TREE", "-", NULL);
			std::cout << "How many nodes should we generate?: ";
			std::cin >> size;

			if (size < 1 && size > 10) {
				invalidInput("Random nodes must be in the range 1-10.");
			}
		}

        srand(time(0));
        for (int x=0; x<size; x++) {
            tree.insert(rand()%100);
        }
    }
}





#include "tui.h"

void TUI::treeMenu() {
	// if (tree.getElementCount() == 0) {
	// 	newTree();
	// }

	while (selection != 'x' || selection != 'X') {
        std::string height = "Height: " + std::to_string(tree.getHeight());
        printTopInfo(
            "BINARY TREE",
            tree.getTreeAsString(traversal).c_str(),
            height.c_str()
        );

		std::cout << "1. Create Tree\n"
				<< "2. Delete\n"
				<< "3. Search\n"
				<< "4. Change traverse method\n"
				<< "5. New Tree\n\n"
                << magenta << "X. Back\n\n" << clearTextColor
				<< "Select an operation: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
				printTopInfo("BINARY TREE -> CREATE TREE", "-", NULL);
				tree.createTree();
                break;
				
            case '2':
                std::cout << "Enter value to delete from tree: ";
                std::cin >> input;

                try {
                    tree.remove(input);
                } catch (const char* e) {
                    std::string error = std::string("Exception: ")+e;
                    invalidInput(error.c_str());
                }
                break;

            case '3':
                treeSearch();
                break;

            case '4':
                changeTraversal();
                break;

            case '5':
                newTree();
                break;

            case 'x': case 'X':
                system(clear);
                return;
                
            default:
                invalidInput("Invalid selection!");
        }
    }
}

void TUI::changeTraversal() {
	while (selection != 'x' || selection != 'X') {
        printTopInfo (
            "BINARY TREE -> CHANGE TRAVERSE METHOD",
            tree.getTreeAsString(traversal).c_str(),
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


void TUI::newTree() {
    printTopInfo("BINARY TREE -> NEW TREE", "-", NULL);

	if (tree.getElementCount() != 0) {
    	tree.deleteTree();
	}

    tree.createTree();
}

void TUI::treeSearch() {
    printTopInfo("BINARY TREE -> SEARCH", tree.getTreeAsString(traversal).c_str(), NULL);
    std::cout << "Enter value to search in binary tree: ";
    std::cin >> input;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        invalidInput("Invalid Input!");
        return;
    }

    if (tree.singleSearchFor(input))
        std::cout << input << " found in binary tree.\n";
    else
        std::cout << input << " not found in binary tree.\n";
    system(pause);
}






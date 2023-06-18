#include "tui.h"
#include "queue_options.cpp"
#include "stack_options.cpp"
#include "ll_options.cpp"
#include "tree_options.cpp"

TUI::TUI() {
    //
}

void TUI::invalidInput(const char* input) {
    std::cout << '\n' << red << input << clearTextColor << '\n';
    std::cout << "Press \"Enter\" to continue...\n";
    system(pause);
}

void TUI::printTopInfo(const char* path, const char* list, const char* info) {
    system(clear);
    std::cout << magenta << path << "\n\n"
        << list << clearTextColor << "\n\n";

    if (info != NULL) {
        std::cout << gray << info << clearTextColor << "\n\n";
    }

}

void TUI::start() {

    while (selection != 'x' || selection != 'X') {
        system(clear);
        std::cout << magenta << projectTitle << clearTextColor;
        std::cout << "1. Queue\n";
        std::cout << "2. Stack\n";
        std::cout << "3. Array\n";
        std::cout << "4. Linked List\n";
        std::cout << "5. Binary Tree\n\n";
        std::cout << magenta << "X. Exit\n\n" << clearTextColor;
        std::cout << "Select an option: ";
        std::cin >> selection;

        switch (selection) {
            case '1':
                queueMenu();
                break;
            case '2':
                stackMenu();
                break;
            case '3':
                array();
                break;
            case '4':
                linkedListMenu();
                break;
            case '5':
                treeMenu();
                break;
            case 'x': case 'X':
                system(clear);
                return;
            default:
                invalidInput("Invalid selection!");
        }

    }
}






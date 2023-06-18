#include "../DataStructures/ui_console/tui.h"
#include "../DataStructures/headers/tree_binary.h"


int main() {

    // TUI ui;
    // ui.start();

    TreeBinary<int> obj = {10, -5, 11, 45, 34};
    // int a;

    // try {
    //     obj.insert(45);
    // }
    // catch (const char* e) {
    //     std::cout << "Exception: " << e << '\n';
    // }

    std::cout << obj.getTreeAsString(TreeBinary<int>::BREADTH_FIRST) << '\n';
    // obj.print2D();
    // std::cout << obj.getTreeAsString(TreeBinary<int>::IN_ORDER) << '\n' << a << '\n';
    
    return 0;
}




#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include <typeinfo>
#include <ctime>
#include "../headers/array_simple.h"
#include "../headers/array_queue.h"
#include "../headers/array_stack.h"
#include "../headers/ll_simple.h"
#include "../headers/ll_queue.h"
#include "../headers/ll_stack.h"
#include "../headers/ll_double.h"
#include "../headers/ll_double_queue.h"
#include "../headers/ll_double_stack.h"
#include "../headers/tree_binary.h"
#include "../headers/tree_binary_search.h"
#include "../headers/avl.h"
#include "../headers/heap_min.h"
#include "../headers/heap_max.h"


class TUI {
    private:
        #ifdef _WIN32
            const char* clear = "cls";
            const char* pause = "pause";
        #else
            const char* clear = "clear";
            const char* pause = "read dummy";
        #endif
        const char* magenta = "\033[35m";
        const char* red = "\033[31m";
        const char* yellow = "\033[33m";
        const char* gray = "\033[90m";
        const char* clearTextColor = "\033[0m";

        ArraySimple<int> arr;
        ArrayQueue<int> que_arr;
        ArrayStack<int> stack_arr;
        LLSimple<int> ll;
        LLQueue<int> que_ll;
        LLStack<int> stack_ll;
        LLDouble<int> dll;
        LLDoubleQue<int> que_dll;
        LLDoubleStack<int> stack_dll;
        TreeBinary<int> tree;
        TreeBinarySearch<int> treeBinSearch;
        AVL<int> treeAvl;
        HeapMin<int> heapMin;
        HeapMax<int> heapMax;

        const std::string projectTitle = "  ___  ___   _     ___ ___  ___     _ ___ ___ _____ \n |   \\/ __| /_\\   | _ \\ _ \\/ _ \\ _ | | __/ __|_   _|\n | |) \\__ \\/ _ \\  |  _/   / (_) | || | _| (__  | |  \n |___/|___/_/ \\_\\ |_| |_|_\\\\___/ \\__/|___\\___| |_|  \n                                                    \n";
        const int lb = 0;
        int size = 0;
        int elements = 0;
        int input, input2;
        char selection = '|';

        enum Traversals {
            IN_ORDER,
            PRE_ORDER,
            POST_ORDER,
            BREADTH_FIRST,
        };

        Traversals traversal = IN_ORDER;

    public:
        TUI();

        // array
        void start();
        void array();
        void insertion();
        void deletion();
        void deletionItem();
        void search();
        char searchingMenu();
        void singleSearch();
        void multiSearch();
        void sort();
        void newArray();
        void merging();

        // queue
        void queueMenu();
        template <typename O> void queue(O& queue);
        void newQueArr();
        template <typename T> void newQueLL(T& queue);

        // stack
        void stackMenu();
        template <typename T> void stack(T& stack);
        void newStackArr();
        template <typename T> void newStackLL(T& stack);

        // linked list
        void linkedListMenu();
        template <typename T> void linkedList(T& list);
        template <typename T> void llInsert(T& list);
        template <typename T> void llDelete(T& list);
        template <typename T> void llSearch(T& list);
        template <typename T> void newList(T& list);

        // binary tree
        void treeMenu();
        void newTree();
        void changeTraversal();
        void treeSearch();

        // binary search tree
        void BSTMenu();
        void newBST();
        void changeTraversalBST();
        void BSTSearch();

        // AVL tree
        void AVLMenu();
        void newAVL();
        void changeTraversalAVL();
        void AVLSearch();

        // heap
        void heapMenu();
        template <typename T> void heapX(T& heap);
        template <typename T> void heapInsert(T& heap);
        template <typename T> void heapSearch(T& heap);
        template <typename T> void heapSingleSearch(T& heap);
        template <typename T> void heapMultiSearch(T& heap);
        template <typename T> void newHeap(T& heap);

        // mics
        void invalidInput(const char* input);
        void printTopInfo(const char* path, const char* list, const char* info);
};

#endif
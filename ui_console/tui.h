#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include "../headers/array_simple.h"
#include "../headers/array_queue.h"
#include "../headers/array_stack.h"
#include "../headers/ll_simple.h"
#include "../headers/ll_double.h"


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
        const char* clearTextColor = "\033[0m";

        ArraySimple<int> arr;
        ArrayQueue<int> que_arr;
        ArrayStack<int> stack_arr;
        LLSimple<int> ll;

        const std::string projectTitle = "  ___  ___   _     ___ ___  ___     _ ___ ___ _____ \n |   \\/ __| /_\\   | _ \\ _ \\/ _ \\ _ | | __/ __|_   _|\n | |) \\__ \\/ _ \\  |  _/   / (_) | || | _| (__  | |  \n |___/|___/_/ \\_\\ |_| |_|_\\\\___/ \\__/|___\\___| |_|  \n                                                    \n";
        const int lb = 0;
        int size = 0;
        int elements = 0;
        int input;
        int index;
        char selection = '|';

    public:
        TUI();

        // array
        void start();
        void array();
        void insertion();
        void deletion();
        void search();
        char searchingMenu();
        void singleSearch();
        void multiSearch();
        void sort();

        void push(bool isStack);

        // queue
        void queue();
        void queueOnArray();
        void queueOnLL();

        // stack
        void stack();
        void stackOnArray();
        void stackOnLL();

        // linked list
        void linkedList();

        // mics
        void invalidInput(const char* input);
        void printTopInfo(const char* path, const char* list);
};

#endif
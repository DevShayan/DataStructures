#!/bin/bash
# g++ main.cpp ./ui_console/console_ui.cpp ./templates/main_page.cpp -o main.out
g++ main.cpp ./ui_console/tui.cpp ./ui_console/array_options.cpp -o main.out
./main.out
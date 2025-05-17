@echo off
echo Building Tree GUI application...

REM Compile the main application with all the necessary files
gcc -Wall -o tree_gui main.c functions_wrapper.c code_utils.c tree_utils.c recursion_utils.c -mwindows -lcomctl32

echo Build complete. Run tree_gui.exe to start the application.

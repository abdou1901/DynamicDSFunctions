@echo off
echo Building GUI application...

REM Compile the main application with all the necessary files
gcc -Wall -o GUI main.c functions_wrapper.c code_utils.c tree_utils.c recursion_utils.c code.c -mwindows -lcomctl32

echo Build complete. Run GUI.exe to start the application.

@echo off
echo Running Data Structures GUI...

REM Set path to GTK3 DLLs - Make sure to adjust this path if needed
set PATH=C:\msys64\ucrt64\bin;%PATH%

REM Check if the executable exists
if not exist ds_functions_gui.exe (
    echo Executable not found. Compiling first...
    call compile.bat
    if %ERRORLEVEL% NEQ 0 (
        echo Compilation failed. Cannot run the application.
        pause
        exit /b 1
    )
)

REM Run the application
start ds_functions_gui.exe
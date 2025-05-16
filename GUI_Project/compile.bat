@echo off
echo Compiling GTK3 application...

REM Set paths to GTK3 - adjust to your UCRT64 installation path
set GTK_DIR=C:\msys64\ucrt64

REM Set include and library paths
set INCLUDE_DIRS=-I"%GTK_DIR%\include\gtk-3.0" -I"%GTK_DIR%\include\cairo" -I"%GTK_DIR%\include\pango-1.0" -I"%GTK_DIR%\include\atk-1.0" -I"%GTK_DIR%\include\gdk-pixbuf-2.0" -I"%GTK_DIR%\include\glib-2.0" -I"%GTK_DIR%\lib\glib-2.0\include" -I"%GTK_DIR%\include" -I"%GTK_DIR%\include\harfbuzz" -I"%GTK_DIR%\include\freetype2" -I"%GTK_DIR%\include\libpng16" -I"%GTK_DIR%\include\fribidi" -I"include" -I"."

set LIB_DIRS=-L"%GTK_DIR%\lib"

set LIBS=-lgtk-3 -lgdk-3 -lgdi32 -limm32 -lshell32 -lole32 -luuid -lpangocairo-1.0 -lpangoft2-1.0 -lfreetype -lfontconfig -lpangowin32-1.0 -lgdi32 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 -lintl -lharfbuzz

REM Echo the command for debugging
echo Compiling with command:
echo gcc -o ds_functions_gui.exe src\main.c lib\trees.c lib\code.c lib\recursion_2.c %INCLUDE_DIRS% %LIB_DIRS% %LIBS% -mwindows

REM Compile the application - using gcc directly without path to make it more portable
gcc -o ds_functions_gui.exe src\main.c lib\trees.c lib\code.c lib\recursion_2.c %INCLUDE_DIRS% %LIB_DIRS% %LIBS% -mwindows

if %ERRORLEVEL% EQU 0 (
    echo Compilation successful!
) else (
    echo Compilation failed.
    pause
    exit /b 1
)
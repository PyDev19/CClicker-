# Set variables for directories and files
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
COMPILED_DIR=$BUILD_DIR/obj
APP_DIR=$BUILD_DIR/app

# Compile the cpp files in colors folder
echo 'Compiling all c++ files...'
x86_64-w64-mingw32-g++ -I$INCLUDE_DIR -c $SRC_DIR/colors.cpp -o $COMPILED_DIR/colors.o
x86_64-w64-mingw32-g++ -I$INCLUDE_DIR -c $SRC_DIR/key.cpp -o $COMPILED_DIR/key.o
x86_64-w64-mingw32-g++ -I$INCLUDE_DIR -c $SRC_DIR/clicker.cpp -o $COMPILED_DIR/clicker.o
x86_64-w64-mingw32-g++ -I$INCLUDE_DIR -c $SRC_DIR/prompts.cpp -o $COMPILED_DIR/prompts.o
x86_64-w64-mingw32-g++ -I$INCLUDE_DIR -c $SRC_DIR/main.cpp -o $COMPILED_DIR/main.o
echo 'Done'

# Link all object files and resource file
echo 'Linking all object and resource files...'
x86_64-w64-mingw32-g++ $COMPILED_DIR/*.o icon.res -o $APP_DIR/CClicker++.exe
echo 'Done'

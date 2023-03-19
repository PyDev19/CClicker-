# Set variables for directories and files
SOURCE_DIR=src
CLASS_DIR=$SOURCE_DIR/classes
BUILD_DIR=build
COMPILED_DIR=$BUILD_DIR/compiled_files
APP_DIR=$BUILD_DIR/app

# Compile the cpp files in classes folder
echo 'Compiling c++ files in ' $CLASS_DIR ' directory...'
g++ -I$CLASS_DIR -c $CLASS_DIR/clicker.cpp -o $COMPILED_DIR/clicker.o
g++ -I$CLASS_DIR -c $CLASS_DIR/key.cpp -o $COMPILED_DIR/key.o
echo 'Done'

# Compile the cpp files in src folder
echo 'Compiling c++ files in ' $SOURCE_DIR ' directory...'
g++ -I$SOURCE_DIR -c $SOURCE_DIR/main.cpp -o $COMPILED_DIR/main.o
g++ -c $SOURCE_DIR/prompts.cpp -o $COMPILED_DIR/prompts.o
echo 'Done'

# Link all object files and resource file
echo 'Linking all object and resource files...'
g++ $COMPILED_DIR/*.o icon.res -o $APP_DIR/CClicker++.exe
echo 'Done'

# Set variables for directories and files
SOURCE_DIR=src
KEY_DIR=$SOURCE_DIR/key
CLICKER_DIR=$SOURCE_DIR/clicker
PROMPTS_DIR=$SOURCE_DIR/prompts
COLORS_DIR=$SOURCE_DIR/colors

BUILD_DIR=build
COMPILED_DIR=$BUILD_DIR/compiled_files
APP_DIR=$BUILD_DIR/app

# Compile the cpp files in key folder
echo 'Compiling c++ files in ' $KEY_DIR ' directory...'
g++ -I$KEY_DIR -c $KEY_DIR/key.cpp -o $COMPILED_DIR/key.o
echo 'Done'

# Compile the cpp files in clicker folder
echo 'Compiling c++ files in ' $CLICKER_DIR ' directory...'
g++ -I$CLICKER_DIR -c $CLICKER_DIR/clicker.cpp -o $COMPILED_DIR/clicker.o
echo 'Done'

# Compile the cpp files in prompts folder
echo 'Compiling c++ files in ' $PROMPTS_DIR ' directory...'
g++ -I$KEY_DIR -I$PROMPTS_DIR -c $PROMPTS_DIR/prompts.cpp -o $COMPILED_DIR/prompts.o
echo 'Done'

# Compile the cpp files in colors folder
echo 'Compiling c++ files in ' $COLORS_DIR ' directory...'
g++ -I$COLORS_DIR -c $COLORS_DIR/colors.cpp -o $COMPILED_DIR/colors.o
echo 'Done'

# Compile the cpp files in src folder
echo 'Compiling c++ files in ' $SOURCE_DIR ' directory...'
g++ -c $SOURCE_DIR/main.cpp -o $COMPILED_DIR/main.o
echo 'Done'

# Link all object files and resource file
echo 'Linking all object and resource files...'
g++ $COMPILED_DIR/*.o icon.res -o $APP_DIR/CClicker++.exe
echo 'Done'

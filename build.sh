g++ -Isrc/classes -c src/classes/clicker.cpp -o build/compiled_files/clicker.o
g++ -Isrc/classes -c src/classes/key.cpp -o build/compiled_files/key.o

g++ -Isrc -c src/prompts.cpp -o build/compiled_files/prompts.o
g++ -c src/main.cpp -o build/compiled_files/main.o

g++ build/compiled_files/*.o icon.res -o build/app/CClicker++.exe
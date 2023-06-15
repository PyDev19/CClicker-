# Build app using cmake and make
mingw64-cmake .
make .

# Move exe to build folder
cp CClicker++.exe build/CClicker++.exe

# Move lib dlls to build folder
cp -r libs/* build/

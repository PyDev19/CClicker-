# Build app using cmake and make
mingw64-cmake
mingw64-make

# Move exe to build folder
mv CClicker++.exe build/CClicker++.exe

# Move lib dlls to build folder
cp -r libs/* build/

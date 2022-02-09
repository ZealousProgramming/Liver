@echo off
if not exist build (mkdir build)
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Debug -DBUILD_TARGET=Sellas -G "MinGW Makefiles"
mingw32-make
cd ..
REM start run.bat & exit
REM start run.bat

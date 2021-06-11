# Hexdump     
An application and library to dump and analyze binary files.      

# Installing     
Download the [Latest Release](https://github.com/dibenso/Hexdump/releases).     
Hexdump can also be built from source with CMake to generate an installer executable. See below. After building, the installer file `Hexdump-<version>-<architecture>.exe` will be generated in the `build` directory.     

# Running
```sh
./<path-to-Hexdump-installation-dir>/bin/Hexdump.exe -i <input-file>
```

# Building with Windows      
### Clone and run CMake     
```sh
git clone git@github.com:dibenso/Hexdump.git
cd Hexdump
mkdir build
cd build
# replace -G option with your platforms generator
# See: https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html
# Example with Visual Studio:
cmake -G "Visual Studio 16 2019" -A x64 ..
```      
### Generate the installer     
* Install [NSIS](https://nsis.sourceforge.io/Download) (Nullsoft Scriptable Install System).     
* Open `Hexdump.sln` with Visual Studio     
* Change `Debug` to `Release`    
* Build `Hexdump`     
* Build `PACKAGE`     

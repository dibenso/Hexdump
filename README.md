# Hexdump     
An application and library to dump and analyze binary files.  

![Hexdump](screenshot.jpg?raw=true "Hexdump")
![Hexdump build status](https://github.com/dibenso/Hexdump/actions/workflows/cmake.yml/badge.svg "Hexdump build status")

# Download [![Hexdump Download Count](https://img.shields.io/github/downloads/dibenso/Hexdump/total)](https://tooomm.github.io/github-release-stats/?username=dibenso&repository=Hexdump)        

Download the [Latest Release](https://github.com/dibenso/Hexdump/releases).         

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
* The installer, `Hexdump-<version>-<architecture>.exe`, should be generated in the `build` directory

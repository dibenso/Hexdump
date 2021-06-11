# Hexdump     
A tool to dump and analyze binary files     

# Building
```sh
git clone git@github.com:dibenso/Hexdump.git
cd Hexdump
cd build
# replace -G option with your platforms generator
# See: https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html
# Example with Visual Studio:
cmake -G "Visual Studio 16 2019" -A x64 ..
```

# Running
```sh
./build/Hexdump -i <input-file>
```
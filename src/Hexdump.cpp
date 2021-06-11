#include "Hexdump.h"

Hexdump::Hexdump() : _input_file(nullptr), _has_input_file(false) {}
Hexdump::Hexdump(std::string input_file) : _input_file(input_file), _has_input_file(true) {}
Hexdump::Hexdump(const char* input_file) { Hexdump(std::string(input_file)); }
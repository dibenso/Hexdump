#include <iostream>
#include <string>
#include <fstream>
#include "Hexdump.h"

HexdumpOptions::HexdumpOptions() : _input_file(""), _output_file("") {}
HexdumpOptions::HexdumpOptions(std::string input_file, std::string output_file) :
  _input_file(input_file),
  _output_file(output_file) {}
std::string HexdumpOptions::input_file() { return _input_file; }
std::string HexdumpOptions::output_file() { return _output_file; }
bool HexdumpOptions::has_input_file() { return !_input_file.empty() && _input_file != ""; }
bool HexdumpOptions::has_output_file() { return !_output_file.empty() && _output_file != ""; }

template<typename T> void int_to_hex2(T i, char* hex_str) {
  sprintf(hex_str, "%02x", i);
}

template<typename T> void int_to_hex6(T i, char* hex_str) {
  sprintf(hex_str, "%06x", i);
}

void print_bytes_line(unsigned int offset, char* hex_str, std::string line, std::string bytes) {
  std::string padding = "";

  for(int i = 0; i < (48 - line.length()); i++)
      padding.push_back(' ');

  int_to_hex6(offset, hex_str);
  std::cout << hex_str << "  " << line << padding << " " << bytes << std::endl;
}

Hexdump::Hexdump() : _options(HexdumpOptions()) {}
Hexdump::Hexdump(HexdumpOptions options) : _options(options) {}
void Hexdump::print_bytes() {
  // if it's not coming from an input file, then it's coming from STDIN
  if(_options.has_input_file()) {
    char c;
    char hex_str[16];
    uint32_t offset = 0;
    uint8_t char_code;
    uint8_t position = 0;
    std::string bytes;
    std::string line;
    std::ifstream binary_file(_options.input_file(), std::ifstream::binary);

    line.reserve(128);

    while(binary_file.get(c)) {
      char_code = (uint8_t)c;

      if(char_code < 32 || char_code > 126)
        bytes.append(".");
      else
        bytes.push_back(c);

    int_to_hex2(char_code, hex_str);
    line.append(hex_str);
    line.append(" ");

      if(++position % 16 == 0) {
        print_bytes_line(offset, hex_str, line, bytes);

        line = "";
        bytes = "";
        position = 0;
        offset += 16;
      }
    }

    print_bytes_line(offset, hex_str, line, bytes);
  }
}

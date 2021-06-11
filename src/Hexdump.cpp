#include <iostream>
#include <string>
#include <fstream>
#include "Hexdump.h"

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

Hexdump::Hexdump() : _input_file(nullptr), _has_input_file(false) {}
Hexdump::Hexdump(std::string input_file) : _input_file(input_file), _has_input_file(true) {}
Hexdump::Hexdump(const char* input_file) { Hexdump(std::string(input_file)); }
void Hexdump::print_bytes() {
  char c;
  char hex_str[16];
  uint32_t offset = 0;
  uint8_t char_code;
  uint8_t position = 0;
  std::string bytes;
  std::string line;
  std::ifstream binary_file(_input_file, std::ifstream::binary);

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
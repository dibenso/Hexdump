#include <iostream>
#include <string>
#include <fstream>
#include "CLIArg.h"
#include "CLI.h"
#include "Hexdump.h"

using namespace std;

template<typename T> void int_to_hex2(T, char*);
template<typename T> void int_to_hex6(T, char*);
void print_bytes(string);
void print_bytes_line(uint32_t, char*, string, string);

int main(int argc, char** argv) {
  CLIArg inputArg = CLIArg(
    ArgType::StringArg,
    "--input",
    "-i",
    "Specifies the path of the file to read binary data from"
  );
  CLIArg outputArg = CLIArg(
    ArgType::StringArg,
    "--output",
    "-o",
    "Specifies the path of the file to output hex dump to"
  );
  CLIArg args[2] = { inputArg, outputArg };
  CLI cli = CLI(args, argc, argv);

  cli.parse();

  CLIArg input_file = cli["--input"];

  if(input_file.resolved()) {
    Hexdump hexdump = Hexdump(input_file.value());
    
    print_bytes(input_file.value());
  }
  else
    cout << "No input file specified" << endl;

  return 0;
}

template<typename T> void int_to_hex2(T i, char* hex_str) {
  sprintf(hex_str, "%02x", i);
}

template<typename T> void int_to_hex6(T i, char* hex_str) {
  sprintf(hex_str, "%06x", i);
}

void print_bytes(string input_file) {
  char c;
  char hex_str[16];
  uint32_t offset = 0;
  uint8_t char_code;
  uint8_t position = 0;
  string bytes;
  string line;
  ifstream binary_file(input_file, std::ifstream::binary);

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

void print_bytes_line(uint32_t offset, char* hex_str, string line, string bytes) {
  string padding = "";

  for(int i = 0; i < (48 - line.length()); i++)
      padding.push_back(' ');

  int_to_hex6(offset, hex_str);
  cout << hex_str << "  " << line << padding << " " << bytes << endl;
}
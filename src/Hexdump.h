#ifndef _HEXDUMP_H_
#define _HEXDUMP_H_

#include <string>

typedef struct HexdumpOptions {
  private:
    std::string _input_file;
    std::string _output_file;
  public:
    HexdumpOptions();
    HexdumpOptions(std::string input_file, std::string output_file);
    std::string input_file();
    std::string output_file();
    bool has_input_file();
    bool has_output_file();
} HexdumpOptions;

class Hexdump {
  private:
    HexdumpOptions _options;
  public:
    Hexdump();
    Hexdump(HexdumpOptions options);
    void print_bytes();
};

#endif
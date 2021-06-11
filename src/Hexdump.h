#ifndef _HEXDUMP_H_
#define _HEXDUMP_H_

#include <string>

class Hexdump {
  private:
    std::string _input_file;
    bool _has_input_file;
  public:
    Hexdump();
    Hexdump(std::string input_file);
    Hexdump(const char* input_file);
};

#endif
#ifndef _CLI_H_
#define _CLI_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "CLIArg.h"

class CLI {
  private:
    bool _parsed;
    int _argc;
    std::vector<std::string> _argv;
    std::unordered_map<std::string, CLIArg> _arg_set;
    void init(int argc, char** argv);
  public:
    CLI(std::vector<CLIArg>* arg_vector, int argc, char** argv);
    CLI(CLIArg* arg_array, int argc, char** argv);
    void parse();
    inline bool parsed() { return _parsed; }
    inline bool no_args() { _argc == 1; }
    CLIArg operator[](const char* arg_name);
    std::string binary_name();
};

#endif
#ifndef _CLI_ARG_H_
#define _CLI_ARG_H_

#include <string>

enum ArgType {
  NoArg,
  BooleanArg,
  IntArg,
  FloatArg,
  DoubleArg,
  CharArg,
  StringArg,
  RangeArg
};

class CLIArg {
  private:
    ArgType _arg_type;
    bool _resolved;
    std::string _value;
    std::string _long_name;
    std::string _short_name;
    std::string _description;
  public:
    CLIArg(ArgType arg_type, const char* long_name, const char* short_name, const char* description);
    inline ArgType arg_type() { return _arg_type; }
    inline bool resolved() { return _resolved; }
    inline std::string value() { return _value; }
    inline std::string long_name() { return _long_name; }
    inline std::string short_name() { return _short_name; }
    inline void resolve() { _resolved = true; }
    void resolve(std::string value);
    bool operator==(CLIArg arg);
};

#endif
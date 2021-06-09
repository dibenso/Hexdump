
#include "CLIArg.h"

CLIArg::CLIArg(ArgType arg_type, const char *long_name, const char *short_name, const char* description) :
  _arg_type(arg_type),
  _long_name(long_name),
  _short_name(short_name),
  _description(description) {}
void CLIArg::resolve(std::string value) {
  resolved();

  _value = value;
}
bool CLIArg::operator==(CLIArg arg) { return _long_name == arg.long_name() || _short_name == arg.short_name(); }
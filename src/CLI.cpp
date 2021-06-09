#include "CLI.h"

void CLI::init(int argc, char** argv) {
  _argc = argc;
  _parsed = false;

  for(int i = 0; i < argc; i++)
    _argv.push_back(argv[i]);
}
CLI::CLI(std::vector<CLIArg>* arg_vector, int argc, char** argv) {
  init(argc, argv);

  for(auto it = arg_vector->begin(); it != arg_vector->end(); ++it)
    _arg_set.insert(std::make_pair(it->long_name(), *it));
}
CLI::CLI(CLIArg* args, int argc, char** argv) {
  int length = sizeof(*args) / sizeof(args[0]);

  init(argc, argv);

  for(int i = 0; i < length; i++)
    _arg_set.insert(std::make_pair(args[0].long_name(), args[0]));
}
void CLI::parse() {
  if(_parsed)
    return;

  int i = 0;

  while(i < _argc) {
    for(auto& arg: _arg_set) {
      if(arg.second.long_name() == _argv[i] || arg.second.short_name() == _argv[i]) {
        switch(arg.second.arg_type()) {
          case ArgType::BooleanArg: {
            arg.second.resolve();
            break;
          }
          case ArgType::StringArg: {
            if(i < _argc - 1)
              arg.second.resolve(_argv[++i]);
            
            break;
          }
          default:
            break;
        }
      }

      break;
    }

    i++;
  }

  _parsed = true;
}
CLIArg CLI::operator[](const char* arg_name) {
  for(auto arg: _arg_set) {
    if(arg.second.long_name() == arg_name || arg.second.short_name() == arg_name)
      return arg.second;
  }

  return CLIArg(ArgType::NoArg, NULL, NULL, NULL);
}
std::string CLI::binary_name() { return _argv[0]; }

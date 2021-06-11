#include <iostream>
#include <string>
#include <fstream>
#include "CLIArg.h"
#include "CLI.h"
#include "Hexdump.h"

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
    
    hexdump.print_bytes();
  }
  else
    std::cout << "No input file specified" << std::endl;

  return 0;
}
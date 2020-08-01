#include <iostream>
#include "command_factory.h"

int main(int argc, char *argv[])
{
  vigenere::HelpCommand command = vigenere::GetCommand(argc, argv);
  command.Execute();

  return 0;
}

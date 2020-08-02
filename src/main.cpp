#include <iostream>
#include "command_factory.h"

int main(int argc, char *argv[])
{
  std::unique_ptr<vigenere::Command> command = vigenere::GetCommand(argc, argv);
  command->Execute();

  return 0;
}

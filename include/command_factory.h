#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "help_command.h"

namespace vigenere
{
// forward declaration
class Command;

HelpCommand GetCommand(int argc, char *argv[]);

}

#endif

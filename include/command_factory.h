#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include <memory>

#include "command.h"

namespace vigenere
{

std::unique_ptr<Command> GetCommand(int argc, char *argv[]);

}

#endif

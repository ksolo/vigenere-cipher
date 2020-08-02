#include <string>
#include <iostream>

#include "command_factory.h"
#include "encipher_command.h"
#include "help_command.h"

namespace vigenere
{
std::unique_ptr<Command> GetCommand(int argc, char *argv[])
{
    // commands
    const std::string encipher = "encipher";
    const std::string decipher = "decipher";
    const std::string help = "help";

    if (argc >= 2)
    {
        const std::string command(argv[1]);
        if (command == encipher) { return std::make_unique<EncipherCommand>(); }
    }
    return std::make_unique<HelpCommand>();
}
}

#include <string>
#include <iostream>
#include <vector>

#include "command_factory.h"
#include "decipher_command.h"
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

    if (argc >= 3)
    {
        const std::string command(argv[1]);
        const std::string key(argv[2]);
        std::vector<std::string> files;

        for (int i=3; i < argc; i++)
        {
            files.emplace_back(std::string(argv[i]));
        }

        if (command == encipher) { return std::make_unique<EncipherCommand>(key, files); }
        if (command == decipher) { return std::make_unique<DecipherCommand>(key, files); }
    }
    return std::make_unique<HelpCommand>();
}
}

#include "encipher_command.h"

#include <iostream>

namespace vigenere
{
EncipherCommand::EncipherCommand(const std::string &key, const std::vector<std::string> &files): _key(key)
{
    std::cout << _key.NormalizedKey() << std::endl;
    std::cout << "files: " << std::endl;
    for (auto file : files)
    {
        std::cout << file << std::endl;
    }
}

void EncipherCommand::Execute()
{
    std::cout << "enciphering file..." << std::endl;
    std::cout << "finished file" << std::endl;
}
}

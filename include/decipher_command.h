#ifndef DECIPHER_COMMAND_H
#define DECIPHER_COMMAND_H

#include <string>
#include <vector>

#include "command.h"
#include "key.h"

namespace vigenere
{
class DecipherCommand : public Command
{
public:
    DecipherCommand(const std::string &key, std::vector<std::string> files);
    ~DecipherCommand() override {};
    void Execute() override;
private:
    Key _key;
    std::vector<std::string> _files;

    void DecipherFiles();
};
}

#endif

#ifndef ENCIPHER_COMMAND_H
#define ENCIPHER_COMMAND_H

#include <string>
#include <vector>

#include "command.h"
#include "key.h"

namespace vigenere
{
class EncipherCommand : public Command
{
public:
    EncipherCommand(const std::string &key, const std::vector<std::string> &files);
    ~EncipherCommand() override {};
    void Execute() override;
private:
    Key _key;
};
}

#endif

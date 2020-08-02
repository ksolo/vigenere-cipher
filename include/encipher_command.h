#ifndef ENCIPHER_COMMAND_H
#define ENCIPHER_COMMAND_H

#include "command.h"

namespace vigenere
{
class EncipherCommand : public Command
{
public:
    ~EncipherCommand() override {};
    void Execute() override;
};
}

#endif

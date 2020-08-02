#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include "command.h"

namespace vigenere
{
class HelpCommand : public Command
{
private:
    void EncipherHelp();
    void DecipherHelp();

public:
    ~HelpCommand() override {};
    void Execute() override;
};
}

#endif

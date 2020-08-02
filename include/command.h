#ifndef COMMAND_H
#define COMMAND_H

namespace vigenere
{
class Command
{
public:
    virtual ~Command() {};
    virtual void Execute() = 0;
};
}

#endif

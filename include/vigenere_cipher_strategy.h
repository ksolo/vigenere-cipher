#ifndef VIGENERE_CIPHER_STRATEGY_H
#define VIGENERE_CIPHER_STRATEGY_H

#include <mutex>
#include <string>

#include "key.h"

namespace vigenere
{
class VigenereCipherStrategy
{
public:
    // constructor
    VigenereCipherStrategy(Key key, std::string &file);

private:
    Key _key;
    std::string &_file;
};
}
#endif

#include "vigenere_cipher_strategy.h"

#include <iostream>

namespace vigenere
{
    VigenereCipherStrategy::VigenereCipherStrategy(Key key, std::string &file) : _key(key), _file(file)
    {
        std::cout << "Key: " << _key.NormalizedKey() << std::endl;
        std::cout << "File: " << _file << std::endl;
    };
}

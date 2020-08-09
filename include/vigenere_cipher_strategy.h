#ifndef VIGENERE_CIPHER_STRATEGY_H
#define VIGENERE_CIPHER_STRATEGY_H

#include <fstream>
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
    // destructor
    ~VigenereCipherStrategy();

    // methods
    void Encipher();

private:
    int _enciphered_characters_count {0};
    int _passthrough_characters_count {0};
    int _skipped_characters_count {0};

    Key _key;
    std::string &_input_filename;
    std::fstream _input_file;
    std::fstream _output_file;

    void encipher_line(const std::string &line);
};
}
#endif

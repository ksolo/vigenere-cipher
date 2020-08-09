#ifndef DECIPHER_STRATEGY_H
#define DECIPHER_STRATEGY_H

#include <fstream>
#include <mutex>
#include <string>

#include "key.h"

namespace vigenere
{
class DecipherStrategy
{
public:
    // constructor
    DecipherStrategy(Key key, std::string &file);
    // destructor
    ~DecipherStrategy();

    // methods
    void Decipher();

private:
    int _deciphered_characters_count {0};
    int _passthrough_characters_count {0};
    int _skipped_characters_count {0};

    Key _key;
    std::mutex _mtx;
    std::string &_input_filename;
    std::fstream _input_file;
    std::fstream _output_file;

    void decipher_line(const std::string &line);
    void report();
    char unshift(char letter);
};
}
#endif

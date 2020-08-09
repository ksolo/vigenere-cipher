#ifndef ENCIPHER_STRATEGY_H
#define ENCIPHER_STRATEGY_H

#include <fstream>
#include <mutex>
#include <string>

#include "key.h"

namespace vigenere
{
class EncipherStrategy
{
public:
    // constructor
    EncipherStrategy(Key key, std::string &file);
    // destructor
    ~EncipherStrategy();

    // methods
    void Encipher();

private:
    int _enciphered_characters_count {0};
    int _passthrough_characters_count {0};
    int _skipped_characters_count {0};

    Key _key;
    std::mutex _mtx;
    std::string &_input_filename;
    std::fstream _input_file;
    std::fstream _output_file;

    void encipher_line(const std::string &line);
    void report();
    char shift(char letter);
};
}
#endif

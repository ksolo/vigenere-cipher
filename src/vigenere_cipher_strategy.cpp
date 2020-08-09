#include "vigenere_cipher_strategy.h"

#include <iostream>

namespace vigenere
{
    VigenereCipherStrategy::VigenereCipherStrategy(Key key, std::string &file) :
        _key(key),
        _input_filename(file),
        _input_file(_input_filename)
    {
        std::string output_filename(_input_filename);
        output_filename.replace(output_filename.size() - 4, 4, ".enc.txt");
        _output_file.open(output_filename, std::ios::out);
    };

    VigenereCipherStrategy::~VigenereCipherStrategy()
    {
        _input_file.close();
        _output_file.close();
    }

    void VigenereCipherStrategy::encipher()
    {
        _output_file << "Hello!" << std::endl;
    }
}

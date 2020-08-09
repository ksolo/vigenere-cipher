#include "vigenere_cipher_strategy.h"

#include <iostream>

namespace vigenere
{
VigenereCipherStrategy::VigenereCipherStrategy(Key key, std::string &file) :
    _key(key),
    _input_filename(file),
    _input_file(file)
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

void VigenereCipherStrategy::Encipher()
{
    if (_input_file)
    {
        std::string line;
        while(getline(_input_file, line))
        {
            encipher_line(line);
        }
    } else {
        std::cout << "input file was not found" << std::endl;
    }
}

void VigenereCipherStrategy::encipher_line(const std::string &line)
{
    std::cout << line << std::endl;
    _output_file << line << std::endl;
}
}

#include "vigenere_cipher_strategy.h"

#include <cctype>
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
        std::cout << "input file: " << _input_filename << " was not found" << std::endl;
        return;
    }
    report();
}

void VigenereCipherStrategy::encipher_line(const std::string &line)
{
    std::string enciphered_line = "";
    for(char letter : line)
    {
        letter = tolower(letter);
        if (isnumber(letter) || isspace(letter))
        {
            _passthrough_characters_count++;
            enciphered_line += letter;
        }
        else if (isalpha(letter))
        {
            char shifted_char = shift(letter);
            enciphered_line += shift(letter);
        }
        else {
            _skipped_characters_count++;
        }
    }
    _output_file << enciphered_line << std::endl;
}

char VigenereCipherStrategy::shift(char letter)
{
    std::string normalized_key = _key.NormalizedKey();
    int offset_position = _enciphered_characters_count++ % normalized_key.size();
    char offset_character = normalized_key.at(offset_position);
    char shifted_char = tolower(letter) + (offset_character - alphabet_begin);

    if (shifted_char > alphabet_end) return shifted_char - alphabet_size;
    return shifted_char;
}

void VigenereCipherStrategy::report()
{
    std::cout << "File: " << _input_filename << " has been enchiphered." << std::endl;
    std::cout << "Characters Skipped: " << _skipped_characters_count << std::endl;
    std::cout << "Characters Passed Through: " << _passthrough_characters_count << std::endl;
    std::cout << "Characters Enciphered: " << _enciphered_characters_count << std::endl;
}
}

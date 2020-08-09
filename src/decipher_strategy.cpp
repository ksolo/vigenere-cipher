#include "decipher_strategy.h"

#include <cctype>
#include <iostream>

#include "cipher_alphabet.h"

namespace vigenere
{
DecipherStrategy::DecipherStrategy(Key key, std::string &file) :
    _key(key),
    _input_filename(file),
    _input_file(file)
{
    std::string output_filename(_input_filename);
    output_filename.replace(output_filename.size() - 4, 4, ".dec.txt");

    _output_file.open(output_filename, std::ios::out);
};

DecipherStrategy::~DecipherStrategy()
{
    _input_file.close();
    _output_file.close();
}

void DecipherStrategy::Decipher()
{
    if (_input_file)
    {
        std::string line;
        while(getline(_input_file, line))
        {
            decipher_line(line);
        }
    } else {
        std::lock_guard<std::mutex> lck(_mtx);
        std::cout << "input file: " << _input_filename << " was not found" << std::endl;
        return;
    }
    report();
}

void DecipherStrategy::decipher_line(const std::string &line)
{
    std::string deciphered_line = "";
    for(char letter : line)
    {
        letter = tolower(letter);
        if (isnumber(letter) || isspace(letter))
        {
            _passthrough_characters_count++;
            deciphered_line += letter;
        }
        else if (isalpha(letter))
        {
            deciphered_line += unshift(letter);
        }
        else {
            _skipped_characters_count++;
        }
    }
    _output_file << deciphered_line << std::endl;
}

char DecipherStrategy::unshift(char letter)
{
    std::string normalized_key = _key.NormalizedKey();
    int offset_position = _deciphered_characters_count++ % normalized_key.size();
    char offset_character = normalized_key.at(offset_position);
    char unshifted_char = (tolower(letter) - offset_character) + alphabet_begin;

    if (unshifted_char < alphabet_begin) return unshifted_char + alphabet_size;
    return unshifted_char;
}

void DecipherStrategy::report()
{
    std::lock_guard<std::mutex> lck(_mtx);
    std::cout << "File: " << _input_filename << " has been deciphered." << std::endl;
    std::cout << "Characters Skipped: " << _skipped_characters_count << std::endl;
    std::cout << "Characters Passed Through: " << _passthrough_characters_count << std::endl;
    std::cout << "Characters Enciphered: " << _deciphered_characters_count << std::endl;
}
}

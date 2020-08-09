#include "encipher_command.h"

#include <future>
#include <iostream>
#include <thread>

#include "vigenere_cipher_strategy.h"

namespace vigenere
{
EncipherCommand::EncipherCommand(const std::string &key, std::vector<std::string> files): _key(key), _files(files) {}

void EncipherCommand::Execute()
{
    EncipherFiles();
}

void EncipherCommand::EncipherFiles()
{
    std::vector<std::future<void>> futures;
    for (auto file : _files)
    {

        futures.emplace_back(std::async([&](std::string file){
            VigenereCipherStrategy cipher(_key, file);
            cipher.Encipher();
        }, file));
    }

    for (auto &ftr : futures)
    {
        ftr.wait();
    }

    std::cout << "futures completed" << std::endl;
}
}

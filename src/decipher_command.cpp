#include "decipher_command.h"

#include <future>
#include <iostream>
#include <thread>

#include "decipher_strategy.h"

namespace vigenere
{
DecipherCommand::DecipherCommand(const std::string &key, std::vector<std::string> files): _key(key), _files(files) {}

void DecipherCommand::Execute()
{
    DecipherFiles();
}

void DecipherCommand::DecipherFiles()
{
    std::vector<std::future<void>> futures;
    for (auto file : _files)
    {

        futures.emplace_back(std::async([&](std::string file){
            DecipherStrategy cipher(_key, file);
            cipher.Decipher();
        }, file));
    }

    for (auto &ftr : futures)
    {
        ftr.wait();
    }

    std::cout << "futures completed" << std::endl;
}
}

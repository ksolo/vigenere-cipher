#include "encipher_command.h"

#include <future>
#include <iostream>
#include <thread>

namespace vigenere
{
EncipherCommand::EncipherCommand(const std::string &key, const std::vector<std::string> &files): _key(key)
{
    std::cout << _key.NormalizedKey() << std::endl;
    std::cout << "files: " << std::endl;
    for (auto file : files)
    {
        std::cout << file << std::endl;
    }
}

void EncipherCommand::Execute()
{
    std::cout << "enciphering file..." << std::endl;
    std::cout << "finished file" << std::endl;
}

void EncipherCommand::EncipherFiles(const std::vector<std::string> &files)
{
    std::vector<std::future<void>> futures;
    for (auto &&file: files)
    {
        futures.emplace_back(std::async([&](){
            std::cout << _key.NormalizedKey() << std::endl;
            std::cout << file << std::endl;
        }));
    }

    for (auto &ftr : futures)
    {
        ftr.wait();
    }
}
}

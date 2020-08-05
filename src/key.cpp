#include "key.h"

#include <cctype>

namespace vigenere
{
    Key::Key(const std::string &key) : _raw_key(key)
    {
        _normalized_key = "";
        for(auto letter : key)
            if (isalpha(letter)) _normalized_key.push_back(tolower(letter));
    };

    std::string Key::NormalizedKey() const
    {
        return _normalized_key;
    }

    int Key::Size() const
    {
        return _normalized_key.size();
    }
} // namespace vigenere

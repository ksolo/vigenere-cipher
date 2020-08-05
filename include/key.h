#ifndef KEY_H
#define KEY_H

#include <string>

namespace vigenere
{
class Key
{
public:
    // constructor
    Key(const std::string &key);

    // getters
    std::string NormalizedKey() const;

    // methods
    int Size() const;

private:
    const std::string &_raw_key;
    std::string _normalized_key;
};
} // namespace vigenere


#endif

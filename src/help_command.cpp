#include <iostream>
#include "help_command.h"

namespace vigenere
{

void HelpCommand::Execute()
{
    using std::cout;
    using std::endl;
    cout << "Usage: " << endl;
    cout << "encipher" << endl;
    cout << "\tencipher a text file using a key of alphabetic characters" << endl;
    cout << "\trequires key followed by a list of files to encipher" << endl;
    cout << "\t./vigenere encipher \"hello\" file.txt file2.txt";
}
}

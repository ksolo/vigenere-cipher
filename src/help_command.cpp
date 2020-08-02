#include <iostream>
#include "help_command.h"

using std::cout;
using std::endl;
namespace vigenere
{

void HelpCommand::Execute()
{
    cout << "Usage: " << endl;
    EncipherHelp();
    cout << endl << endl;
    DecipherHelp();
    cout << endl;
}

void HelpCommand::EncipherHelp()
{
    cout << "encipher" << endl;
    cout << "\tencipher a text file using a key of alphabetic characters" << endl;
    cout << "\trequires key followed by a list of files to encipher" << endl << endl;
    cout << "\t$ ./vigenere encipher \"hello\" file.txt file2.txt";

}

void HelpCommand::DecipherHelp()
{
    cout << "decipher" << endl;
    cout << "\tdecipher an encrypted file using a key of alphabetic characters" << endl;
    cout << "\trequires key followed by a list of files to decipher" << endl << endl;
    cout << "\t$ ./vigenere decipher \"hello\" file.enc.txt file2.enc.txt";

}
}

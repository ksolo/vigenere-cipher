# Vigenere Cipher

This is an extension of the cocepts in the Caesar Cipher where a word or phrase is used as the
key for shifting the characters. For more information on these ciphers checkout the
[Wikipedia Article](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## Building

This project uses cmake 3.7 which can be obtained from the [cmake downloads page](https://cmake.org/download/).
Once this is installed make a build directory and navigate to the new directory.

```sh
$ mkdir build
$ cd build
```

From there run the cmake command to generate the make files.

```sh
$ cmake ..
```

Once this has completed you can run make to generate the binary.

```sh
$ make
```

## Running the Program

From the `build/` directory you can execute the program with the following command.

```sh
$ ./vigenere
```

With no arguments or with the help command you will be provided with examples on the application.

## Encipher

To encipher a file you must provide a key to use for encryption. To limit scope of the program
only alphabetic letters should be used. If spaces are part of your key wrap the key in quotes.

```sh
$ ./vigenere encipher "this is my key" file.txt
```

The resulting output will be in a file `file.enc.txt`.


## Decipher

To decipher a file you must provide the key that was use to encrypt the file. As with the
encipher command if the key itself contains spaces, the key must be wrapped in quotes.

```sh
$ ./vigenere decipher "this is my key" encryptedfile.txt
```

## Full Run Through

The application includes a `samples` directory that contains 2 files (`one.txt` and `two.txt`).
To encipher or encrypt them use:

```sh
# make sure you are in the build directory
$ cd build
$ ./vigenere encipher abcdefg ../samples/one.text ../samples/two.txt
```

This will run the program, each file in its own thread. After completion a report will show
indicating how many characters were altered. Due to scope constraints there are many edge
cases not covered and many items are skipped such as punctuation.

The new files with the encrypted information will be in `samples/one.enc.txt` and `samples/two.enc.txt`

To decipher or decrypt them you will now use:

```sh
# make sure you are in the build directory
$ cd build
$ ./vigenere decipher abcdefg ../samples/one.enc.txt ../samples/two.enc.txt
```

This will decrypt them and save the resulting files in `samples/one.enc.dec.txt` and `samples/two.enc.dec.txt`

The text of these last files should contain the original message (all lowercase) and may have a few items
altered such as punctuation since those were not handled.

## Rubric Items

### Loops, Functions, IO

I used `fstream` for reading and writing files, including creating new files for output and altering
the names to differentiate input from output.

For loops and other functions are throughout the code.

### OOP

A shallow hierarchy of `Command` objects was used for creating the `Execute` interface
among the `EncipherCommand`, `DecipherCommand`, and `HelpCommand`.

The Strategy classes contain the primary algorithm for shifting/unshifting characters for
the encryption.

### Memory

There is a unique_ptr used by the `CommandFactory` and returned in `main.cpp`

### Concurrency

Each file provided as input is enciphered/deciphered in its own thread.

# Vigenere Cipher

This is an extension of the cocepts in the Caesar Cipher where a word or phrase is used as the
key for shifting the characters. For more information on these ciphers checkout the
[Wikipedia Article](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## Building

This project uses cmake 3.17.3 which can be obtained from the [cmake downloads page](https://cmake.org/download/).
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
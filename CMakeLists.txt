cmake_minimum_required(VERSION 3.16.3)

project(vigenere_cipher)
set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

add_executable(vigenere
    src/main.cpp
    src/command_factory.cpp
    src/decipher_command.cpp
    src/decipher_strategy.cpp
    src/encipher_command.cpp
    src/encipher_strategy.cpp
    src/help_command.cpp
    src/key.cpp
)

target_include_directories(vigenere PUBLIC include)
target_link_libraries(vigenere ${CMAKE_THREAD_LIBS_INIT})

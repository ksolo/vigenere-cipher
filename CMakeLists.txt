cmake_minimum_required(VERSION 3.17.3)

project(vigenere_cipher)
set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

add_executable(vigenere src/main.cpp)
target_include_directories(vigenere PUBLIC include)

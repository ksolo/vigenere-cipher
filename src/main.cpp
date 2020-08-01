#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "number of args: " << argc << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << "args " << i << ": " << argv[i] << std::endl;
  }

  return 0;
}

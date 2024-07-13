#include <iostream>
#include "dld.h"

int main(int argc, char* argv[]) {
  DLD downloader(std::filesystem::current_path());
  std::cout << std::filesystem::current_path().string() << std::endl;
  if(argc < 2) {
    std::cout << "Is working" << std::endl;
  } else {
    std::string option = argv[1];
    if(option == "-a") {
      std::cout << option << std::endl;
    } else if(option == "-d") {
      downloader.printLatest();
    } else if(option == "-t") {
      downloader.printAll();
    } else if(option == "-h") {
      downloader.printHelp();
    } else {
      std::cerr << "Not a valid option, type \'dld -h\' to see a list of options" << std::endl;
    }
  }
}

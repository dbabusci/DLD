#include <iostream>
#include "dld.h"

int main(int argc, char* argv[]) {
  DLD downloader(std::filesystem::current_path());
  if(argc < 2) {
    downloader.installLatest();
  } else {
    std::string option = argv[1];
    if(option == "-a") {
      downloader.installAll();
    } else if(option == "-d") {
      downloader.printLatest();
    } else if(option == "-l") {
      downloader.printAll();
    } else if(option == "-h") {
      downloader.printHelp();
    } else {
      std::cerr << "Not a valid option, type \'dld -h\' to see a list of options" << std::endl;
    }
  }
}

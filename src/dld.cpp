#include "dld.h"

/*
Constructor
*/
DLD::DLD(std::filesystem::path cwd) {
  _cwd = cwd;
}

/*
Install latest deb
*/
void DLD::installLatest() {

}

/*
Installs all deb
*/
void DLD::installAll() {
  
}

/*
Print latest debs
*/
void DLD::printLatest() {
  std::cout << findLatest() << std::endl;
}

/*
Print all debs
*/
void DLD::printAll() {
  std::vector<std::string> debList = findAll();
  for(std::string s : debList) {
    std::cout << s << std::endl;
  }
}

/*
Print help message
*/
void DLD::printHelp() {
  std::cout << "List of options" << std::endl;
  std::cout << "\tNo options -> Downloads most recently downloaded .deb" << std::endl;
  std::cout << "\t-a         -> Downloads all .deb files in the current directory" << std::endl;
  std::cout << "\t-d         -> Prints out the most recently downloaded .deb" << std::endl;
  std::cout << "\t-t         -> Prints out all the .debs in the current directory" << std::endl;
  std::cout << "\t-h         -> Prints out options that are availiable" << std::endl;
}

/*
Find all of the debs in cwd
*/
std::vector<std::string> DLD::findAll() {
  vector<std::string> debList;
  for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_cwd)) {
    if(entry.is_regular_file) {
      if(isDeb(entry)) {
	debList.push(entry.path.string());
      }
    }
  }
  return debList;
}

/*
Find the latest deb
*/
std::string DLD::findLatest() {
  std::filesystem::directory_entry recent = nullptr;
  for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_cwd)) {
    if(entry.is_regular_file()) {
      if(isDeb(entry)) {
	if(recent == nullptr || recent.last_write_time < entry.last_write_time) {
	  recent = entry;
	}
      }
    }
  }
  return recent.string();
}

/*
Break formatter
*/
void DLD::breakFormat(std::string filename) {
  
}

bool DLD::isDeb(std::filesystem::directory_entry e) {
  std::string path = e.path.string();
  return path.substring(path.size() - 4, 4) == ".deb";
}

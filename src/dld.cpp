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
  std::system((_cmd + findLatest()).c_str());
}

/*
Installs all deb
*/
void DLD::installAll() {
  std::vector<std::string> debList = findAll();
  for(std::string s : debList) {
    breakFormat(s);
    std::system((_cmd + findLatest()).c_str());
  }
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
  std::cout << "\t-l         -> Prints out all the .debs in the current directory" << std::endl;
  std::cout << "\t-h         -> Prints out options that are availiable" << std::endl;
}

/*
Find all of the debs in cwd
*/
std::vector<std::string> DLD::findAll() {
  std::vector<std::string> debList;
  std::string temp = "";
  std::string retTemp = "";
  auto it = temp.end();
  for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_cwd)) {
    if(entry.is_regular_file() && isDeb(entry)) {
      temp = entry.path().string();
      it = temp.end();
      while(it != temp.begin() && *it != '/') {
	 retTemp += *it;
	--it;
      }
      debList.push_back(reverse(retTemp));
      retTemp = "";
    }
  }
  return debList;
}

/*
Find the latest deb
*/
std::string DLD::findLatest() {
  std::filesystem::directory_entry recent;
  for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_cwd)) {
    if(entry.is_regular_file() && isDeb(entry)) {
      if(recent.path().empty() || recent.last_write_time() < entry.last_write_time()) {
	recent = entry;
      }
    }
  }
  std::string p = recent.path().string();
  std::string ret = "";
  auto it = p.end();
  while(it != p.begin() && *it != '/') {
    ret += *it;
    --it;
  }
  return reverse(ret);
}

/*
Break formatter
*/
void DLD::breakFormat(std::string fileName) {
  std::cout << "=================================================" << std::endl; //50 long
  std::cout << std::endl;
  std::cout << fileName << std::endl;
  std::cout << std::endl;
  std::cout << "=================================================" << std::endl;
}

bool DLD::isDeb(std::filesystem::directory_entry e) {
  std::string p = e.path().string();
  return p.substr(p.size() - 4, 4) == ".deb";
}

std::string DLD::reverse(std::string& s) {
  int start = 0;
  int end = s.size() - 1;
  while(start < end) {
    std::swap(s[start], s[end]);
    ++start;
    --end;
  }
  return s;
}

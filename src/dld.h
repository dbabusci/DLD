#ifndef DLD_H
#define DLD_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <filesystem>
#include <vector>
#include <string>

class DLD {
public:
  DLD                                    (std::filesystem::path cwd);
  void                      installLatest();
  void                      installAll   ();
  void                      printLatest  ();
  void                      printAll     ();
  void                      printHelp    ();
  std::vector<std::string>  findAll      ();
  std::string               findLatest   ();
  void                      breakFormat  (std::string fileName);
  bool                      isDeb        (std::filesystem::directory_entry e);
  std::string               reverse      (std::string& s);
private:
  const std::string _cmd = "sudo apt install ./";
  std::filesystem::path _cwd;
};

#endif

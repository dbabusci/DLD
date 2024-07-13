#ifndef DLD_H
#define DLD_H

#include <iostream>
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
  void                      breakFormat  (std::string filename);
  bool                      isDeb        (std::filesystem::directory_entry e);
private:
  const std::string _command = "sudo apt install ./";
  std::filesystem::path _cwd;
};

#endif

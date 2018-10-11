/**
 *  @copyright
 */
#ifndef PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_
#define PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler {
 private:
  ifstream file;

 public:
  bool SetFile(string file_name);
};

#endif  // PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

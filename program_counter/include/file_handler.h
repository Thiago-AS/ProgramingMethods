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
 public:
  ifstream file;
  bool SetFile(string file_name);
};

#endif  // PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

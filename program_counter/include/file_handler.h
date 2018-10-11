/**
 *  @copyright
 */
#ifndef PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_
#define PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

class FileHandler {
 public:
  ifstream file;
  bool SetFile(string file_name);
  int GetFileLines();
};

#endif  // PROGRAM_COUNTER_INCLUDE_FILE_HANDLER_H_

/**
 *  @copyright
 */

#include "../include/file_handler.h"

bool FileHandler::SetFile(string file_name) {
  this->file.open(file_name);
  if (this->file.is_open())
    return true;
  else
    return false;
}

int FileHandler::GetFileLines() {
  if (this->file.is_open()) {
    string line;
    int amount_lines = 0;
    while (getline(this->file, line)) {
      ++amount_lines;
    }
    return amount_lines;
  } else {
    throw "File not open";
  }
}

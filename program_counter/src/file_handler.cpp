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

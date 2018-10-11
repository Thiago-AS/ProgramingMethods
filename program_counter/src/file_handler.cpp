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
    this->file.clear();
    this->file.seekg(0, ios::beg);
    return amount_lines;
  } else {
    throw "File is not open";
  }
}

int FileHandler::GetInvalidLines() {
  if (this->file.is_open()) {
    string line;
    size_t slash_slash, slash_star, star_slash;
    int amount_invalid_lines = 0;
    while (getline(this->file, line)) {
      line.erase(remove(line.begin(), line.end(), ' '), line.end());
      slash_star = line.find("/*");
      slash_slash = line.find("//");

      // Caso em que existe ambos comentários em uma linha.
      if (slash_star != string::npos && slash_slash != string::npos) {
        // Caso /* apareca primeiro que //
        if (slash_star < slash_slash) {
          // Procura fechamento */, e contabiliza quantidade de linhas
          // comentadas
          amount_invalid_lines++;
          star_slash = line.find("*/");
          while (star_slash == string::npos) {
            amount_invalid_lines++;
            getline(this->file, line);
            star_slash = line.find("*/");
          }
        } else {
          if (slash_slash == 0)
            amount_invalid_lines++;
        }
      }

      // Caso exista somente /*
      if (slash_star != string::npos && slash_slash == string::npos) {
        // Procura fechamento */, e contabiliza quantidade de linhas
        // comentadas
        amount_invalid_lines++;
        star_slash = line.find("*/");
        while (star_slash == string::npos) {
          amount_invalid_lines++;
          getline(file, line);
          star_slash = line.find("*/");
        }
      }

      // Caso exista somente //
      if (slash_star == string::npos && slash_slash != string::npos) {
        if (slash_slash == 0)
          amount_invalid_lines++;
      }

      // Caso nao exista comentario, porem so existe espaco nas linhas
      if (line.size() == 0) {
        amount_invalid_lines++;
      }
    }
    this->file.clear();
    this->file.seekg(0, ios::beg);
    return amount_invalid_lines;
  } else {
    throw "File is not open";
  }
}

int FileHandler::GetValidLines() {
  if (this->file.is_open()) {
    int amount_valid_lines = 0;
    amount_valid_lines = GetFileLines() - GetInvalidLines();
    return amount_valid_lines;
  } else {
    throw "File is not open";
  }
}

bool FileHandler::CloseFile() {
  if (this->file.is_open()) {
    this->file.close();
    if (this->file.is_open())
      return false;
    else
      return true;
  } else {
    return false;
  }
}

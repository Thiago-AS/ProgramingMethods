/**
 *  @copyright
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/file_handler.h"

TEST_CASE("Alocar classe FileHandler") {
  FileHandler* file_handler = nullptr;
  file_handler = new FileHandler;
  REQUIRE(file_handler != nullptr);

  SECTION("Definir arquivo no atributo de classe") {
    bool set_correctly = false;
    set_correctly = file_handler->SetFile("sample_file.cpp");
    REQUIRE(set_correctly == true);

    SECTION("Contar quantidade de linhas total do arquivo") {
      int file_lines = 0;
      try {
        file_lines = file_handler->GetFileLines();
        REQUIRE(file_lines != 0);
        REQUIRE(file_lines == 27);
      } catch(const char* error) {
        REQUIRE(file_handler->file.is_open() == false);
      }
    }
  }
}

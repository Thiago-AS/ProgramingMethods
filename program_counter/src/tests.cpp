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

      SECTION("Contar quantidade de linhas comentadas ou em branco") {
        int invalid_lines = 0;
        try {
          invalid_lines = file_handler->GetInvalidLines();
          REQUIRE(invalid_lines == 12);
        } catch(const char* error) {
          REQUIRE(file_handler->file.is_open() == false);
        }

        SECTION("Contar quantidade de linhas de codigo") {
          try {
            int valid_lines = 0;
            valid_lines = file_handler->GetValidLines();
            REQUIRE(valid_lines == 15);
          } catch(const char* error) {
            REQUIRE(file_handler->file.is_open() == false);
          }
        }
      }
    }

    SECTION("Fechar arquivo") {
      bool close_correctly = false;
      close_correctly = file_handler->CloseFile();
      REQUIRE(close_correctly == true);
    }
  }
  delete file_handler;
}

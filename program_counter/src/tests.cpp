/**
 *  @copyright
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/file_handler.h"

TEST_CASE("Alocar classe FileHandler") {
  FileHandler file_handler = nullptr;
  file_handler = new FileHandler;
  REQUIRE(file_handler != nullptr);
}

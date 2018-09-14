/* Copyright 2018 Thiago Araujo da Silva 15/0149832 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack.hpp"

TEST_CASE("Alocar a classe pilha") {
  Stack* stack_test = new Stack;
  REQUIRE(stack_test->Amount() == 0);
  REQUIRE(stack_test->Size() == 0);

  SECTION("Tentar mudar tamanho máximo para valor negativo") {
    REQUIRE(stack_test->SetSize(-2) == 0);
    REQUIRE(stack_test->Size() == 0);
  }

  SECTION("Mudar tamanho máximo da pilha para valor positivo") {
    REQUIRE(stack_test->SetSize(2) == 1);
    REQUIRE(stack_test->Size() == 2);

    SECTION("Verificar se pilha está vazia e não cheia") {
      REQUIRE(stack_test->IsEmpty() == 1);
      REQUIRE(stack_test->IsFull() == 0);
    }

    SECTION("Retirar elemento de pilha vazia") {
      try {
        REQUIRE(stack_test->Amount() == 0);
        stack_test->Pop();
      } catch(const std::out_of_range& error) {
        std::string expected_error("Stack is empty");
        REQUIRE(stack_test->Amount() == 0);
        REQUIRE(expected_error.compare(error.what()) == 0);
      }
    }

    SECTION("Olhar topo da pilha vazia") {
      try {
        REQUIRE(stack_test->Amount() == 0);
        stack_test->Top();
      } catch(const std::out_of_range& error) {
        std::string expected_error("Stack is empty");
        REQUIRE(stack_test->Amount() == 0);
        REQUIRE(expected_error.compare(error.what()) == 0);
      }
    }

    SECTION("Adicionar elemento a pilha") {
      REQUIRE(stack_test->Push(12) == 1);
      REQUIRE(stack_test->Top() == 12);
      REQUIRE(stack_test->Amount() == 1);

      SECTION("Retirar elemento da pilha") {
        REQUIRE(stack_test->Pop() == 12);
        REQUIRE(stack_test->Amount() == 0);
      }
    }

    SECTION("Adicionar elementos até atingir tamanho máximo") {
        REQUIRE(stack_test->Push(10) == 1);
        REQUIRE(stack_test->Top() == 10);
        REQUIRE(stack_test->Amount() == 1);
        REQUIRE(stack_test->Push(11) == 1);
        REQUIRE(stack_test->Top() == 11);
        REQUIRE(stack_test->Amount() == 2);

        SECTION("Verificar se pilha está cheia e não vazia") {
          REQUIRE(stack_test->IsFull() == 1);
          REQUIRE(stack_test->IsEmpty() == 0);
        }

        SECTION("Adicionar elemento a uma pilha cheia") {
          REQUIRE(stack_test->Push(12) == 0);
          REQUIRE(stack_test->Top() == 11);
          REQUIRE(stack_test->Amount() == 2);
        }
    }
  }
  delete stack_test;
}

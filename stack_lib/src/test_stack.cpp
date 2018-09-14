/* Copyright 2018 Thiago Araujo da Silva 15/0149832 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack.hpp"

/**@brief Testa todos os components da pilha.
 * Realiza todas as operações possiveis da classe/biblioteca pilha.
 */
TEST_CASE("Testes pilha") {
  // Setup dos testes
  Stack* stack_test = new Stack;
  REQUIRE(stack_test->Amount() == 0);
  REQUIRE(stack_test->Size() == 0);

  // INIT TESTES

  /**@brief Test tamanho máximo negativo.
   * Muda o valor do tamanho máximo para negativo e verifica que a operação
   * nao foi bem sucedida.
   */
  SECTION("Tentar mudar tamanho máximo para valor negativo") {
    REQUIRE(stack_test->SetSize(-2) == false);
    REQUIRE(stack_test->Size() == 0);
  }

  /**@brief Test tamanho máximo positivo.
   * Muda o valor do tamanho máximo para positivo e verifica que a operação
   * foi bem sucedida.
   */
  SECTION("Mudar tamanho máximo da pilha para valor positivo") {
    REQUIRE(stack_test->SetSize(2) == true);
    REQUIRE(stack_test->Size() == 2);

    /**@brief Test pilha vazia.
     * Checa se o retorno da função IsEmpty e verdadeiro (Pilha vazia)
     */
    SECTION("Verificar se pilha está vazia e não cheia") {
      REQUIRE(stack_test->IsEmpty() == true);
      REQUIRE(stack_test->IsFull() == false);
    }

    /**@brief Retirar elemento da pilha vazia.
     * Retira elemento da pilha vazia, e verifica se ouve tratamento de exeção.
     */
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

    /**@brief Olhar elemento topo da pilha vazia.
     * Olha o elemento topo da pilha vazia, e verifica se ouve tratamento de
     * exeção.
     */
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

    /**@brief Adicionar elemento a pilha.
     * Adiciona elemento a pilha, verifica se operação foi bem sucedida, se o topo
     * é o mesmo elemento adicionado e se a quantidade mudou
     */
    SECTION("Adicionar elemento a pilha") {
      REQUIRE(stack_test->Push(12) == true);
      REQUIRE(stack_test->Top() == 12);
      REQUIRE(stack_test->Amount() == 1);

      /**@brief Retira elemento a pilha.
       * Retira o elemento anteriormente adicionado, verifica se é o mesmo e
       * verifica se a quantidade mudou
       */
      SECTION("Retirar elemento da pilha") {
        try {
          REQUIRE(stack_test->Pop() == 12);
          REQUIRE(stack_test->Amount() == 0);
        } catch(const std::out_of_range& error) {
          std::string expected_error("Stack is empty");
          REQUIRE(stack_test->Amount() == 0);
          REQUIRE(expected_error.compare(error.what()) == 0);
        }
      }
    }

    /**@brief Atingir tamanho máximo pilha.
     * Adiciona elementos até atingir tamanho máximo, e para cada inserção,
     * verifica se elemento foi adicionado.
     */
    SECTION("Adicionar elementos até atingir tamanho máximo") {
        REQUIRE(stack_test->Push(10) == true);
        REQUIRE(stack_test->Top() == 10);
        REQUIRE(stack_test->Amount() == 1);
        REQUIRE(stack_test->Push(11) == true);
        REQUIRE(stack_test->Top() == 11);
        REQUIRE(stack_test->Amount() == 2);

        /**@brief Test pilha cheia.
         * Checa se o retorno da função IsFull e verdadeiro (Pilha vazia).
         */
        SECTION("Verificar se pilha está cheia e não vazia") {
          REQUIRE(stack_test->IsFull() == true);
          REQUIRE(stack_test->IsEmpty() == false);
        }

        /**@brief Adiciona elemento a pilha cheia.
         * Adiciona elementos a uma pilha cheia, verificar se a operação foi mal
         * sucedida, se o topo da pilha continua com o ultimo elemento adicionado
         * e se a quantidade não mudou.
         */
        SECTION("Adicionar elemento a uma pilha cheia") {
          REQUIRE(stack_test->Push(12) == false);
          REQUIRE(stack_test->Top() == 11);
          REQUIRE(stack_test->Amount() == 2);
        }
    }
    // END TESTES
  }
  // TearDown dos testes
  delete stack_test;
}

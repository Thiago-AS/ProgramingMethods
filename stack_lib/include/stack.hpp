/* Copyright 2018 Thiago Araujo da Silva 15/0149832 */
/** @file stack.hpp
 *  @brief Define as interfaces das pilhas utilizadas.
 *
 *  Arquivo que define as estruturas e classes utilizadas para se formular a
 *  pilha.
 */
#ifndef STACK_LIB_INCLUDE_STACK_HPP_
#define STACK_LIB_INCLUDE_STACK_HPP_

#include<iostream>
#include<vector>
#include<string>

/**Macro que define o tipo de dado a ser utilizado pela pilha.*/
#define ITEM_TYPE int

/** @brief Define os elementos da pilha.
 *
 *  Struct que representa um elemento da pilha, contendo o dado deste elemento
 *  e um ponteiro para o próximo elemento da pilha.
 */
typedef struct StackNode {
  ITEM_TYPE data; /**< Dado armazenado no elemento.*/
  struct StackNode* next_node; /**< Ponteiro para o próximo elemento da pilha.*/
} StackNode;

/** @brief Define o cabeçalho da pilha.
 *
 *  Struct que representa o cabeçalho da pilha, contendo sempre o topo da pilha,
 *  a quantidade de elementos e o tamanho máximo da pilha.
 */
typedef struct StackHeader {
  StackNode* stack_top; /**< Ponteiro apontando para o topo da pilha*/
  int stack_amount; /**< Guarda a quantidade de elementos armazenados na pilha*/
  int stack_max_size; /**< Guarda a quantidade máxima de elementos da pilha*/
} StackHeader;

// typedef struct StackHeader {
//   std::vector<ITEM_TYPE> stack_vector;
//   int stack_amount;
//   int stack_max_size;
// } StackHeader;

/**
 *  @brief Classe que mantem as estruturas e métodos para a implementar uma
 *  pilha.
 */
class Stack {
 private:
  /** Cabeçalho que define a pilha na classe. */
  StackHeader* stack_header;
  /** @brief Cria o cabeçalho da pilha.*/
  void CreateStack();
  /** @brief Destroi o cabeçalho da pilha e seus elementos restantes.*/
  void DestroyStack();

 public:
  /** @brief Construtor da classe que invoca o método criar pilha.*/
  Stack() {
    CreateStack();
  }
  /** @brief Destrutor da classe que invoca o método destruir pilha.*/
  ~Stack() {
    DestroyStack();
  }
  /** @brief Verifica se a pilha está cheia.
   *  @return Retorna verdadeiro apenas se a pilha estiver cheia, caso contrário
   *  retorna falso.
   */
  bool IsFull();
  /** @brief Verifica se a pilha está vaiza.
   *  @return Retorna verdadeiro apenas se a pilha estiver vazia, caso contrário
   *  retorna falso.
   */
  bool IsEmpty();
  /** @brief Define o tamanho máximo da pilha.
   *  @param size Tamanho da pilha desejado.
   *  @return Retorna verdadeiro para operação bem sucedida, ou falso caso falha.
   */
  bool SetSize(int size);
  /** @brief Retorna o tamanho máximo da pilha.
   *  @return Retorna o valor do tamanho máximo da pilha.
   */
  int Size();
  /** @brief Adiciona elemento ao topo pilha.
   *  @param data Conteúdo a ser inserido na pilha.
   *  @return Retorna verdadeiro para operação bem sucedida, ou falso caso falha.
   */
  bool Push(ITEM_TYPE data);
  /** @brief Retira elemento do topo da pilha e retorna seu dado.
   *  @return Retorna o conteúdo do elemento retirado da pilha.
   */
  ITEM_TYPE Pop();
  /** @brief Retorna o dado do topo da pilha sem modifica-la.
   *  @return Retorna o conteúdo do elemento do topo da pilha.
   */
  ITEM_TYPE Top();
};

#endif  // STACK_LIB_INCLUDE_STACK_HPP_

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

#define ITEM_TYPE std::string

/** @brief Define os elementos da pilha.
 *
 *  Define uma struct que representa um elemento da pilha de char, tendo como
 *  elementos, o valor do char, e um ponteiro o próximo elemento.
 */
// typedef struct StackNode {
//   ITEM_TYPE data; /**< Valor do char armazenado.*/
//   struct StackNode* next_node; /**< Valor do char armazenado.*/
// } StackNode;
//
// typedef struct StackHeader {
//   StackNode* stack_top;
//   int stack_amount;
//   int stack_max_size;
// } StackHeader;

typedef struct StackHeader {
  std::vector<ITEM_TYPE> stack_vector;
  int stack_amount;
  int stack_max_size;
} StackHeader;

class Stack {
  StackHeader* stack_header;
 public:
  Stack() {
    CreateStack();
  }
  ~Stack() {
    DestroyStack();
  }
  bool IsFull();
  bool IsEmpty();
  bool SetSize(int size);
  int Size();
  bool Push(ITEM_TYPE data);
  ITEM_TYPE Pop();
  ITEM_TYPE Top();

 private:
  void CreateStack();
  void DestroyStack();
};

#endif  // STACK_LIB_INCLUDE_STACK_HPP_

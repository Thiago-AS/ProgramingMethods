/* Copyright 2018 Thiago Araujo da Silva 15/0149832 */
#include "stack.hpp"

/**
 *  LinkedList: Aloca o cabeçalho da pilha, definindo o elemento do topo como
 *  nulo, e o tamanho máximo e a quantidade inicial como 0.
 */
void Stack::CreateStack() {
  stack_header = new StackHeader;
  stack_header->stack_top = NULL;
  stack_header->stack_amount = 0;
  stack_header->stack_max_size = 0;
}

/**
 *  LinkedList: Itera-se sobre a pilha desalocando todos os elementos restantes da
 *  pilha, até que esta esteja vazia, após remover os elementos, remove-se o
 *  cabeçalho da pilha.
 */
void Stack::DestroyStack() {
  while (stack_header->stack_top != NULL) {
    StackNode* node = stack_header->stack_top;
    stack_header->stack_top = stack_header->stack_top->next_node;
    delete node;
  }
  delete stack_header;
}

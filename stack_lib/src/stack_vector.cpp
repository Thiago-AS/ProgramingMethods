/* Copyright 2018 Thiago Araujo da Silva 15/0149832 */
#include "stack.hpp"

/**
 *  Vector: Aloca o cabeçalho da pilha, declarando sua estrutura vector, e
 *  definindo o tamanho máximo e a quantidade inicial como 0.
 */
void Stack::CreateStack() {
  stack_header = new StackHeader;
  stack_header->stack_amount = 0;
  stack_header->stack_max_size = 0;
}

/**
 *  Vector: Desaloca o cabeçalho da pilha, como os elementos se encontram na
 *  estrutura vector, os elementos são desalocados juntos.
 */
void Stack::DestroyStack() {
  delete stack_header;
}

/**
 *  Vector: Verifica se a pilha está cheia, comparando a quantidade de elementos
 *  na pilha com o seu tamanho máximo.
 */
bool Stack::IsFull() {
  if (stack_header->stack_amount == stack_header->stack_max_size)
    return true;
  else
    return false;
}

/**
 *  Vector: Verifica se a pilha está vazia, comparando a quantidade de elementos
 *  na pilha com 0.
 */
bool Stack::IsEmpty() {
  if (stack_header->stack_amount == 0)
    return true;
  else
    return false;
}

/**
 *  Vector: Muda o valor de tamanho máximo da pilha e redimensiona o vector.
 *  Verifica se o valor fornecido é maior que zero, caso seja, realiza a operação
 *  e retorna verdadeiro, caso não, retorna falso e nao realiza nada.
 */
bool Stack::SetSize(int size) {
  if (size >= 0) {
    stack_header->stack_max_size = size;
    stack_header->stack_vector.reserve(stack_header->stack_max_size);
    return true;
  } else {
    return false;
  }
}

/**
 *  Vector: Retorna o valor de tamanho máximo definido na pilha.
 */
int Stack::Size() {
  return stack_header->stack_max_size;
}

/**
 *  Vector: Verifica se a pilha está cheia, caso esteja, retorna falso sem
 *  realizar nenhuma operação. Caso ainda tenha espaço, itera-se sobre o vector
 *  utilizando a propria variavel de quantidade, coloca-se o dado no topo
 *  (ultimo elemento do vector), soma 1 a quantidade e retorna-se verdadeiro.
 */
bool Stack::Push(ITEM_TYPE data) {
  if (IsFull()) {
    std::cout << "Stack is full" << std::endl;
    return false;
  } else {
    stack_header->stack_vector[stack_header->stack_amount++] = data;
    return true;
  }
}

/**
 *  Vector: Verifica se a pilha está vazia, caso esteja, não realiza nenhuma
 *  operação. Caso ainda tenha elementos, subtrai-se 1 da quantidade de elementos
 *  para que seja possivel obter o indice do elemento a ser retirado e retorna-se
 *  o conteúdo do elemento retirado.
 */
ITEM_TYPE Stack::Pop() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    ITEM_TYPE data;
    stack_header->stack_amount--;
    data = stack_header->stack_vector[stack_header->stack_amount];
    return data;
  }
}

/**
 *  Vector: Verifica se a pilha está vazia, caso esteja, não realiza nenhuma
 *  operação. Caso ainda tenha elementos, apenas é retornado o conteudo do topo
 *  da pilha, sem alterações na quantidade de elementos.
 */
ITEM_TYPE Stack::Top() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    return stack_header->stack_vector[stack_header->stack_amount - 1];
  }
}

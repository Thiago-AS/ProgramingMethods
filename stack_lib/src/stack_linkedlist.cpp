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

/**
 *  LinkedList: Verifica se a pilha está cheia, comparando a quantidade de elementos
 *  na pilha com o seu tamanho máximo.
 */
bool Stack::IsFull() {
  if (stack_header->stack_amount == stack_header->stack_max_size)
    return true;
  else
    return false;
}

/**
 *  LinkedList: Verifica se a pilha está vazia, comparando a quantidade de elementos
 *  na pilha com 0.
 */
bool Stack::IsEmpty() {
  if (stack_header->stack_amount == 0)
    return true;
  else
    return false;
}

/**
 *  LinkedList: Muda o valor de tamanho máximo da pilha. Verifica se o valor fornecido
 *  é maior que zero, caso seja, realiza a operação e retorna verdadeiro, caso
 *  não, retorna falso e nao realiza nada.
 */
bool Stack::SetSize(int size) {
  if (size >= 0) {
    stack_header->stack_max_size = size;
    return true;
  } else {
    return false;
  }
}

/**
 *  LinkedList: Retorna o valor de tamanho máximo definido na pilha.
 */
int Stack::Size() {
  return stack_header->stack_max_size;
}

/**
 *  LinkedList: Verifica se a pilha está cheia, caso esteja, retorna falso sem
 *  realizar nenhuma operação. Caso ainda tenha espaço, cria-se um novo elemento
 *  definindo seu conteudo como o parametro data fornecido, e apontado seu antecessor
 *  para o antigo topo da pilha. Por fim, aponta o topo da pilha para o novo
 *  elemento, incrementa-se a quantidade de elementos da pilha e retorna verdadeiro.
 */
bool Stack::Push(ITEM_TYPE data) {
  if (IsFull()) {
    std::cout << "Stack is full" << std::endl;
    return false;
  } else {
    StackNode* new_node = new StackNode;
    new_node->data = data;
    new_node->next_node = stack_header->stack_top;
    stack_header->stack_top = new_node;
    stack_header->stack_amount++;
    return true;
  }
}

/**
 *  LinkedList: Verifica se a pilha está vazia, caso esteja, não realiza nenhuma
 *  operação. Caso ainda tenha elementos, cria-se um elemento auxiliar para que
 *  seja possivel desalocar este posteriormente. O conteudo a ser retornado é
 *  salvo, o topo da pilha é apontado para o antecessor do elemento a ser retirado
 *  e decrementa-se a quantidade de elementos. Por fim, desaloca-se o elemento,
 *  e seu conteudo é retornado.
 */
ITEM_TYPE Stack::Pop() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    ITEM_TYPE node_data;
    StackNode* old_node = stack_header->stack_top;
    node_data = stack_header->stack_top->data;
    stack_header->stack_top = stack_header->stack_top->next_node;
    stack_header->stack_amount--;
    delete old_node;
    return node_data;
  }
}

/**
 *  LinkedList: Verifica se a pilha está vazia, caso esteja, não realiza nenhuma
 *  operação. Caso ainda tenha elementos, apenas é retornado o conteudo do topo
 *  da pilha, sem alterações na quantidade de elementos.
 */
ITEM_TYPE Stack::Top() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    return stack_header->stack_top->data;
  }
}

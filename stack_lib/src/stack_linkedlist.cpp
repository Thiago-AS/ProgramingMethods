// Copyright
#include "stack.hpp"

void Stack::CreateStack() {
  stack_header = new StackHeader;
  stack_header->stack_top = NULL;
  stack_header->stack_amount = 0;
  stack_header->stack_max_size = 0;
}

void Stack::DestroyStack() {
  while (stack_header->stack_top != NULL) {
    StackNode* node = stack_header->stack_top;
    stack_header->stack_top = stack_header->stack_top->next_node;
    delete node;
  }
  delete stack_header;
}

bool Stack::IsFull() {
  if (stack_header->stack_amount == stack_header->stack_max_size)
    return true;
  else
    return false;
}

bool Stack::IsEmpty() {
  if (stack_header->stack_amount == 0)
    return true;
  else
    return false;
}

bool Stack::SetSize(int size) {
  if (size >= 0) {
    stack_header->stack_max_size = size;
    return true;
  } else {
    return false;
  }
}

int Stack::Size() {
  return stack_header->stack_max_size;
}

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

ITEM_TYPE Stack::Top() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    return stack_header->stack_top->data;
  }
}

#include "stack.hpp"

bool Stack::IsFull() {
  if (stack_amount == stack_max_size)
    return true;
  else
    return false;
}

bool Stack::IsEmpty() {
  if (stack_amount == 0 && stack_top == NULL)
    return true;
  else
    return false;
}

bool Stack::SetSize(int size) {
  if (size >= 0) {
    stack_max_size = size;
    return true;
  } else {
    return false;
  }
}

int Stack::Size() {
  return stack_max_size;
}

bool Stack::Push(ITEM_TYPE data) {
  if (IsFull()) {
    std::cout << "Stack is full" << std::endl;
    return false;
  } else {
    StackNode* new_node = new StackNode;
    new_node->data = data;
    new_node->next_node = stack_top;
    stack_top = new_node;
    stack_amount++;
    return true;
  }
}

ITEM_TYPE Stack::Pop() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return false;
  } else {
    ITEM_TYPE node_data;
    StackNode* old_node = stack_top;
    node_data = stack_top->data;
    stack_top = stack_top->next_node;
    stack_amount--;
    delete old_node;
    return node_data;
  }
}

ITEM_TYPE Stack::Top() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return false;
  } else {
    return stack_top->data;
  }
}

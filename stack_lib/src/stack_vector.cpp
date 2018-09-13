// Copyright
#include "stack.hpp"

void Stack::CreateStack() {
  stack_header = new StackHeader;
  stack_header->stack_amount = 0;
  stack_header->stack_max_size = 0;
}

void Stack::DestroyStack() {
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
    stack_header->stack_vector.reserve(stack_header->stack_max_size);
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
    stack_header->stack_vector[stack_header->stack_amount++] = data;
    return true;
  }
}

ITEM_TYPE Stack::Pop() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return false;
  } else {
    ITEM_TYPE data;
    stack_header->stack_amount--;
    data = stack_header->stack_vector[stack_header->stack_amount];
    return data;
  }
}

ITEM_TYPE Stack::Top() {
  if (IsEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return false;
  } else {
    return stack_header->stack_vector[stack_header->stack_amount - 1];
  }
}

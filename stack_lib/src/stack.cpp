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

#include "stack.hpp"

int main() {
  Stack* s = new Stack;
  std::cout << s->Size() << std::endl;
  std::cout << s->IsFull() << std::endl;
  std::cout << s->IsEmpty() << std::endl;
  std::cout << s->SetSize(3) << std::endl;
  std::cout << s->Size() << std::endl;
  std::cout << s->IsFull() << std::endl;
  std::cout << s->IsEmpty() << std::endl;

  return 0;
}

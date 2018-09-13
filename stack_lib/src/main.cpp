// Copyright
#include "stack.hpp"

int main() {
  Stack* s = new Stack;
  std::cout << s->Size() << std::endl;
  std::cout << s->SetSize(2) << std::endl;
  std::cout << s->Push("oi") << std::endl;
  std::cout << s->Push("asds") << std::endl;
  std::cout << s->Push("lko") << std::endl;
  std::cout << s->Pop() << std::endl;
  std::cout << s->Top() << std::endl;
  std::cout << s->Pop() << std::endl;
  s->Pop();
  std::cout << s->Push("llll") << std::endl;

  return 0;
}

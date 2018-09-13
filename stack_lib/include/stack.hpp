// Copyright
#ifndef STACK_LIB_INCLUDE_STACK_HPP_
#define STACK_LIB_INCLUDE_STACK_HPP_

#define ITEM_TYPE int

#include<iostream>
#include<vector>

// typedef struct StackNode {
//   ITEM_TYPE data;
//   struct StackNode* next_node;
// } StackNode;

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

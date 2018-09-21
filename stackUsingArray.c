#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {

  int top;
  int *arr;
  int SIZE;
}Stack;

void init(Stack **stack, int size) {

  *stack = (Stack *)malloc(sizeof(Stack));
  (*stack)->top = -1;
  (*stack)->SIZE = size;
  (*stack)->arr = (int *)malloc(sizeof(int) * size);
  printf("Size: %d\n", (*stack)->SIZE);
}

int top(Stack *stack) {

  return stack->arr[stack->top];
}

int isEmpty(Stack* stack) {

  return (stack->top == -1);
}

int isFull(Stack* stack) {
  
  
  return ((stack->top) == (stack->SIZE - 1));
}

void insert(Stack *stack, int data) {

  if(!(isFull(stack))) {
  
    stack->arr[++(stack->top)] = data;
  }
  else {
    
    printf("Stack Overflow..\n");
  }
}

int delete(Stack *stack) {

  if(!(isEmpty(stack))) {
  
    (stack->top)--;
    return stack->arr[stack->top + 1];
  }
  printf("stack Underflow...\n");
  return -9999999;
}



int main() {

  Stack *stack;
  init(&stack, 10);
  insert(stack, 1);
  insert(stack, 2);
  insert(stack, 4);
  insert(stack, 5);
  insert(stack, 6);
  insert(stack, 7);
  insert(stack, 8);
  insert(stack, 9);
  insert(stack, 8);
  insert(stack, 7);
  insert(stack, 6);
  insert(stack, 5);
  insert(stack, 4);
  
  while(!(isEmpty(stack))) {
  
    printf("%d\n", delete(stack));
  }
  
  return 0;
}

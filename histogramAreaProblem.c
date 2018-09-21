#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

  int data;
  struct Node *next;
}Node;

typedef struct Stack {

  Node *top;
}Stack; 

void insert(Stack *stack, int data) {

  Node *node = (Node *)malloc(sizeof(Node));
  if(node == NULL) {
  
    printf("Stack Overflow..\n");
  }
  node->data = data;
  node->next = stack->top;
  stack->top = node;
}

int delete(Stack *stack) {

  if(stack->top == NULL) {
  
    printf("Stack Underflow..\n");
  }
  int d = stack->top->data;
  Node *t = stack->top;
  stack->top = stack->top->next;
  free(t);
  t = NULL;
  return d;
}

int top(Stack *stack) {

  return stack->top->data;
}

int isEmpty(Stack *stack) {

  return (stack->top == NULL);
}

int main() {

  
}

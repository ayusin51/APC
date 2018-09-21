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

  Stack* stack = (Stack *)malloc(sizeof(Stack));
  int arr[] = {100, 80, 60, 70, 60, 75, 85};
  int size = 7;
  int span[7] = {1};
  
  int max = 1;
  int i = 0;
  insert(stack , 0);
  for(i = 1; i < size;) {
  
    if(arr[i] <= arr[top(stack)]) {
      if(isEmpty(stack)) span[i] = i + 1;
      else span[i] = i - top(stack);
      insert(stack, i);
      printf("i = %d, Inserting %d\n", i, i);
      i++;
    }	
    else {
    
      printf("i = %d, deleting %d\n", i, top(stack));  
      delete(stack);
        
      if(max < i - top(stack)) max = i - top(stack);
    }
  }
  for(i = 0; i < size; i++) {
  
    printf("%d\n", span[i]);
  }
  printf("Max : %d\n", max);
}

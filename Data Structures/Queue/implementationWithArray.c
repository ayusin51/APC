#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {

	int arr[100];
	int start;
	int end;
	int size;
}Queue;

void push(Queue *q, int data) {

	q->arr[++(q->end)] = data;
	(q->size)++;
}

int pop(Queue *q) {

	if((q->size) > 0) 
	{
		(q->start)++;
		(q->size)--;
		return q->arr[q->start - 1];
	}
	
	return -99999;
}

int isEmpty(Queue *q) {

	return (q->size == 0);
}



int main() {

	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->start = 0;
	q->end = -1;
	q->size = 0;
	
	int i;
	for(i = 0; i < 10; i++) 
		push(q, i + 2);
	
	while(!isEmpty(q))
		printf("%d ", pop(q));
}

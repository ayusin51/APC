#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node * next;
};

struct Node* createNewNode() {

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	return node;
}

struct Node* head = NULL;


void insertFirst(int data) {

	struct Node* node = createNewNode();
	node->data = data;
	head->next = node;
}

void insertLast(int data) {
	
	struct Node* node = createNewNode();
	node->data = data;
	node->next = NULL;
	
	struct Node* curr = head;
	while(curr->next) {
	
		curr = curr->next;
	}
	
	curr->next = node;
}

void print() {

	struct Node* curr = head;
	while(curr->next) {
		
		curr = curr->next;
		printf("%d\n", curr->data);
	}
}

int main() {

	insertFirst(2);
	insertFirst(1);
	insertLast(3);
	insertLast(4);
	print();
}





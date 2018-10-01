#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	struct Node *next;
	int data;
}Node;

Node* createNode(int data) {

	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

Node* insertFirst(Node* head, int data) {

	Node *node = createNode(data);
	node->next = head;
	head = node;
	return head;
}

Node* insertLast(Node* head, int data) {

	Node *node = createNode(data);
	
	if(!head) return node;
	
	Node* curr = head;
	while(curr->next) {
	
		curr = curr->next;
	}
	curr->next = node;
	return head;
}

Node* insertAtPos(Node* head, int data, int pos) {

	if(pos <= 0) return head;
	if(pos == 1) return insertFirst(head, data);
	
	Node* node = createNode(data);
	Node* curr = head;
	
	pos--;
	while(--pos) {
	
		curr = curr->next;
	}
	node->next = curr->next;
	curr->next = node;
	return head;
}

Node* deleteFirst(Node* head) {

	if(!head || !(head->next)) return NULL;
	
	Node* curr = head;
	head = head->next;
	
	free(curr);
	
	return head;
}

Node* deleteLast(Node *head) {

	if(!head || !(head->next)) return NULL;
	
	Node* curr = head;
	
	while(curr->next->next) {
	
		if(curr->next)
			curr = curr->next;
		else
			return head;
	}
	
	Node *temp = curr->next;
	curr->next = NULL;
	free(temp);
	
	return head;
}

Node* deleteAtPos(Node* head, int pos) {

	if(pos <= 0) return head;
	if(pos == 1) return deleteFirst(head);
	
	pos--;
	Node* curr = head;
	while(--pos) {
	
		if(curr->next)
			curr = curr->next;
		else
			return head;
	}
	Node* temp = curr->next;
	curr->next = curr->next->next;
	free(temp);
	
	return head;
}

void printList(Node *head) {

	Node *curr = head;
	while(curr) {
	
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
}

void printRev(Node *curr) {

	if(curr == NULL) return;
	
	printRev(curr->next);
	
	printf("%d <- ", curr->data);
}


int main() {

	Node *head = NULL;
	int i;
	for(i = 0; i < 3; i++) {
	
		head = insertFirst(head, i);
	}
	
	printf("\nPrint : \n");
	printList(head);
	
	for(i = 0; i < 3; i++) {
	
		head = insertLast(head, i+3);
	}
	
	printf("\nPrint : \n");
	printList(head);
	
	head = insertAtPos(head, 10, 3);
	printf("\nPrint : \n");
	printList(head);
	
	for(i = 0; i < 3; i++) {
	
		head = deleteFirst(head);
	}
	
	printf("\nPrint : \n");
	printList(head);
	
	head = deleteAtPos(head, 3);
	printf("\nAfter deleting at 3 Print : \n");
	printList(head);
	
	for(i = 0; i < 2; i++) {
	
		head = deleteLast(head);
	}
	
	printf("\nPrint : \n");
	printList(head);
	
	printf("\nPrint Rev : \n");
	printRev(head);
	printf("\n");
	
}

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

void printList(Node *head) {

	Node *curr = head;
	while(curr) {
	
		printf("%d -> ", curr->data);
		curr = curr->next;
	}
}

Node* reverse(Node* head) {

	if(!head || !(head->next)) return head;
	
	Node *prev = NULL;
	Node *curr = head;
	Node *next = curr->next;
	
	while(curr) {
	
		curr->next = prev;
		prev = curr;
		curr = next;
		if(next)
			next = next->next;
	}
	
	head = prev;
	return head;
}

Node* reverseRecursion(Node *head) {

	if(head == NULL || head->next ==  NULL) return head;
	
	Node *first = head;
	Node *second = head->next;
	
	Node *curr = reverseRecursion(second);
	
	second->next = first;
	first->next = NULL;
	
	return curr;
}

int main() {

	
	Node *head = NULL;
	int i;
	for(i = 0; i < 6; i++) {
	
		head = insertFirst(head, i);
	}
	printf("Print : \n");
	printList(head);
	
	head = reverse(head);
	printf("\nPrint after Reversing : \n");
	printList(head);
	
	head = reverseRecursion(head);
	printf("\nPrint after Reversing again : \n");
	printList(head);
}

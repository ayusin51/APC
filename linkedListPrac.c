#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;	
	
}Node;


Node* createNewNode() {

	Node *node = (Node*)malloc(sizeof(Node));
	return node;
}

Node* insertFirst(Node* head, int data) {

	Node* node = createNewNode();
	Node* temp = head;
	node->data = data;
	node->next = temp;
	head = node;
	return head;
	//printf("%d\n", head->data);
}

Node* insertEnd(Node* head, int data) {

	Node* node = createNewNode();
	node->data = data;
	node->next = NULL;
	Node* curr = head;
	if(!head) head = node;
	else {
	
		while(curr->next) {
	
			curr = curr->next;
		}
		curr->next = node;
	}
	return head;
	
}

Node* insertAtIndex(Node* head, int data, int pos) {

	if(pos < 0) {
	
		printf("Position Cannot be negative...\n");
		return head;
	}
	if(pos == 0) {
	
		head = insertFirst(head, data);
		return head;
	}
	Node* curr = head;
	int count = 1;
	while(count < pos) {
	
		count++;
		if(curr->next)
			curr = curr->next;
		else {
			printf("\nInvalid Position %d\n", pos);
			return head;
		}
	}
	Node* temp = curr->next;
	Node *node = createNewNode();
	node->data = data;
	node->next = temp;
	curr->next = node;
	return head;
}

Node* deleteFirst(Node* head) {

	if(!head) {
	
		printf("List already Empty...\n");
		return head;
	}
	head = head->next;
	//else head = NULL;
	return head;
}

void deleteEnd(Node* head) {

	if(!head || !head->next) {
	
		
		//return NULL;
	}else
	while(head->next->next) {
	
		head = head->next;
	}
	Node* temp = head->next;
	head->next = NULL;
	free(temp);
	//return head;
	
}

void display(Node* head) {

	while(head) {
	
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


int main() {

	Node* head = NULL;
	head = insertFirst(head, 1);
	head = insertFirst(head, 2);
	head = insertFirst(head, 3);
	head = insertFirst(head, 4);
	
	printf("Insert First :\n");
	display(head);
	
	head = insertEnd(head, 1);
	head = insertEnd(head, 2);
	head = insertEnd(head, 3);
	head = insertEnd(head, 4);
	
	printf("\nInsert Last :\n");
	display(head);
	
	head = insertAtIndex(head, 7, 5);
	head = insertAtIndex(head, 9, 1);
	head = insertAtIndex(head, 11, 2);
	head = insertAtIndex(head, 13, 0);
	
	printf("\nInsert At position \n");
	display(head);
	
	head = deleteFirst(head);
	head = deleteFirst(head);
	
	printf("\nDelete First :\n");
	display(head);
	
	deleteEnd(head);
	deleteEnd(head);
	deleteEnd(head);
	
	printf("\nDelete End :\n");
	display(head);	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int data;
	struct Node *next;
}Node;


Node * createNewNode() {

	Node *node = (Node*)malloc(sizeof(Node));
	return node;
}


Node* insertAtLast(Node *curr, int data) {

	if(curr == NULL) {

		curr = createNewNode();
		curr->data = data;
		curr->next = NULL;
		return curr;
	}
	
	curr->next = insertAtLast(curr->next, data);
	return curr;
}


Node* deleteAtEnd(Node *curr) {

	if(curr == NULL) {
	
		return NULL;
	} if(curr->next == NULL) {
	
		curr = NULL;
		free(curr);
		return NULL;
	} if( curr->next->next == NULL) {
	
		curr->next = NULL;
		free(curr->next);
		return curr;
	} else
	
	return deleteAtEnd(curr->next);
}


void printLinkedList(Node *h) {

	if(h == NULL) {
	
		printf("Empty List\n");
		return ;
	}
	Node *currNode = h;
	while(currNode) {
	
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	
	
	printf("\n");
}


void insertFirst(Node* head, int data) {

	Node *node = createNewNode();
	node->data = data;
	//Node * temp = head;
	
	node->next = head;
	head = node;
}


void insertLast(Node *head, int data) {

	Node * node = createNewNode();
	node->data = data;
	node->next = NULL;
	
	if(head == NULL) {
		head = node;
		return ;
	}
	while(head->next != NULL) {
	
		head = head->next;
	}
	head->next = node;
	
}


void insertAtPos(Node *head, int data, int pos) {

	if(pos < 0) {
	
		printf("Invalid Position");
		return;
	}

	if(pos == 0) {
	
		insertFirst(head, data);
		return ;
	}
	int count = 0;
	Node* node = createNewNode();
	node->data = data;
	while(count < pos) {
	
		if(head == NULL) {
		
			printf("Invalid Position");
			return;
		}
		count++;
		head = head->next;
	}
	
	Node* temp = head->next;
	head->next = node;
	node->next = temp;
	return;
}


void deleteFirst(Node *head) {

	if(head != NULL) {
	
		Node* temp = head;
		head = head->next;
		free(temp);
	}
	else {
	
		printf("List Already Empty !!\n");
	}
	
}



int main() {

	Node *head = NULL;
	/*head = insertAtLast(head, 1);
	head = insertAtLast(head, 2);
	head = insertAtLast(head, 3);
	head = insertAtLast(head, 4);
	
	printLinkedList(head);*/
	/*
	head = deleteAtEnd(head);
	head = deleteAtEnd(head);
	head = deleteAtEnd(head);
	head = deleteAtEnd(head);*/ 
	
	printLinkedList(head);
	
	insertFirst(head, 11);
	insertFirst(head, 12);
	insertFirst(head, 12);
	
	printLinkedList(head);
	
	return 0;
}



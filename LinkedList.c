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

void addAtBeginning(Node **h, int data) {

	Node *nn = createNewNode();
	nn->data = data;
	nn->next = *h;
	*h = nn;
}

void addAtEnd(Node **h, int data) {

	if(*h == NULL) {
		
		addAtBeginning(h, data);
	}else {
	
		Node *nn = createNewNode();
		nn->data = data;
		nn->next = NULL;
		Node *currNode = *h;
		while(currNode->next) {
	
			currNode = currNode->next;
		}
		currNode->next = nn;
	}

	
}

void addAtPosition(Node **h, int pos, int data) {

	if(pos < 0) {
		printf("Negative index is not possible\n");
		return;
	}
	if(pos == 0) {
	
		addAtBeginning(h, data);
		return ;
	}
	int count = 0;
	Node *currNode = *h;
	while(count < pos-1) {
	
		if(!currNode) {
			
			printf("Index out of bounds\n");
		return;
		}
		currNode = currNode->next;
		count++;
	}
	
	Node *nn = createNewNode();
	nn->data = data;
	nn->next = currNode->next;
	currNode->next = nn;
	
}

void printList(Node **h) {

	Node *currNode = *h;
	while(currNode) {
	
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	
	
	printf("\n");
}

void printReverse(Node *head) {

	if(head==NULL) {
	
		return;
	}
	printReverse(head->next);
	printf("%d ", head->data);
}

int isPalindrome(Node* curr, Node **h) {

	if(curr==NULL) {
		return 1;
	}
	int y = isPalindrome(curr->next, h);
	if(y == 1) {
		if((*h)->data == curr->data) {
			return 1;
		}
	}
	return 0;
}

Node* reverse(Node *first) {

	Node * second = NULL;
	if(first) {
		second = first->next;
	}
	if(second == NULL) {
	
		return first;
	}
	
	Node* curr = reverse(second);
	first->next = second->next;
	second->next = first;
	return curr;
}


int main() {

	Node *head = NULL;
	addAtBeginning(&head, 1);
	addAtBeginning(&head, 2);
	addAtBeginning(&head, 3);
	addAtBeginning(&head, 4);
	
	printList(&head);
	
	addAtEnd(&head, 9);
	addAtEnd(&head, 10);
	addAtEnd(&head, 11);
	addAtEnd(&head, 12);
	
	printList(&head);
	
	addAtPosition(&head, 2, 5);
	addAtPosition(&head, 0, 6);
	
	printList(&head);
	
	printf("\nPrinting Reverse :\n");
	printReverse(head);
	
	head = reverse(head);
	printf("\nPrinting After Reversing\n");
	printList(&head);
	
	return 0;
}

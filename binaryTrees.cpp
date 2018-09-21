#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
using namespace std;

typedef struct Node {

    struct Node *left;
    struct Node *right;
    int data;
}Node;
/*
Node *createNode(int data) {

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    return node;
}*/

Node * insertNode(Node *root, int data) {

    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    Queue<Node> q = new Queue<>();
    q.push(root);
    while(!q.empty()) {

        Node *s = q.front();
        q.pop();
        if(s->left) q.push(s->left);
        else {
            q->left = node;
            return root;
        }
    }
}

void inorder(Node *root) {

    Stack<Node> stack = new Stack();
    while(1) {

        while(root) {

            stack.push(root);
            root = root->left;
        }
        if(stack.empty()) return;

        Node *node = stack.peek();
        stack.pop();
        printf("%d\n", node->data);
        root = node->right;
    }
}

void preorder(Node *root) {

    Stack<Node> stack = new Stack();
    while(1) {

        while(root) {

            stack.push(root);
            printf("%d\n", root->data);
            root = root->left;
        }
        if(stack.empty()) return;

        root = stack.peek();
        stack.pop();
        
    }
}

void levelOrder(node *root) {

    Queue<Node> q = new Queue<>();
    q.push(root)
    while(!q.empty()) {

        Node *node = q.peek();
        printf("%d\n", node->data);
        q.pop();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        
    }
}

int main() {

    Node *root = new Node();
    root = NULL;
    root = insertNode(1);
    root = insertNode(2);
    root = insertNode(3);
    preorder(root);
}

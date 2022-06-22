//
//  prelab15.c
//  
//
//  Created by Trevor Hileman on 4/30/20.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int data;
    struct nodeStruct *left;
    struct nodeStruct *right;
}Node;

Node *createNode(int data);
Node *insertBST(Node *passedRoot, int data);
Node *searchBST(Node *passedRoot, int key);
void printTree(Node *passedRoot);
void freeTree(Node *passedRoot);

int main(void)
{
    Node *mainRoot = NULL;
    mainRoot = insertBST(mainRoot, 50);
    insertBST(mainRoot, 30);
    insertBST(mainRoot, 20);
    insertBST(mainRoot, 40);
    insertBST(mainRoot, 17);
    
    printTree(mainRoot);
    printf("DONE\n");
    freeTree(mainRoot);
    
    return 0;
}

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    
    if (newNode) { // null check
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    } else {
        printf("Error: Could not allocate memory.\n");
        return NULL; // return NULL if malloc fails
    }
}

/* This function gets passed a root(tree) and a data the user wants to insert in that tree and uses recursion to find the spot in that tree that the value needs to go. */
Node *insertBST(Node *passedRoot, int data)
{
    if (passedRoot) { // null check
      // use recursion to go down the tree until it finds the place to put the data
        if (data < passedRoot->data) {
          passedRoot->left = insertBST(passedRoot->left, data);
        }
        else if (data > passedRoot->data) {
          passedRoot->right = insertBST(passedRoot->right, data);
        }
    
        return passedRoot;
    } else {
        return createNode(data); // return a new node if passed node is null
    }
}
/* This function gets passed a root(tree) and a value they want to search for and finds that value using recursion. */
Node *searchBST(Node *passedRoot, int key)
{
    if (passedRoot == NULL || passedRoot->data == key) { // base case
       return passedRoot;
    }
    
    if (passedRoot->data < key) { // if passed key is greater than the current key
       return searchBST(passedRoot->right, key);
    }
  
    return searchBST(passedRoot->left, key); // if passed key is less than
}

/* This function gets passed a root(tree) and uses recursion to print the data in order. */
void printTree(Node *passedRoot)
{
    if (passedRoot) // null check
    {
        printTree(passedRoot->left);        //
        printf("%d-->", passedRoot->data);  // prints the tree from left->right
        printTree(passedRoot->right);       //
    } else {
    return; // exit the function if the passed root is null;
  }
}

/* This function gets passed a root(tree) and uses recursion to free it. */
void freeTree(Node *passedRoot)
{
    if (passedRoot) { // null check
    freeTree(passedRoot->left);
    freeTree(passedRoot->right);
    free(passedRoot);
    } else {
    return; // exit the function if the passed root is null;
  }
}
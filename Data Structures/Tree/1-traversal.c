/******************************************************************************
Tree Traversal Excercise.

Inorder Traversal :
1. Left Node is traversed
2. Print Node
3. Right Node is traversed

Preorder Traversal :
1. Print Node
2. Left Node is traversed
3. Right Node is traversed

Postorder Traversal :
1. Left Node is traversed
2. Right Node is traversed
3. Print Node
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> // package containing malloc()

//--------------------- Node Structure (Binary Tree) ---------------------------
struct node{    // node structure.
    int data;
    struct node* left;  // link to left nodes
    struct node* right; // link to right nodes
};
//------------------------------------------------------------------------------

//-------------------- Function to Allocate New Node ---------------------------
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));  // dynamic memory allocation
    node -> data = data;    // assign new data
    node -> left = NULL;    // left link is null initially
    node -> right = NULL;   // right link is null initially

    return node; // return newly created node with data value and empty links
}
//------------------------------------------------------------------------------

//------------------------- POST ORDER TRAVERSAL -------------------------------
void postorder(struct node* parent)   // left - right - root
{
    if(parent == NULL) return;    // start backtracking at the leaves.
    postorder(parent -> left); // travere left
    postorder(parent -> right); // travere right
    printf("%d ", parent -> data); // print node
}
//------------------------------------------------------------------------------

//-------------------------- INORDER TRAVERSAL ---------------------------------
void inorder(struct node* parent) // left - root - right
{
    if(parent == NULL) return;    // start backtracking at the leaves.
    inorder(parent -> left);  // traverse left
    printf("%d ", parent -> data); // print node
    inorder(parent -> right); // traverse right
}
//------------------------------------------------------------------------------

//-------------------------- PREORDER TRAVERSAL --------------------------------
void preorder(struct node* parent)    // root - left - right
{
    if(parent == NULL) return;    // start backtracking at the leaves.
    printf("%d ", parent -> data); // print node
    preorder(parent -> left); // travere left
    preorder(parent -> right); // travere right
}
//------------------------------------------------------------------------------
int main()
{
    //construction of tree
    struct node* root = newNode(1);
    root -> left      = newNode(2);
    root -> right     = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    // end of tree construction
    printf("\nThe preorder traversal : \n");
    preorder(root);

    printf("\nThe postorder traversal : \n");
    postorder(root);

    printf("\nThe inorder traversal : \n");
    inorder(root);

    return 0;
}

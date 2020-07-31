/*
  Rule of Binary Search Tree :
    Left node value should be in the range between :
        INT_MIN to Node.value
    Right node value should be in the range between :
        Node.value + 1 to INT_MAX
*/
#include <bits/stdc++.h>
using namespace std;

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
//---------------------------- Funtion to check BST ----------------------------
bool checkBST(node* root, int min, int max)
{
    if(root == NULL)    // Null tree is a binary tree.
        return true;

    if(root -> data <= min || root -> data > max) // Min limit is greater than Node.value OR MAX limit is smaller than Node.value.
        return false;     // return false.

    return checkBST(root -> left, min, root -> data) && checkBST(root -> right, root -> data, max); // even a single subtree returing false is false.
}
//------------------------------------------------------------------------------
int main()
{
    //construction of tree
    struct node* root = newNode(4);
    root -> left      = newNode(2);
    root -> right     = newNode(5);
    root -> left -> left = newNode(1);
    root -> left -> right = newNode(3);
    // end of tree construction
    if(checkBST(root, INT_MIN, INT_MAX))      // initially there is infinity upper and lower bound.
        cout << "BST";
    else
        cout << "No BST";
    return 0;
}

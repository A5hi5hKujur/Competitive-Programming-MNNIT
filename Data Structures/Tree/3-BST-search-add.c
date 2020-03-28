/******************************************************************************
BST : Binary Search Tree.

Binary Search Tree, is a node-based binary tree data structure with properties:
1. The LEFT subtree of a node contains only nodes with keys LESSER than the node’s key.
2. The RIGHT subtree of a node contains only nodes with keys GREATER than the node’s key.
3. The left and right subtree each must also be a binary search tree.
4. There must be no duplicate nodes.

===== Search node in a BST with matching key.(starting from the root) ==========

base cases :
1.  Check if the key matches with the Node -> data, if so then return the node. (Found Case)
1.2 Check if the node == NULL (Not Found Case)

2. If Node -> data > search key , recursively traverse the left branch of the node.
    else , recursively traverse the right branch of the node.
================================================================================

============ Add new Element in the BST.(starting from the root)================

1. New Nodes are only added to the leaves of a node,
    If you encounter a NULL link to a leaf in your path, you add the new node there.
    base case (Node == NULL) return addNode(key);

2. Path of the new node will be determined by the value of the new node(key),
    if(key > Node -> data) ; Recursively traverse the right path,
    if(key < Node -> data) ; Recursively traverse the left path.

3. Do this till u reach Node == NULL (leave node).
================================================================================

================== PROGRAM OBJECTIVE ===========================================

1. User inputs a 'key'
2. If the key matches with a node on the BST, it will say so
3. If the key does not match with any node, the key will be added in its appropriate
   place in the BST.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
//------------------------ Node Structure ------------------------------
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//----------------------------------------------------------------------
//--------------------- Function to Add Node ----------------------------
struct node* newNode(int value)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = value;
    Node -> left = NULL;
    Node -> right = NULL;

    return Node;
}
//----------------------------------------------------------------------
//------------------------ Searching algo ------------------------------
struct node* search(struct node* Node, int key) // returns either the node with the found key or node with error key (-1 : not found)
{
    struct node* null_node = newNode(-1);   // create null_node if not found.
    if(Node == NULL) return null_node;  // return null_node if not found.
    if(Node -> data == key) return Node;    // if node data matches the key, then return this node.
    if(key > Node -> data) return search(Node -> right, key); // search RIGHT, if key is LARGER
    if(key < Node -> data) return search(Node -> left, key); // search LEFT, if key is LESSER
}
//------------------ Add node to the BST -------------------------------
struct node* addBST(struct node* Node, int key) // returns newly created nodes
{
    if(Node == NULL) return newNode(key);  // return node if leaf is encountered
    if(key < Node -> data) Node -> left = addBST(Node -> left, key); // attach node to the left path
    if(key > Node -> data) Node -> right = addBST(Node -> right, key); // attach node to the right path
}
//-----------------------------------------------------------------------

//----------------------- Inorder Traversal ------------------------------
void InOrder(struct node* Node){    // Traversal algo to print values of the modified BST.
    if(Node == NULL) return;
    InOrder(Node -> left);
    printf("%d ",Node -> data);
    InOrder(Node -> right);
}
//-------------------------------------------------------------------------
int main()
{
    // BST Construction.
    struct node* root = newNode(8);
    root -> left = newNode(3);
    root -> right = newNode(10);
    root -> left -> left = newNode(1);
    root -> left -> right = newNode(6);
    root -> left -> right -> left = newNode(4);
    root -> left -> right -> right = newNode(7);
    root -> right -> right = newNode(14);
    root -> right -> right -> left = newNode(13);
    // BST Construction end.

    int key;
    scanf("%d",&key);
    struct node* temp = search(root,key);
    if(temp -> data == -1){
        printf("The item was not found, so we are adding it to the tree.\n");
        addBST(root,key);
    }else{
        printf("%d\n", temp -> data);
    }
    InOrder(root);
    return 0;
}

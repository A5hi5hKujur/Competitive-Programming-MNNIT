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

//------------------ Add node to the BST -------------------------------
struct node* addBST(struct node* Node, int key) // returns newly created nodes
{
    if(Node == NULL) return newNode(key);  // return node if leaf is encountered
    if(key < Node -> data) Node -> left = addBST(Node -> left, key); // attach node to the left path
    if(key > Node -> data) Node -> right = addBST(Node -> right, key); // attach node to the right path
    return node;
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
    // BST Construction O(nlogn).
    int n;
    printf("Enter the number of elements you want in your tree : ");
    scanf("%d",&n);
    struct node* root = NULL;
    for(int i=0; i<n; i++) // everything in the loop is executed O(n); times
    {
      int input;
      scanf("%d",&input);
      if(i == 0) root = newNode(input); // assign the first element as root.
      else addBST(root,input); // everything in this function is called O(log n) times
    }
    printf("Created Tree : \n");
    InOrder(root);
    return 0;
}

/******************************************************************************
Height of a Tree :

Here height of a tree is maximum number of nodes on root to leaf path.

base cases :
* Height of a tree with single node is considered as 1.
* Height of a tree with no node is 0.

maxDepth()
1. If tree is empty then return 0
2. Else
    (a) Get the max depth of left subtree recursively  i.e.,
         call maxDepth( tree->left-subtree)
    (a) Get the max depth of right subtree recursively  i.e.,
         call maxDepth( tree->right-subtree)
    (c) Get the max of max depths of left and right
         subtrees and add 1 to it for the current node.
        max_depth = max(max dept of left subtree, max depth of right subtree) + 1
    (d) Return max_depth
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//------------------------------ Node Structure --------------------------------
struct node {
    int data;
    struct node* left;
    struct node* right;
};
//------------------------------------------------------------------------------

//------------------------ Function to Create New Node -------------------------
struct node* newNode(int data)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = data;
    Node -> left = NULL;
    Node -> right = NULL;
    return Node;
}
//------------------------------------------------------------------------------

//----------------- Function to calculate Height of the tree -------------------
int maxDepth(struct node* parent)
{
   if(parent == NULL)  return 0; // height = 0
   int left_height = maxDepth(parent -> left);  // recursively find height of left path
   int right_height = maxDepth(parent -> right);// recursively find height of right path

   // Compare the height of left and right path
   if(left_height > right_height) return left_height + 1;
   else return right_height + 1;
   // return the path of the maximum height + 1 (+1 : the curent node will included in the height count)
}
int main()
{
    // construction of tree
    struct node* root = newNode(1);
    root -> left      = newNode(2);
    root -> right     = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    // end of construction

    printf("The height of this tree is : %d", maxDepth(root));
    return 0;
}

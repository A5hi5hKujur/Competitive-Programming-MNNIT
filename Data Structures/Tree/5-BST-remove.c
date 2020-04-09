/*
  --------------------------- TERMINOLOGIES : ----------------------------------
  Inorder Successor : The smallest valued element just AFTER the value of node to be deleted.
  Inorder Predicessor : The largest value element just BEFORE the value of the node to be deleted.
                          OR
  Inorder Successor : left most element on node -> right.
  Inorder Predicessor : right most element on node -> left.
  ------------------------------------------------------------------------------

  ------------- ALGORITHM TO DELETE NODE WITH MATHCHING KEY --------------------

  base cases : (physically only leaf nodes are deleted)
    if(Node -> left == NULL && Node -> right == NULL)
    {
      free(Node);
      return NULL;
    }

  1. Search the Node with matching key.
    - if(Node -> data < key) Delete(Node -> left, key)
    - if(Node -> data > key) Delete(Node -> right, key)
  2. Delete the Node with matching key.
    - if(Node -> data == key)
        - If (Node -> left != NULL && Node -> right == NULL)
          - connect the left child, free(Node), return Node -> left
        - If (Node -> right != NULL && Node -> left == NULL)
          - connect the right child, free(Node), return Node -> right
        - Else Find Successor / Predicessor for the the node to be deleted :
          - Value of the successor / predicessor node is to be replaced with the key node.
          - Remove the successor / predicessor node. (ALways leaf node)

* Finding inorder Predicessor : keep traversing the rightmost path till you reach the leaf node.
** Finding inoreder Successor : keep traversing the leftmost path till you reach the leaf node.

Note : In order to find which side has more no. of nodes we find the height.
--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
//------------------------ Node Structure --------------------------------------
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//------------------------------------------------------------------------------
//--------------------- Function to Add Node -----------------------------------
struct node* newNode(int value)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node -> data = value;
    Node -> left = NULL;
    Node -> right = NULL;

    return Node;
}
//------------------------------------------------------------------------------

//------------------ Add node to the BST ---------------------------------------
struct node* addBST(struct node* Node, int key) // returns newly created nodes
{
    if(Node == NULL) return newNode(key);  // return node if leaf is encountered
    if(key < Node -> data) Node -> left = addBST(Node -> left, key); // attach node to the left path
    if(key > Node -> data) Node -> right = addBST(Node -> right, key); // attach node to the right path
    return Node;
}
//------------------------------------------------------------------------------

//----------------------- Inorder Traversal ------------------------------------
void InOrder(struct node* Node){    // Traversal algo to print values of the modified BST.
    if(Node == NULL) return;
    InOrder(Node -> left);
    printf("%d ",Node -> data);
    InOrder(Node -> right);
}
//------------------------------------------------------------------------------
//------------------- Function to Find Height of the tree ----------------------
  int height(struct node* parent)
  {
    if(parent == NULL)  return 0; // height = 0
    int left_height = height(parent -> left);  // recursively find height of left path
    int right_height = height(parent -> right);// recursively find height of right path

    // Compare the height of left and right path
    if(left_height > right_height) return left_height + 1;
    else return right_height + 1;
  }
//------------------------------------------------------------------------------
//------------------- Function to Find Inorder Predicessor ---------------------
  struct node* InPre(struct node* Node)
  {
    while(Node -> right != NULL) // traverse till you reach the rightmost leaf.
    {
      Node = Node -> right;
    }
    return Node;
  }
//------------------------------------------------------------------------------
//------------------- Function to Find Inorder Successor -----------------------
  struct node* InSucc(struct node* Node)
  {
    while(Node -> left != NULL) // traverse till you reach the leftmost leaf.
    {
      Node = Node -> left;
    }
    return Node;
  }
//------------------------------------------------------------------------------
//------------------------- Function to Delete Node ----------------------------
  struct node* deleteNode(struct node* Node, int key)
  {
    //base case :
    if(Node == NULL) return NULL;

    // search :
    if(Node -> data > key) deleteNode(Node -> left, key);
    else if(Node -> data < key) deleteNode(Node -> right, key);

    // delete :
    else{   // You found the matching key.
      struct node *temp_node; // temporary node pointer.
      if(Node -> left == NULL) // Case 1 : When the left child is missing
      {
        temp_node = Node -> right; // The right child takes the key node's place.
        free(Node); // key node gets deleted.
        return temp_node; // address of the right child is recursively returned.
      }
      else if(Node -> right == NULL) // Case 2. : When the right child is missing
      {
        temp_node = Node -> left; // The left child takes the key node's place.
        free(Node); // key node gets deleted from the memory
        return temp_node; // address of the left child is recursively returned.
      }
      // Case 3 : If both the children exist.
        // Either find the inorder successor or predicessor (I chose successor)
      temp_node = InSucc(Node -> right); // This inorder successor now is to take the key node's place.
		  Node -> data = Node -> data; // Data of the successor gets copied over to key node.
		  Node -> right = deleteNode(Node -> right, temp_node -> data); // The successor is removed from its place.
    }
    return Node; // recursively return either left most child or right most child.
  }
//------------------------------------------------------------------------------
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

    int key;
    printf("Enter the number you want to delete : ");
    scanf("%d",&key);
    deleteNode(root, key);
    printf("Tree after deletion : \n");
    InOrder(root);
    return 0;
}

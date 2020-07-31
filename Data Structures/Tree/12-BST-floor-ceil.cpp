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
    node* node = (struct node*)malloc(sizeof(struct node));  // dynamic memory allocation
    node -> data = data;    // assign new data
    node -> left = NULL;    // left link is null initially
    node -> right = NULL;   // right link is null initially

    return node; // return newly created node with data value and empty links
}
//------------------------------------------------------------------------------

//----------------------- Find Floor of the node -------------------------------
int floorBST(node* root, int x) // returns x node or the value smaller to x
{
    if(root == NULL)    // if you reach null return deadend, in this case +ve infinity
        return INT_MAX;
    if(root -> data == x)  // if x is found return x
        return x;
    if(root -> data > x)   // if root data is greater than x; go for smaller value in the left node (but root -> data could be a possible floor value).
        return floorBST(root -> left, x);
    int right = floorBST(root -> right, x); // store the value of right node
    return (right < x) ? right : root -> data; // return the minimum of either the root data or the right data.
}
//------------------------------------------------------------------------------

//------------------------ Find Ceil of the node -------------------------------
int ceilBST(node* root, int x)
{
    if(root == NULL)  // if you reach null return deadend, in this case -ve infinity
        return INT_MIN;
    if(root -> data == x) // if x is found return x
        return x;
    if(root -> data < x)  // if root data is smaller than x; go for larger value in the right node (but root -> data could be a possible ceil value).
        return ceilBST(root -> right, x);
    int left = ceilBST(root -> left, x);
    return (left > x) ? left : root -> data; // return the max of either the root data or the left data.
}
//------------------------------------------------------------------------------
int main()
{
    //construction of tree
    struct node* root = newNode(10);
    root -> left      = newNode(5);
    root -> right     = newNode(15);
    root -> right -> left = newNode(12);
    root -> right -> right = newNode(30);
    root -> right -> left -> left = newNode(11);
    root -> right -> left -> right = newNode(13);
    /*
                    10
                5       15
                    12      30
                11      13
    */


    cout << floorBST(root, 29);
    cout << "\n";
    cout << ceilBST(root, 4);
    return 0;
}

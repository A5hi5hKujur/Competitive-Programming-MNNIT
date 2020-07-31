#include <bits/stdc++.h>
using namespace std;

//--------------------- Node Structure (Binary Tree) ---------------------------
struct node{    // node structure.
    char data;
    struct node* left;  // link to left nodes
    struct node* right; // link to right nodes
};
//------------------------------------------------------------------------------

//-------------------- Function to Allocate New Node ---------------------------
struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));  // dynamic memory allocation
    node -> data = data;    // assign new data
    node -> left = NULL;    // left link is null initially
    node -> right = NULL;   // right link is null initially

    return node; // return newly created node with data value and empty links
}
//------------------------- Tree Traversal methods------------------------------
 void preorder(node* root)
 {
     if(root == NULL)
        return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
 }

  void inorder(node* root)
 {
     if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
 }

 void postorder(node* root)
 {
     if(root == NULL)
        return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
 }
//-------------------------- Preorder + Inorder --------------------------------

node* buildTree(string Inorder, string Preorder, int in_start, int in_end)
{
    static int pre_root_index = 0;          // preorder root starts from Preorder[0]
    char pre_root;
    if(pre_root_index < Preorder.length())  // out of bound check
        pre_root = Preorder.at(pre_root_index); // root of the subtree found from preorder array

    if(in_start > in_end)           // when inorder left/right range gets exhausted.
        return NULL;                // there is no node

    node* root = newNode(Preorder.at(pre_root_index++));  // assign new root as preorder root and increment pre_root_index, since it would have the next root index info.
    if(in_start == in_end)         // if there is only one node in the range
        return root;

    int in_root = -1;
    for(int i=in_start; i<= in_end; i++)    // find location of inorder root based on root value from preorder array
    {
        if(Inorder.at(i) == pre_root)
            in_root = i;
    }

    // divide the inorder array into left and right ranges
    root -> left = buildTree(Inorder, Preorder, in_start, in_root - 1);  // left range : inorder start to inorder root - 1
    root -> right = buildTree(Inorder, Preorder, in_root + 1, in_end);   // right range : inorder root + 1 to inorder end
    return root;
}
node* PreInTree(string Inorder, string Preorder)
{
    int n = Inorder.length();
    return buildTree(Inorder, Preorder, 0, n-1); // Tree Builder Function. starts from index 0 to n-1
}
//------------------------------------------------------------------------------

//------------------------- Postorder + Inorder ---------------------------------

node* buildTreePost(string Inorder, string Postorder, int in_start, int in_end)
{
    static int post_root_index = Postorder.length() - 1;  // The root starts from n-1th position in the postorder array
    char post_root;
    if(post_root_index >= 0)    // out of bound check
        post_root = Postorder.at(post_root_index);
    if(in_start > in_end)
        return NULL;
    node* root = newNode(Postorder.at(post_root_index--));  // post root index is decremented after every new root node iteration

    if(in_start == in_end)
        return root;

    int in_root = -1;
    for(int i=in_start; i<= in_end; i++)
    {
        if(Inorder.at(i) == post_root)
            in_root = i;
    }
    // Same partition except this time the partition starts from right.
    root -> right = buildTreePost(Inorder, Postorder, in_root + 1, in_end);
    root -> left = buildTreePost(Inorder, Postorder, in_start, in_root - 1);
    return root;

}
node* PostInTree(string Inorder, string Postorder)
{
    int n = Inorder.length();
    return buildTreePost(Inorder, Postorder, 0, n-1);
}
//------------------------------------------------------------------------------
int main()
{
    string Inorder;
    Inorder = "DBEAFC";
    string Preorder;
    Preorder = "ABDECF";

    string Inorder2;
    Inorder2 = "48251637";
    string Postorder;
    Postorder = "84526731";

    node* root = PreInTree(Inorder, Preorder);
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";

    node* root2 = PostInTree(Inorder2, Postorder);
    postorder(root2);
    cout << "\n";
    inorder(root2);
    return 0;
}

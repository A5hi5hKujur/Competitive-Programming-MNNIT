#include<bits/stdc++.h>
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
//------------------------------------------------------------------------------


//-------------------------- Preorder Traversal --------------------------------
void preorder(node* root)
{
    stack<node*> st;    // stack to store the visited nodes
    st.push(root);
    while(!st.empty())  // loop while the stack runs out.
    {
        node* parent = st.top();
        st.pop();
        cout << parent -> data << " ";
        if(parent -> right)                 // pushing right into the stack before left so that left can be processed first in a stack.
            st.push(parent -> right);
        if(parent -> left)
            st.push(parent -> left);
    }
}
//------------------------------------------------------------------------------

//--------------------------- Postorder Traversal ------------------------------
void postorder(node* root)
{
    stack<node*> st; // stack that stores the visited nodes
    stack<int> ans;   // stack that stores the order of postorder
    st.push(root);
    while(!st.empty())
    {
        node* curr = st.top();
        st.pop();
        ans.push(curr -> data);

        if(curr -> left)      // left is pushed first so that right node can be visited first.
            st.push(curr -> left);
        if(curr -> right)
            st.push(curr -> right);
    }
    while(!ans.empty())   // postorder is pretty much the opposite of preorder.
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}
//------------------------------------------------------------------------------

//------------------------------ Inorder Traversal ------------------------------
void inorder(node* root)
{
    stack<node*> st;
    node* curr = root;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)     // process left node until there exists a left node.
        {
            st.push(curr);
            curr = curr -> left;
        }
        curr = st.top();  // curr = leftmost node
        st.pop();
        cout << curr -> data << " ";
        curr = curr -> right; // move to the right of current
    }
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

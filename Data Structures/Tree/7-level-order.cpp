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

//------------------------- Level order Traversal ------------------------------
void levelorder(node* root)
{
    queue<node*> que;                 // to treverse 1 level at a time. (FIFO)
    que.push(root);                   // level 1 consists of the root
    while(!que.empty())               // while there are nodes to process
    {
        node* curr = que.front();     // node next in queue.
        cout << curr -> data << " ";
        que.pop();
        if(curr -> left)              // if there exists a left node
            que.push(curr -> left);   // push the left node to the queue
        if(curr -> right)             // if there exists a right node
            que.push(curr -> right);  // push the right node to the queue
    }
}
//------------------------------------------------------------------------------

//----------------------- Spiral order Traversal (right) -------------------------
void levelSpiral(node* root)
{
    stack<node*> s1, s2;              // s1 traverses right to left ; s2 traverses left to right
    s2.push(root);
    while(!s1.empty() || !s2.empty()) // while either of stacks is not empty
    {
        while(!s1.empty())            // if s1 is filled its time to traverse right to left
        {
            node* curr = s1.top();    // same step as level order, but you push to the other stack.
            s1.pop();
            cout << curr -> data << " ";
            if(curr -> right)           // you first insert right node
                s2.push(curr -> right);
            if(curr -> left)            // then left.
                s2.push(curr -> left);
        }
        while(!s2.empty())              // if s2 is filled its time to traverse left to right
        {
            node* curr = s2.top();
            s2.pop();
            cout << curr -> data << " ";
            if(curr -> left)            // you first insert left node
                s1.push(curr -> left);
            if(curr -> right)           // then right.
                s1.push(curr -> right);
        }
    }
}
//------------------------------------------------------------------------------

//----------------------- Spiral order Traversal (left) -------------------------
void levelSpiral(node* root)    // same process just swap the 2 while loops.
{
    stack<node*> s1, s2;
    s2.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node* curr = s1.top();
            s1.pop();
            cout << curr -> data << " ";
            if(curr -> left)
                s2.push(curr -> left);
            if(curr -> right)
                s2.push(curr -> right);
        }
        while(!s2.empty())
        {
            node* curr = s2.top();
            s2.pop();
            cout << curr -> data << " ";
            if(curr -> right)
                s1.push(curr -> right);
            if(curr -> left)
                s1.push(curr -> left);
        }
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

    printf("\nThe level order traversal : \n");
    levelorder(root);
    return 0;
}

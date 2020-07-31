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
/*
  Vertical traversal rule :
  - Every vertix is assigned a vertical id.
  - Vertial id of the root = 0
  - Vertical id of the left node = root - 1
  - Vertical id of the right node = root + 1
*/
void vertical(node* root)
{
    map<int, vector<int>> mp; // map key : vertical id  ; map value : list of vertices in that id.
    queue<pair<node*, int>> que; // queue of pairs containing <node, vertical id>
    que.push({root, 0});  // starts with root = 0
    while(!que.empty())   // while there are vertices to process
    {
        auto curr = que.front();
        mp[curr.second].push_back(curr.first -> data);  // add node data to the corresponding vertical id
        que.pop();
        if(curr.first -> left) //
            que.push({curr.first -> left, curr.second - 1}); // Vertical id of the left node = root_vertical_id - 1
        if(curr.first -> right)
            que.push({curr.first -> right, curr.second + 1}); // Vertical id of the right node = root_vertial_id + 1
    }
    for(auto itr = mp.begin(); itr != mp.end(); itr++) // view data in corresponding vertical id
    {
        cout << itr -> first << ": ";
        for(int i : itr -> second)
            cout << i << " ";
        cout << "\n";
    }
}
int main()
{
    //construction of tree
    struct node* root = newNode(1);
    root -> left      = newNode(2);
    root -> right     = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    int height = 0;

    vertical(root);
    return 0;
}

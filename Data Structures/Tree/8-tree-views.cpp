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

//--------------------------------- LEFT/RIHT View -----------------------------
void leftRightViews(node* root)   // level order traversal
{
    queue<pair<node*, int>> que;  // pair contains <node, height>
    que.push({root, 1});          // root height starts from 1 (code needs to be modified if started from 0)
    int max_height = 0;
    while(!que.empty())
    {
        auto curr = que.front();
        que.pop();
        if(curr.second > max_height)   // The first node encountered in the next level
        {
            max_height = curr.second;   // elevate the level
            cout << curr.first -> data << " ";  // display the first encounter.
        }

        // Insert nodes in the queue from left to right to see the left view.
        if(curr.first -> left)
            que.push({curr.first -> left, curr.second + 1});
        if(curr.first -> right)
            que.push({curr.first -> right, curr.second + 1});

      // Switch the orders from right to left to print Right view.
    }
}
//------------------------------------------------------------------------------

//------------------------------- Top View -------------------------------------
/*
  See "Vertial Traversal" before this.
  Combination of vertical traversal and level order traversal
*/
void TopView(node* root)
{
    unordered_map<int, vector<int>> mp; // map<vertical id : list of vertices in that vertical id>
    queue<pair<node*, int>> que;  // vertices with their vertial id
    que.push({root, 0});
    while(!que.empty())
    {
        auto curr = que.front();
        if(mp.count(curr.second) == 0) // only store the first vertix of a vertical_id
            mp[curr.second].push_back(curr.first -> data);
        que.pop();                // normal vertical traversal after this.
        if(curr.first -> left)
            que.push({curr.first -> left, curr.second - 1});
        if(curr.first -> right)
            que.push({curr.first -> right, curr.second + 1});
    }
    for(auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr -> first << ": ";
        for(int i : itr -> second)
            cout << i << " ";
        cout << "\n";
    }
}
//------------------------------------------------------------------------------

//------------------------------- Bottom View ----------------------------------
void BottomView(node* root)   // vertical traversal but now print the last element of the corresponding vertical id.
{
    map<int, vector<int>> mp;
    queue<pair<node*, int>> que;
    que.push({root, 0});
    while(!que.empty())
    {
        auto curr = que.front();
        mp[curr.second].push_back(curr.first -> data);
        que.pop();
        if(curr.first -> left)
            que.push({curr.first -> left, curr.second - 1});
        if(curr.first -> right)
            que.push({curr.first -> right, curr.second + 1});
    }
    for(auto itr = mp.begin(); itr != mp.end(); itr++)
        cout <<  itr -> second[itr -> second.size() - 1] << " ";    // last elements of the list.
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
    int height = 0;

    cout << "\nLeft View : \n";
    leftRightViews(root);

    return 0;
}

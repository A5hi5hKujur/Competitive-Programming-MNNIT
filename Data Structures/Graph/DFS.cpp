/*

  Depth First Search : A graph traversal Algorithm which follows a 2 step process
                       of scanning all the adjecent (Children) vertices.

---------------------------------------- Data Structure Prerequisits ------------------------------------------------------

  1. Adjecency Matrix : A 2d matrix, of (v x v, where v : no. of vertices) size
                        which plots which 2 vertices are connected.
  Eg : Assuming a graph containing 4 vertices, the adj. matrix is :

   _ 1  2  3  4 _       Where : * 1 represents an undirected connection between 2 vertices.
1 |  0  1  1    |               * Vertix associated row represents out-degree connections. (directed graph)
2 |  1 . . . .  |               * Vertix associated coloumn represent in-degree connections. (directed graph)
3 |  1 . . . .  |
4 |_ 0 . . . . _|

2. Visited Array : An array that keeps track of all the vertices visited / not visited. For a graph of n vertices,
                   the length of the array is (n+1) 0-based index(we are gonna start from index 1, to simplify operations).

  Eg : For the above graph, visited = [0,  0, 0, 0, 0];   // initially their values are zero, i.e, not visited.
                                      0    1  2  3  4

3. Stack : To store the vertix to be explored as soon as an unvisited, adjacent vertix is encountered.
-------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------- ALGORITHM ---------------------------------------------------

    As defined the algorithm is fundamentally divided into 2 steps :
    1. Visit            2. Explore

    VISIT : where vertix 'i' is visited for the first time.
    Step 1 : input a start vertix (i)
    Step 2 : Store the index in the explore stack : stack.push(i);

    EXPLORE : where adjecent vertices connected to vertix 'i' are explored.
    Step 3 : while(there are elements in the stack) continue visit process.
    Step 4 : Take the topmost vertix(which represents the deepest vertix) at that time,
             and print it if not visited, after which mark it visited.
    Step 5 : When encounterd an adjecent vertix which is not visited yet, push it in the explore stack and repeat.

    Time Complexity : O(V + E)
----------------------------------------------------------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
//----------------------- SETTING UP THE DATA-STRUCTURES ------------------------
int n = 7;
int Adj[][7] = {{0,0,0,0,0,0,0}, // Adjecency Matrix of the graph (starting from 1).
               {0,0,1,1,0,0,0}, // 6x6 data (ignoring index 0s)
               {0,1,0,0,1,0,0},
               {0,1,0,0,1,0,0},
               {0,0,1,1,0,1,1},
               {0,0,0,0,1,0,0},
               {0,0,0,0,1,0,0}};
stack<int> explore;
int visited[7] = {0}; // Array that tracks visited vertices.
//------------------------------------------------------------------------------

//--------------------------- DFS Funtions -------------------------------------
void DFS(int i) // enter starting point.
{
    explore.push(i); // push the starting point into the stack.
    while(!explore.empty()) // keep exploring until there are vertices to explore.
    {
        int vertix = explore.top(); // start exploring with the topmost vertix.
        explore.pop();
        if(!visited[vertix]) // if the vertix is unvisited.
        {
            cout << vertix << " "; // print it out.
            visited[vertix] = 1; // and mark it "visited".
        }
        for(int j=1; j<=n; j++)  // explore all elements on the entire row
        {
            if(Adj[vertix][j] == 1 && visited[j] == 0)
            {
                explore.push(j); // keep pushing the non-visited adjacent verties on the stack.
            }
        }
    }
}
//------------------------------------------------------------------------------

//--------------------------------- DFS Recursion ------------------------------
void DFS2(int i)
{
  visited[i] = 1;
  cout << i << " ";
  for(int j=1; j<=n; j++)
  {
    if(Adj[i][j] == 1 && visited[j] == 0)
    DFS2(j);
  }
}
//------------------------------------------------------------------------------

int main()
{
  DFS(4); // starting point as parameter.
  return 0;
}
